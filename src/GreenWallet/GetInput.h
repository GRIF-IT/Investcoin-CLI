// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <string>

#include <vector>

#include <GreenWallet/Commands.h>
#include <GreenWallet/Types.h>

std::string yellowANSIMsg(std::string msg);

std::string getPrompt(std::shared_ptr<WalletInfo> walletInfo);

template<typename T>
std::string getInputAndWorkInBackground(const std::vector<T>
                                        &availableCommands,
                                        std::string prompt,
                                        bool backgroundRefresh,
                                        std::shared_ptr<WalletInfo>
                                        walletInfo);

template<typename T>
std::string getInput(const std::vector<T> &availableCommands,
                     std::string prompt);
