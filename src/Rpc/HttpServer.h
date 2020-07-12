// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once 

#include <unordered_set>

#include <HTTP/HttpRequest.h>
#include <HTTP/HttpResponse.h>

#include <System/ContextGroup.h>
#include <System/Dispatcher.h>
#include <System/TcpListener.h>
#include <System/TcpConnection.h>
#include <System/Event.h>

#include <Logging/LoggerRef.h>

namespace CryptoNote {

class HttpServer {

public:

  HttpServer(System::Dispatcher& dispatcher, Logging::ILogger& log);

  void start(const std::string& address, uint16_t port, const std::string& user = "", const std::string& password = "");
  void stop();

  virtual void processRequest(const HttpRequest& request, HttpResponse& response) = 0;
  virtual size_t get_connections_count() const;

protected:

  System::Dispatcher& m_dispatcher;

private:

  void acceptLoop();
  void connectionHandler(System::TcpConnection&& conn);
  bool authenticate(const HttpRequest& request) const;

  System::ContextGroup workingContextGroup;
  Logging::LoggerRef logger;
  System::TcpListener m_listener;
  std::unordered_set<System::TcpConnection*> m_connections;
  std::string m_credentials;
};

}
