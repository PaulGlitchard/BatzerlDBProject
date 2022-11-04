#include "hash_table.hpp"

HashTable::HashTable(int size):
size_{size},
count_{0}
{
  createTable();

  accessStorage();
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


void HashTable::accessStorage()
{
  int fd = open("batzerl_data.txt", O_CREAT|O_RDWR);
  storage_ptr_ = (char*)mmap(0,321*ValueConst::HASH_TABLE_LENGTH+1,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
  
  // ftruncate(fd,320*ValueConst::HASH_TABLE_LENGTH+1);

  storage_ptr_[321*ValueConst::HASH_TABLE_LENGTH+1] = 0;
    
}

int HashTable::hashFunction(std::string str, int offset)
{
  int address{0};
  for (auto &&c : str)
    address += c;
  return ((address + offset) % size_) * 321;
}

bool compareStringAndSave(std::string name, char* ptr)
{
  for (size_t i = 0; i < name.size(); i++)
  {
    if (name.at(i) != ptr[i])
      return false;
  }
  return true;
}

bool HashTable::insertItem(std::string name, std::vector<std::string> att)
{
  if (count_ == size_)
  {
    std::cout << StringConst::NO_MORE_PLACE << std::endl;
    return false;
  }
  
  int offset{0};
  int index{0};
  while (1)
  {
    index = hashFunction(name, offset);
    if(storage_ptr_[index] == 0) 
    {
      storage_ptr_[index] = 1;
      index++;
      //fill name
      for (size_t i = 0; i < 64; i++)
      {
        if (i < name.size())
        {
          storage_ptr_[index + i] = name.at(i);
        }
        else
        {
          storage_ptr_[index + i] = 0;
        }
      }
      index += 64;
      //fill atts
      size_t att_index = 0;
      size_t char_counter = 0;
      for (size_t i = 0; i < 256; i++)
      {
        if (att_index < att.size())
        {
          if (char_counter < att.at(att_index).size())
          {
            storage_ptr_[i] = att.at(att_index).at(char_counter);
            char_counter++;
          }
          else
          {
            att_index++;
          }
        } 
        else
        {
          storage_ptr_[i] = 0;
        }       

      }
      break;
    }
    else if(storage_ptr_[index] == 1 && compareStringAndSave(name, &storage_ptr_[index + 1])) 
    {
      std::cout << StringConst::ALREADY_EXISTS << std::endl;
      return false;
    }
    else
    {
      offset++;
    }
  }
  return true;  
}

std::vector<std::string> HashTable::getItem(std::string name)
{
  int offset{0};
  int index{0};
  std::vector<std::string> output{};
  while (1)
  {
    index = hashFunction(name, offset);
    if (items_[index] == nullptr)
    {
      break;
    }
    else if(items_[index]->name == name) 
    {
      output = items_[index]->att;
      break;
    }
    else
    {
      offset++;
    }
  }
  return output;
}

bool HashTable::deleteItem(std::string name)
{
  int offset{0};
  int index{0};
  while (1)
  {
    index = hashFunction(name, offset);
    if (items_[index] == nullptr)
    {
      return false;
    }
    else if(items_[index]->name == name) 
    {
      delete items_[index];
      items_[index] = nullptr;
      return true;
    }
    else
    {
      offset++;
    }
  }
}

