#include "batzerl_db.hpp"

BatzerlDB* BatzerlDB::instance_ = nullptr;

BatzerlDB::BatzerlDB()
{

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
