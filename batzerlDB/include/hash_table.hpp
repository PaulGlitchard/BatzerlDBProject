#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <string>
#include <vector>
#include <iostream>
#include "constants.hpp"

struct HashItem
{
  std::string name;
  std::vector<std::string> att;
};

class HashTable
{
  private:
    HashItem** items_;
    int size_;
    int count_;
  public:
    HashTable(int size);
    ~HashTable();

    HashItem* createItem(std::string name, std::vector<std::string> att);
    void createTable();
    int hashFunction(std::string str, int offset);
    bool insertItem(std::string name, std::vector<std::string> att);
    std::vector<std::string> getItem(std::string name);
    bool deleteItem(std::string name);

};

#endif