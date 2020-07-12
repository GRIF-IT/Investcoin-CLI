// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <crypto/random.h>
#include <stdexcept>
#include <unordered_map>

template <typename T>
class ShuffleGenerator {
public:

  ShuffleGenerator(T n) :
    N(n), count(n) {}

  T operator()() {

    if (count == 0) {
      throw std::runtime_error("shuffle sequence ended");
    }

	T value = Random::randomValue<T>(0, --count);

    auto rvalIt = selected.find(count);
    auto rval = rvalIt != selected.end() ? rvalIt->second : count;

    auto lvalIt = selected.find(value);

    if (lvalIt != selected.end()) {
      value = lvalIt->second;
      lvalIt->second = rval;
    } else {
      selected[value] = rval;
    }

    return value;
  }

  bool empty() const {
    return count == 0;
  }

  void reset() {
    count = N;
    selected.clear();
  }

private:

  std::unordered_map<T, T> selected;
  T count;
  const T N;
};
