// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once 
#include "Chaingen.h"

class gen_simple_chain_001: public test_chain_unit_base 
{
public: 
  gen_simple_chain_001();
  bool generate(std::vector<test_event_entry> &events);
  bool verify_callback_1(CryptoNote::core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
  bool verify_callback_2(CryptoNote::core& c, size_t ev_index, const std::vector<test_event_entry> &events); 
};

class one_block: public test_chain_unit_base
{
  CryptoNote::AccountBase alice;
public:
  one_block();
  bool generate(std::vector<test_event_entry> &events);
  bool verify_1(CryptoNote::core& c, size_t ev_index, const std::vector<test_event_entry> &events);
};
