// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once 
#include <chrono>
#include <System/ContextGroup.h>
#include <System/Timer.h>

namespace System {

class ContextGroupTimeout {
public: 
  ContextGroupTimeout(Dispatcher&, ContextGroup&, std::chrono::nanoseconds);

private: 
  Timer timeoutTimer;
  ContextGroup workingContextGroup;
};

}
