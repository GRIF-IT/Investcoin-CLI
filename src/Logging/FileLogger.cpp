// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#include "FileLogger.h"

namespace Logging {

FileLogger::FileLogger(Level level) : StreamLogger(level) {
}

void FileLogger::init(const std::string& fileName) {
  fileStream.open(fileName, std::ios::app);
  StreamLogger::attachToStream(fileStream);
}

}
