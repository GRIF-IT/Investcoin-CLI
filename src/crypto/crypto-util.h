// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <stddef.h>
#include <stdint.h>

#if defined(__cplusplus)
extern "C" {
#endif
// We borrow from https://libsodium.org/
void sodium_memzero(void *pnt, size_t length);
int sodium_compare(const void *a1, const void *a2, size_t length);

#if defined(__cplusplus)
}
#endif
