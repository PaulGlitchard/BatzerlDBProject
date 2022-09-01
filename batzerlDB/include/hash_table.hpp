#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <string>
#include <vector>
#include "constants.hpp"

struct HashItem
{
  std::string str;
  std::vector<std::string> attributes;
};

class HashTable
{
  private:
    static HashTable* instance_;
    HashItem** items_;
    int size_;
    
    HashTable();
    ~HashTable();
  public:
    HashTable(HashTable &other) = delete;
    void operator=(const HashTable&) = delete;
    static HashTable* getInstance();

    void createTable();
    int hashFunction(std::string str);

};

#endif