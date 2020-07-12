// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include "CryptoNoteCore/CryptoNoteBasic.h"
#include "CryptoNoteCore/CryptoNoteFormatUtils.h"

#include "SingleTransactionTestBase.h"

class test_generate_key_image_helper : public single_tx_test_base
{
public:
  static const size_t loop_count = 500;

  bool test()
  {
    CryptoNote::KeyPair in_ephemeral;
    Crypto::KeyImage ki;
    return CryptoNote::generate_key_image_helper(m_bob.getAccountKeys(), m_tx_pub_key, 0, in_ephemeral, ki);
  }
};
