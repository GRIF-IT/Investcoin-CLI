// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include "CryptoNoteProtocol/CryptoNoteProtocolDefinitions.h"

#include <unordered_set>

namespace CryptoNote
{
    struct PendingLiteBlock
    {
        NOTIFY_NEW_LITE_BLOCK_request request;
        std::unordered_set<Crypto::Hash> missed_transactions;
    };
} // namespace CryptoNote
