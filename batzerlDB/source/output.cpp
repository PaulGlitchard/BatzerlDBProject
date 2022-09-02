#include "output.hpp"

Output::Output(/* args */)
{
}

Output::~Output()
{
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
  return ErrorCodes;
}

