// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <sstream>

namespace CryptoNote {

class IStreamSerializable {
public:
  virtual void save(std::ostream& os) = 0;
  virtual void load(std::istream& in) = 0;
};

}
