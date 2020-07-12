// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

namespace System {

class Event;

class EventLock {
public:
  explicit EventLock(Event& event);
  ~EventLock();
  EventLock& operator=(const EventLock&) = delete;

private:
  Event& event;
};

}
