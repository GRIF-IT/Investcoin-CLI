// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <string>
#include <vector>

namespace Tests {

  class Process {
  public:

    void startChild(const std::string& executablePath, const std::vector<std::string>& args = {});
    void wait();

  private:

    size_t m_pid = 0;

  };
}
