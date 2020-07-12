// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <GreenWallet/Types.h>

char* getCmdOption(char ** begin, char ** end, const std::string & option);

bool cmdOptionExists(char** begin, char** end, const std::string& option);

Config parseArguments(int argc, char **argv);

void helpMessage();

std::string getVersion();

std::vector<CLICommand> getCLICommands();
