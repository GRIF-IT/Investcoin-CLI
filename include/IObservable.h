// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

namespace CryptoNote {

template <typename T>
class IObservable {
public:
  virtual void addObserver(T* observer) = 0;
  virtual void removeObserver(T* observer) = 0;
};

}
