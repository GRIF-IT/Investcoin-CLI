// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include "CryptoNoteCore/CryptoNoteBasic.h"
#include "CryptoNoteCore/CryptoNoteFormatUtils.h"

#include "SingleTransactionTestBase.h"

class test_is_out_to_acc : public single_tx_test_base
{
public:
  static const size_t loop_count = 1000;

  bool test()
  {
    const CryptoNote::KeyOutput& tx_out = boost::get<CryptoNote::KeyOutput>(m_tx.outputs[0].target);
    return CryptoNote::is_out_to_acc(m_bob.getAccountKeys(), tx_out, m_tx_pub_key, 0);
  }
};
