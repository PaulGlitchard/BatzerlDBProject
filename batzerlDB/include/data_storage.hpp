#ifndef DATA_STORAGE_HPP
#define DATA_STORAGE_HPP

#include <string>
#include <vector>
#include "constants.hpp"
// #include "hash_table.hpp"


class DataStorage
{
  private:
    static DataStorage* instance_;    

    DataStorage();
    ~DataStorage();
  public:
    DataStorage(DataStorage &other) = delete;
    void operator=(const DataStorage&) = delete;
    static DataStorage* getInstance();
};

#endif