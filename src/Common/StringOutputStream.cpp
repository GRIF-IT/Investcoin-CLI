// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#include "StringOutputStream.h"

namespace Common {

StringOutputStream::StringOutputStream(std::string& out) : out(out) {
}

size_t StringOutputStream::writeSome(const void* data, size_t size) {
  out.append(static_cast<const char*>(data), size);
  return size;
}

}
