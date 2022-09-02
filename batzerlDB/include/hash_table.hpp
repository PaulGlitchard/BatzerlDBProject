#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <string>
#include <vector>
#include <iostream>
#include "constants.hpp"
#include "error_manager.hpp"
#include "output.hpp"

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
    ErrorManager* error_manager_;
  public:
    HashTable(int size);
    ~HashTable();

    HashItem* createItem(std::string name, std::vector<std::string> att);
    void createTable();
    int hashFunction(std::string str, int offset);
    Output insertItem(std::string name, std::vector<std::string> att);
    Output getItem(std::string name);
    Output deleteItem(std::string name);

};

#endif