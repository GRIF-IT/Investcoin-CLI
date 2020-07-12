// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <cstddef>
#include <initializer_list>

namespace CryptoNote {

struct CheckpointData {
  uint32_t height;
  const char* blockId;
};

const std::initializer_list<CheckpointData> CHECKPOINTS = {
  {10,		"3f658b2dacdd0c1bc1c3cc59037a867992c688079cf5a6594567e2d66b2eb4f1" },
  {100,         "cc5133a55eac068fbbe512dab52b62d6dc5486a0c4da03f5389da8422b2e967c" },
  {1000,	"dece7c338cb084377748106548bfcc14d50c1a7d20e98435a1118c81db3c86fb" },
  {10000,	"7a296132cca0c2e550a824c7997e9a129d019d1e87512e3959c0f86568521932" },
  {11800,       "c7eb3a09d83bef3cdcd313c4c4ff98ce868e10abf0d50bce0a1423a71ae80c00" },
  {73128,       "c06edc6f138010bcf62f266cb87bfd28d57e75746f05953a39a5f93fedcbae86" }
};
  
}
