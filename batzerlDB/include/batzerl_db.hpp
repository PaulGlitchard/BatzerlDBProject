#ifndef BATZERLDB_HPP
#define BATZERLDB_HPP

#include <iostream>
#include <filesystem>
#include "input_manager.hpp"
#include "error_manager.hpp"

const std::string WELCOME_TEXT = "Welcome to BatzerlDB\n";
const std::string CONFIC_TEXT = "Please enter the path to the Database\n";

class BatzerlDB
{
  private:
    static BatzerlDB* instance_;
    BatzerlDB(/* args */);
    ~BatzerlDB();

    void requestInformation();
  public:
    BatzerlDB(BatzerlDB &other) = delete;
    void operator=(const BatzerlDB&) = delete;
    static BatzerlDB* getInstance();
};

#endif