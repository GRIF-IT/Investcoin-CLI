// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once 
#include "Chaingen.h"

/************************************************************************/
/*                                                                      */
/************************************************************************/
class gen_chain_switch_1 : public test_chain_unit_base
{
public: 
  gen_chain_switch_1();

  bool generate(std::vector<test_event_entry>& events) const;

  bool check_split_not_switched(CryptoNote::core& c, size_t ev_index, const std::vector<test_event_entry>& events);
  bool check_split_switched(CryptoNote::core& c, size_t ev_index, const std::vector<test_event_entry>& events);

private:
  std::list<CryptoNote::Block> m_chain_1;

  CryptoNote::AccountBase m_recipient_account_1;
  CryptoNote::AccountBase m_recipient_account_2;
  CryptoNote::AccountBase m_recipient_account_3;
  CryptoNote::AccountBase m_recipient_account_4;

  std::vector<CryptoNote::Transaction> m_tx_pool;
};
