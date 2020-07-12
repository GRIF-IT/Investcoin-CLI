// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once 

#include <string>
#include "Rpc/CoreRpcServerCommandsDefinitions.h"

namespace Common {
  namespace Format {
    std::string get_mining_speed(const uint64_t hashrate);

    std::string get_sync_percentage(
      uint64_t height,
      const uint64_t target_height);

    std::string prettyPrintBytes(const uint64_t numBytes);

    std::string unixTimeToDate(const uint64_t timestamp);

    std::string formatAmount(uint64_t amount);

    std::string formatAmount(int64_t amount);

    bool parseAmount(const std::string& str, uint64_t& amount);
  }
}
