// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <cstddef>
#include <cstdint>
#include "P2p/ConnectionContext.h"

namespace CryptoNote {
class ICryptoNoteProtocolObserver;

class ICryptoNoteProtocolQuery {
public:
  virtual bool addObserver(ICryptoNoteProtocolObserver* observer) = 0;
  virtual bool removeObserver(ICryptoNoteProtocolObserver* observer) = 0;

  virtual uint32_t getObservedHeight() const = 0;
  virtual size_t getPeerCount() const = 0;
  virtual bool isSynchronized() const = 0;
  virtual bool getConnections(std::vector<CryptoNoteConnectionContext>& connections) const = 0;
};

} //namespace CryptoNote
