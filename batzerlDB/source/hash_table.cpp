#include "hash_table.hpp"

HashTable::HashTable(int size):
size_{size},
count_{0}
{
  error_manager_ = new ErrorManager();
  createTable();
}

HashTable::~HashTable()
{
  for (size_t i{0}; i < size_; i++)
  {
    if (items_[i] != nullptr)
    {
      delete items_[i];
    }
  }
  delete items_;
  delete error_manager_;
}

HashItem* HashTable::createItem(std::string name, std::vector<std::string> att)
{
  HashItem* item = new HashItem();
  item->name = name;
  item->att = att;
  return item;
}

void HashTable::createTable()
{
  // items_ = (HashItem**)calloc(size_, sizeof(HashItem*));

  items_ = (HashItem**)new HashItem*[size_];
  for (size_t i{0}; i < size_; i++)
  {
    items_[i] = nullptr;
  }
}

int HashTable::hashFunction(std::string str, int offset)
{
  int address{0};
  for (auto &&c : str)
    address += c;
  return ((address + offset) % size_);
}

ErrorCodes HashTable::insertItem(std::string name, std::vector<std::string> att)
{
  if (count_ == size_)
  {
    std::cout << StringConst::NO_MORE_PLACE << std::endl;
    return ErrorCodes::NO_EXIST;
  }

  
  
  int offset{0};
  int index{0};
  while (1)
  {
    index = hashFunction(name, offset);
    if(items_[index] == nullptr) 
    {
      items_[index] = createItem(name, att);
      break;
    }
    else if(items_[index]->name == name) 
    {
      std::cout << StringConst::ALREADY_EXISTS << std::endl;
      return ErrorCodes::ALREADY_EXIST;
    }
    else
    {
      offset++;
    }
  }
  return ErrorCodes::NO_ERROR;  
}

Output HashTable::getItem(std::string name)
{
  int offset{0};
  int index{0};
  Output output;
  while (1)
  {
    index = hashFunction(name, offset);
    if (items_[index] == nullptr)
    {
      break;
    }
    else if(items_[index]->name == name) 
    {
      output.setList(items_[index]->att);
      break;
    }
    else
    {
      offset++;
    }
  }
  return output;
}

ErrorCodes HashTable::deleteItem(std::string name)
{
  int i{ValueConst::HASH_TABLE_LENGTH};
  int offset{0};
  int index{0};
  while (1)
  {
    index = hashFunction(name, offset);
    if (items_[index] == nullptr)
    {
      return ErrorCodes::NO_EXIST;
    }
    else if(items_[index]->name == name) 
    {
      delete items_[index];
      items_[index] = nullptr;
      return ErrorCodes::NO_ERROR;
    }
    else
    {
      offset++;
    }
  }
}

