#include "output.hpp"

Output::Output(/* args */)
{
}

Output::Output(std::string name):
name_{name},
error_code_{ErrorCodes::NO_ERROR}
{
}

Output::~Output()
{
}

void Output::setName(std::string name)
{
  name_ = name;
}

void Output::setList(std::vector<std::string> list)
{
  list_ = list;
}

void Output::setError(ErrorCodes error)
{
  error_code_ = error;
}

std::string Output::getName()
{
  return name_;
}

std::vector<std::string> Output::getList()
{
  return list_;
}

ErrorCodes Output::getErrorCode()
{
  return error_code_;
}

