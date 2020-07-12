// Copyright (c) 2018-2020, The Investcoin Project, GRIF-IT

#pragma once

#include <fstream>
#include <memory>
#include <string>

#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

namespace Tools {

template <class t_object>
bool serialize_obj_to_file(t_object& obj, const std::string& file_path) {
  try {
    std::ofstream file(file_path);
    boost::archive::binary_oarchive a(file);
    a << obj;
    if (file.fail()) {
      return false;
    }

    file.flush();
    return true;
  } catch (std::exception&) {
    return false;
  }
}

template <class t_object>
bool unserialize_obj_from_file(t_object& obj, const std::string& file_path) {
  try {
    std::ifstream dataFile;
    dataFile.open(file_path, std::ios_base::binary | std::ios_base::in);
    if (dataFile.fail()) {
      return false;
    }

    boost::archive::binary_iarchive a(dataFile);
    a >> obj;
    return !dataFile.fail();
  } catch (std::exception&) {
    return false;
  }
}

}
