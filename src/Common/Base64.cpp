// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#include "Base64.h"

namespace Tools
{
  namespace Base64
  {
    std::string encode(const std::string& data) {
      static const char* encodingTable = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
      const size_t resultSize = 4 * ((data.size() + 2) / 3);
      std::string result;
      result.reserve(resultSize);

      for (size_t i = 0; i < data.size(); i += 3) {
        size_t a = static_cast<size_t>(data[i]);
        size_t b = i + 1 < data.size() ? static_cast<size_t>(data[i + 1]) : 0;
        size_t c = i + 2 < data.size() ? static_cast<size_t>(data[i + 2]) : 0;

        result.push_back(encodingTable[a >> 2]);
        result.push_back(encodingTable[((a & 0x3) << 4) | (b >> 4)]);
        if (i + 1 < data.size()) {
          result.push_back(encodingTable[((b & 0xF) << 2) | (c >> 6)]);
          if (i + 2 < data.size()) {
            result.push_back(encodingTable[c & 0x3F]);
          }
        }
      }

      while (result.size() != resultSize) {
        result.push_back('=');
      }

      return result;
    }
  }
}
