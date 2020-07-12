// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <cstddef>
#include <cstdint>
#include <vector>
#include <CryptoNote.h>

using namespace CryptoNote;

namespace Common {

template<class It>
inline BinaryArray::iterator append(BinaryArray &ba, It be, It en) {
	return ba.insert(ba.end(), be, en);
}
inline BinaryArray::iterator append(BinaryArray &ba, size_t add, BinaryArray::value_type va) {
	return ba.insert(ba.end(), add, va);
}
inline BinaryArray::iterator append(BinaryArray &ba, const BinaryArray &other) {
	return ba.insert(ba.end(), other.begin(), other.end());
}

} // namespace Common
