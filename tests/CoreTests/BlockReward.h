// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once 
#include "Chaingen.h"

struct gen_block_reward : public test_chain_unit_base
{
  gen_block_reward();

  bool generate(std::vector<test_event_entry>& events) const;

  bool check_block_verification_context(const CryptoNote::block_verification_context& bvc, size_t event_idx, const CryptoNote::Block& blk);

  bool mark_invalid_block(CryptoNote::core& c, size_t ev_index, const std::vector<test_event_entry>& events);
  bool mark_checked_block(CryptoNote::core& c, size_t ev_index, const std::vector<test_event_entry>& events);
  bool check_block_rewards(CryptoNote::core& c, size_t ev_index, const std::vector<test_event_entry>& events);

private:
  size_t m_invalid_block_index;
  std::vector<size_t> m_checked_blocks_indices;
};
