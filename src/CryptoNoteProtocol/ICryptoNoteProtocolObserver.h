// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <cstddef>
#include <cstdint>
#include <cstddef>

namespace CryptoNote {

class ICryptoNoteProtocolObserver {
public:
  virtual void peerCountUpdated(size_t count) {}
  virtual void lastKnownBlockHeightUpdated(uint32_t height) {}
  virtual void blockchainSynchronized(uint32_t topHeight) {}
};

} //namespace CryptoNote
