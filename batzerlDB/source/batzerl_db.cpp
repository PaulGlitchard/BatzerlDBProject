#include "batzerl_db.hpp"

BatzerlDB* BatzerlDB::instance_ = nullptr;

BatzerlDB::BatzerlDB()
{
  error_manager_ = new ErrorManager();
  hash_table_ = new HashTable(ValueConst::HASH_TABLE_LENGTH);
  data_storage_ = new DataStorage();
}

BatzerlDB::~BatzerlDB()
{
  delete instance_;
}

BatzerlDB* BatzerlDB::getInstance() {
  if (instance_ == nullptr) {
    instance_ = new BatzerlDB();
  }
  return instance_;
}

ErrorCodes BatzerlDB::put(std::string name, std::vector<std::string> att)
{
  return hash_table_->insertItem(name, att);
}

Output BatzerlDB::get(std::string name)
{
  return hash_table_->getItem(name);
}

ErrorCodes BatzerlDB::remove(std::string name)
{
  return hash_table_->deleteItem(name);
}

