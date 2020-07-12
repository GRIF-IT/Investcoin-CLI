// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <string>
#include <ostream>

namespace CryptoNote {

void importLegacyKeys(const std::string& legacyKeysFilename, const std::string& password, std::ostream& destination);

} //namespace CryptoNote
