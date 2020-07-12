// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

namespace CryptoNote {
  class IBlockchainStorageObserver {
  public:
    virtual ~IBlockchainStorageObserver() {
    }

    virtual void blockchainUpdated() = 0;
  };
}
