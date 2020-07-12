// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <ostream>
#include "IOutputStream.h"

namespace Common {

class StdOutputStream : public IOutputStream {
public:
  StdOutputStream(std::ostream& out);
  StdOutputStream& operator=(const StdOutputStream&) = delete;
  size_t writeSome(const void* data, size_t size) override;

private:
  std::ostream& out;
};

}
