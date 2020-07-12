// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <NodeRpcProxy/NodeRpcProxy.h>
#include <GreenWallet/Types.h>

int main(int argc, char **argv);

void run(CryptoNote::WalletGreen &wallet, CryptoNote::INode &node,
         Config &config);
