// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <tuple>
#include <vector>
#include "ITransfersSynchronizer.h"

namespace CryptoNote {

class TransfersObserver : public ITransfersObserver {
public:
  virtual void onError(ITransfersSubscription* object, uint32_t height, std::error_code ec) override {
    errors.emplace_back(height, ec);
  }

  virtual void onTransactionUpdated(ITransfersSubscription* object, const Hash& transactionHash) override {
    updated.push_back(transactionHash);
  }

  virtual void onTransactionDeleted(ITransfersSubscription* object, const Hash& transactionHash) override {
    deleted.push_back(transactionHash);
  }

  std::vector<std::tuple<uint64_t, std::error_code>> errors;
  std::vector<Hash> updated;
  std::vector<Hash> deleted;
};


}
