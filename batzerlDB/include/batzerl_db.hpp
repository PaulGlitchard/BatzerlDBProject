#ifndef BATZERLDB_HPP
#define BATZERLDB_HPP

#include <iostream>
#include <filesystem>

#include "constants.hpp"
#include "data_storage.hpp"
#include "hash_table.hpp"
#include "error_manager.hpp"
#include "output.hpp"

class BatzerlDB
{
  private:
    static BatzerlDB* instance_;
    HashTable* hash_table_;
    DataStorage* data_storage_;
    ErrorManager* error_manager_;

    BatzerlDB();
    ~BatzerlDB();

    int write();
  public:
    BatzerlDB(BatzerlDB &other) = delete;
    void operator=(const BatzerlDB&) = delete;
    static BatzerlDB* getInstance();

    ErrorCodes put(std::string name, std::vector<std::string> att);
    Output get(std::string name);
    ErrorCodes remove(std::string name);
};

#endif