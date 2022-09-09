#ifndef DATA_STORAGE_HPP
#define DATA_STORAGE_HPP

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
// #include <WinBase.h>
#include "constants.hpp"


class DataStorage
{
  private: 
    std::string path_;
    char* file_in_memory_;
    void readDatabase();
    
  public:
    DataStorage(std::string path);
    ~DataStorage();

};

#endif