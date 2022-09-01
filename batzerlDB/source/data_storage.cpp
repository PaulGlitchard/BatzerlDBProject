#include "data_storage.hpp"

DataStorage* DataStorage::instance_ = nullptr;

DataStorage::DataStorage(/* args */)
{
}

DataStorage::~DataStorage()
{
  delete instance_;
}

DataStorage* DataStorage::getInstance() 
{
  if (instance_ == nullptr) 
  {
    instance_ = new DataStorage();
  }
  return instance_;
}




