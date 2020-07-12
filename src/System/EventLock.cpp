// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#include "EventLock.h"
#include <System/Event.h>

namespace System {

EventLock::EventLock(Event& event) : event(event) {
  while (!event.get()) {
    event.wait();
  }

  event.clear();
}

EventLock::~EventLock() {
  event.set();
}

}
