// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#include <System/ErrorMessage.h>
#include <gtest/gtest.h>

using namespace System;

TEST(ErrorMessageTests, testErrorMessage) {
  auto msg = errorMessage(100);
  ASSERT_EQ(msg.substr(0, 12), "result=100, ");
}
