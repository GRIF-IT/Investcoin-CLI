// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <stdint.h>
#include <string>

namespace Common {

bool parseUrlAddress(const std::string& url, std::string& host, uint16_t& port, std::string& path, bool& ssl);

}
