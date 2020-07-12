// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <boost/program_options.hpp>

namespace CryptoNote {

class RpcServerConfig {
public:

  RpcServerConfig();

  static void initOptions(boost::program_options::options_description& desc);
  void init(const boost::program_options::variables_map& options);

  std::string getBindAddress() const;

  std::string bindIp;
  uint16_t    bindPort;
  std::string enableCors;
  std::string contactInfo;
  std::string nodeFeeAddress;
  std::string nodeFeeAmountStr;
  std::string nodeFeeViewKey;
  bool        restrictedRpc;
};

}
