#include "error_manager.hpp"

ErrorManager* ErrorManager::instance_ = nullptr;

ErrorManager::ErrorManager(/* args */)
{
}

ErrorManager::~ErrorManager()
{
  delete instance_;
}

ErrorManager* ErrorManager::getInstance()
{
  if (instance_ == nullptr) {
    instance_ = new ErrorManager();
  }
  return instance_;
}

bool ErrorManager::checkForInputError(std::vector<std::string> input, size_t max) 
{
  if (input.size() == 0)
  {
    std::cout << NO_COMMAND;
    return true;
  }
  else if (input.size() > max)
  {
    std::cout << TOO_MANY_COMMANDS << max << std::endl;
    return true;
  }
  
  return false;
}