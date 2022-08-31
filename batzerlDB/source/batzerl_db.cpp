#include "batzerl_db.hpp"

BatzerlDB* BatzerlDB::instance_ = nullptr;

BatzerlDB::BatzerlDB(/* args */)
{
  ErrorManager::getInstance();
  std::cout << WELCOME_TEXT;
  requestInformation();
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

void BatzerlDB::requestInformation() {
  std::cout << CONFIC_TEXT;
  InputManager* input = new InputManager(1);

  delete input;
}
