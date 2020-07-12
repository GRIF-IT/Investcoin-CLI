// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <cstdint>

#include "CryptoNoteProtocol/ICryptoNoteProtocolObserver.h"
#include "CryptoNoteProtocol/ICryptoNoteProtocolQuery.h"

class ICryptoNoteProtocolQueryStub: public CryptoNote::ICryptoNoteProtocolQuery {
public:
  ICryptoNoteProtocolQueryStub() : peers(0), observedHeight(0), synchronized(false) {}

  virtual bool addObserver(CryptoNote::ICryptoNoteProtocolObserver* observer) override;
  virtual bool removeObserver(CryptoNote::ICryptoNoteProtocolObserver* observer) override;
  virtual uint32_t getObservedHeight() const override;
  virtual size_t getPeerCount() const override;
  virtual bool isSynchronized() const override;

  void setPeerCount(uint32_t count);
  void setObservedHeight(uint32_t height);

  void setSynchronizedStatus(bool status);

private:
  size_t peers;
  uint32_t observedHeight;

  bool synchronized;
};
