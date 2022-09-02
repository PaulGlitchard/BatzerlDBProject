#ifndef BATZERLDB_HPP
#define BATZERLDB_HPP

#include <iostream>
#include <filesystem>

#include "constants.hpp"
#include "data_storage.hpp"
#include "hash_table.hpp"

// struct Output
// {
//   std::string str;
//   std::vector<std::string> list;

// };


class BatzerlDB
{
  private:
    static BatzerlDB* instance_;
    HashTable* hash_table_;
    DataStorage* data_storage_;

    BatzerlDB();
    ~BatzerlDB();

    int write();
  public:
    BatzerlDB(BatzerlDB &other) = delete;
    void operator=(const BatzerlDB&) = delete;
    static BatzerlDB* getInstance();

    bool put(std::string name, std::vector<std::string> att);
    std::vector<std::string> get(std::string name);
    bool remove(std::string name);
};

#endif