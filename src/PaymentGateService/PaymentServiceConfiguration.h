// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <string>
#include <stdexcept>
#include <cstdint>

#include <boost/program_options.hpp>

#include "Common/PasswordContainer.h"

namespace {
	Tools::PasswordContainer pwd_container;
}

namespace PaymentService {

class ConfigurationError : public std::runtime_error {
public:
  ConfigurationError(const char* desc) : std::runtime_error(desc) {}
};

struct Configuration {
  Configuration();

  void init(const boost::program_options::variables_map& options);
  static void initOptions(boost::program_options::options_description& desc);

  std::string bindAddress;
  uint16_t bindPort;
  std::string m_rpcUser;
  std::string m_rpcPassword;

  std::string containerFile;
  std::string containerPassword;
  std::string logFile;
  std::string serverRoot;
  std::string secretViewKey;
  std::string secretSpendKey;
  std::string mnemonicSeed;

  bool generateNewContainer;
  bool generateDeterministic;
  bool daemonize;
  bool registerService;
  bool unregisterService;
  bool testnet;
  bool printAddresses;

  size_t logLevel;
};

} //namespace PaymentService
