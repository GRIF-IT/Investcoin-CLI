// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

namespace CryptoNote {

class ICoreObserver {
public:
  virtual ~ICoreObserver() {};
  virtual void blockchainUpdated() {};
  virtual void poolUpdated() {};
};

}
