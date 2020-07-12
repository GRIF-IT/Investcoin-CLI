// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <exception>

namespace System {

class InterruptedException : public std::exception {
  public:
    virtual const char* what() const throw() override {
      return "interrupted";
    }
};

}
