#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <string>
#include <vector>
#include <iostream>
#include <sys/mman.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "constants.hpp"

struct HashItem
{
  char exist; // 1 or 0
  std::string name; // max 64
  std::vector<std::string> att; //max 256
  // = 321
};

class HashTable
{
  private:
    HashItem** items_;
    int size_;
    int count_;

    char* storage_ptr_;

  public:
    HashTable(int size);
    ~HashTable();

    HashItem* createItem(std::string name, std::vector<std::string> att);
    void createTable();


    void accessStorage();
    int hashFunction(std::string str, int offset);
    bool insertItem(std::string name, std::vector<std::string> att);
    std::vector<std::string> getItem(std::string name);
    bool deleteItem(std::string name);

};

#endif