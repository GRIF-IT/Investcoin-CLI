// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <string>
#include "IOutputStream.h"

namespace Common {

class StringOutputStream : public IOutputStream {
public:
  StringOutputStream(std::string& out);
  size_t writeSome(const void* data, size_t size) override;

private:
  std::string& out;
};

}
