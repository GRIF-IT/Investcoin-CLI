#!/bin/sh

# Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

DATA_DIR="/var/investcoin"
LOG_DIR="/var/log/investcoin"
RUN_DIR="/var/run/investcoin"

INVCS="/usr/sbin/simplewallet"

INVCS_NODE_HOST="127.0.0.1"
INVCS_NODE_PORT="5334"
INVCS_WALLET="Wallet.dat"
INVCS_PASS="pass"
INVCS_LOG_LEVEL="3"
INVCS_RPC_IP="127.0.0.1"
INVCS_RPC_PORT="15000"

SIGTERM_TIMEOUT=30
SIGKILL_TIMEOUT=20

INVCS_WALLET=$DATA_DIR/$INVCS_WALLET


## Base check

# Check all work directories
if [ -d $DATA_DIR ]; then
  if [ ! -w $DATA_DIR ]; then
    echo "Error: DATA dir not writable!"
    exit 1
  fi
else
  echo "Error: DATA dir not found!"
  exit 1
fi

if [ -d $LOG_DIR ]; then
  if [ ! -w $LOG_DIR ]; then
    echo "Error: LOG dir not writable!"
    exit 1
  fi
else
  echo "Error: LOG dir not found!"
  exit 1
fi

if [ -d $RUN_DIR ]; then
  if [ ! -w $RUN_DIR ]; then
    echo "Error: RUN dir not writable!"
    exit 1
  fi
else
  echo "Error: RUN dir not found!"
  exit 1
fi

# Check all bin files
if [ ! -f $INVCS ]; then
  echo "Error: SIMPLEWALLET bin file not found!"
  exit 1
fi

if [ ! -f $INVCS_WALLET.wallet ]; then
  echo "Error: wallet bin file not found!"
  exit 1
fi


# Function logger
logger(){
  if [ ! -f $LOG_DIR/invcs_control.log ]; then
    touch $LOG_DIR/invcs_control.log
  fi
  mess=[$(date '+%Y-%m-%d %H:%M:%S')]" "$1
  echo $mess >> $LOG_DIR/invcs_control.log
  echo $mess
}

# Funstion locker
locker(){
  if [ "$1" = "check" ]; then
    if [ -f $RUN_DIR/invcs_control.lock ]; then
      logger "LOCKER: previous task is not completed; exiting..."
      exit 0
    fi
  fi
  if [ "$1" = "init" ]; then
    touch $RUN_DIR/invcs_control.lock
  fi
    if [ "$1" = "end" ]; then
    rm -f $RUN_DIR/invcs_control.lock
  fi
}

# Function init service
service_init(){
  $INVCS --wallet-file $INVCS_WALLET \
        --password $INVCS_PASS \
        --daemon-host $INVCS_NODE_HOST \
        --daemon-port $INVCS_NODE_PORT \
        --rpc-bind-ip $INVCS_RPC_IP \
        --rpc-bind-port $INVCS_RPC_PORT \
        --log-file $LOG_DIR/invcs.log \
        --log-level $INVCS_LOG_LEVEL > /dev/null & echo $! > $RUN_DIR/INVCS.pid
}

# Function start service
service_start(){
  if [ ! -f $RUN_DIR/INVCS.pid ]; then
    logger "START: trying to start service..."
    service_init
    sleep 5
    if [ -f $RUN_DIR/INVCS.pid ]; then
      pid=$(sed 's/[^0-9]*//g' $RUN_DIR/INVCS.pid)
      if [ -f /proc/$pid/stat ]; then
        logger "START: success!"
      fi
    fi
  else
    pid=$(sed 's/[^0-9]*//g' $RUN_DIR/INVCS.pid)
    if [ -f /proc/$pid/stat ]; then
      logger "START: process is already running"
    else
      logger "START: abnormal termination detected; starting..."
      rm -f $RUN_DIR/INVCS.pid
      service_init
      sleep 5
      if [ -f $RUN_DIR/INVCS.pid ]; then
        pid=$(sed 's/[^0-9]*//g' $RUN_DIR/INVCS.pid)
        if [ -f /proc/$pid/stat ]; then
          logger "START: success!"
        fi
      fi
    fi
  fi
}

# Function stop service
service_stop(){
  if [ -f $RUN_DIR/INVCS.pid ]; then
    logger "STOP: attempting to stop the service..."
    pid=$(sed 's/[^0-9]*//g' $RUN_DIR/INVCS.pid)
    if [ -f /proc/$pid/stat ]; then
      kill $pid
      sleep 5
      for i in $(seq 1 $SIGTERM_TIMEOUT); do
        if [ ! -f /proc/$pid/stat ]; then
          rm -f $RUN_DIR/INVCS.pid
          logger "STOP: success!"
          break
        fi
        sleep 1
      done
      if [ -f $RUN_DIR/INVCS.pid ]; then
        logger "STOP: attempt failed, trying again..."
        kill -9 $pid
        sleep 5
        for i in $(seq 1 $SIGKILL_TIMEOUT); do
          if [ ! -f /proc/$pid/stat ]; then
            rm -f $RUN_DIR/INVCS.pid
            logger "STOP: service has been killed (SIGKILL) due to ERROR!"
            break
          fi
          sleep 1
        done
      fi
    else
      logger "STOP: PID file found, but service not detected; possible error..."
      rm -f $RUN_DIR/INVCS.pid
    fi
  else
    logger "STOP: no service found!"
  fi
}


do_start(){
  logger "DO START: procedure initializing..."
  service_start
  logger "DO START: ok"
}

do_stop(){
  logger "DO STOP: procedure initializing..."
  service_stop
  logger "DO STOP: ok"
}

do_restart(){
  logger "DO RESTART: procedure initializing..."
  service_stop
  service_start
  logger "DO RESTART: ok"
}


# Command selector
locker "check"
locker "init"

case "$1" in
  "--start")
  do_start
  ;;
  "--stop")
  do_stop
  ;;
  "--restart")
  do_restart
  ;;
  *)
  logger "SELECTOR: unknown command"
  ;;
esac

locker "end"
