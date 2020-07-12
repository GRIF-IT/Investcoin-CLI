// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <GreenWallet/Types.h>

void syncWallet(CryptoNote::INode &node,
                std::shared_ptr<WalletInfo> walletInfo);

void checkForNewTransactions(std::shared_ptr<WalletInfo> walletInfo);
