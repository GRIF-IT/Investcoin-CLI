// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#include "ContextGroupTimeout.h"
#include <System/InterruptedException.h>

using namespace System;

ContextGroupTimeout::ContextGroupTimeout(Dispatcher& dispatcher, ContextGroup& contextGroup, std::chrono::nanoseconds timeout) :
  workingContextGroup(dispatcher),
  timeoutTimer(dispatcher) {
  workingContextGroup.spawn([&, timeout] {
    try {
      timeoutTimer.sleep(timeout);
      contextGroup.interrupt();
    } catch (InterruptedException&) {
    }
  });
}
