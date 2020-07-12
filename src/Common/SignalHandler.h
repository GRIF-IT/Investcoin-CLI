// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once 

#include <functional>

namespace Tools {
  
  class SignalHandler
  {
  public:
    static bool install(std::function<void(void)> t);
  };
}
