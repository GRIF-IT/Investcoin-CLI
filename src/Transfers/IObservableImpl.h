// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include "Common/ObserverManager.h"

namespace CryptoNote {

template <typename Observer, typename Base>
class IObservableImpl : public Base {
public:

  virtual void addObserver(Observer* observer) override {
    m_observerManager.add(observer);
  }

  virtual void removeObserver(Observer* observer) override {
    m_observerManager.remove(observer);
  }

protected:
  Tools::ObserverManager<Observer> m_observerManager;
};

}
