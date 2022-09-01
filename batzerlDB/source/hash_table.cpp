#include "hash_table.hpp"

HashTable* HashTable::instance_ = nullptr;

HashTable::HashTable(/* args */):
size_{DSConst::HASH_TABLE_LENGTH}
{
  createTable();
}

HashTable::~HashTable()
{
  for (size_t i = 0; i < size_; i++)
  {
    if (items_[i] != nullptr)
    {
      delete items_[i];
    }
  }
  delete items_;
  delete instance_;
}

HashTable* HashTable::getInstance()
{
  if (instance_ == nullptr)
  {
    instance_ = new HashTable();
  }
  return instance_;
}

void HashTable::createTable()
{
  // items_ = (HashItem**)calloc(size_, sizeof(HashItem*));

  items_ = new HashItem*[size_];
  for (size_t i = 0; i < size_; i++)
  {
    items_[i] = nullptr;
  }
  
  
}

int HashTable::hashFunction(std::string str)
{
  int address = 0;
  for (auto &&c : str)
    address += c;
  return address % size_;
}


