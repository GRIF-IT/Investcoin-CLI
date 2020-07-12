// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

namespace CryptoNote {
class ITxPoolObserver {
public:
  virtual ~ITxPoolObserver() {
  }

  virtual void txDeletedFromPool() = 0;
};
}
