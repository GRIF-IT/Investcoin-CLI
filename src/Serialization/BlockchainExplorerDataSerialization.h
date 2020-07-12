// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include "BlockchainExplorerData.h"

#include "Serialization/ISerializer.h"

namespace CryptoNote {

void serialize(transactionOutputDetails2& output, ISerializer& serializer);
void serialize(TransactionOutputReferenceDetails& outputReference, ISerializer& serializer);

void serialize(BaseInputDetails& inputBase, ISerializer& serializer);
void serialize(KeyInputDetails& inputToKey, ISerializer& serializer);
void serialize(MultisignatureInputDetails& inputMultisig, ISerializer& serializer);
void serialize(transactionInputDetails2& input, ISerializer& serializer);

void serialize(TransactionExtraDetails& extra, ISerializer& serializer);
void serialize(TransactionExtraDetails2& extra, ISerializer& serializer);
void serialize(TransactionDetails& transaction, ISerializer& serializer);

void serialize(BlockDetails& block, ISerializer& serializer);

} //namespace CryptoNote
