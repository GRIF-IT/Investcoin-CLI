// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <System/Dispatcher.h>

namespace System {

class ContextGroup {
public:
  explicit ContextGroup(Dispatcher& dispatcher);
  ContextGroup(const ContextGroup&) = delete;
  ContextGroup(ContextGroup&& other);
  ~ContextGroup();
  ContextGroup& operator=(const ContextGroup&) = delete;
  ContextGroup& operator=(ContextGroup&& other);
  void interrupt();
  void spawn(std::function<void()>&& procedure);
  void wait();

private:
  Dispatcher* dispatcher;
  NativeContextGroup contextGroup;
};

}
