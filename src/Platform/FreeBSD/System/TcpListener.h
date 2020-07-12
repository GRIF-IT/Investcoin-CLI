// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <cstdint>
#include <string>

namespace System {

class Dispatcher;
class Ipv4Address;
class TcpConnection;

class TcpListener {
public:
  TcpListener();
  TcpListener(Dispatcher& dispatcher, const Ipv4Address& address, uint16_t port);
  TcpListener(const TcpListener&) = delete;
  TcpListener(TcpListener&& other);
  ~TcpListener();
  TcpListener& operator=(const TcpListener&) = delete;
  TcpListener& operator=(TcpListener&& other);
  TcpConnection accept();

private:
  Dispatcher* dispatcher;
  int listener;
  void* context;
};

}
