#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace ValueConst
{
  const int HASH_TABLE_LENGTH = 100;
} // namespace DataStorage

namespace StringConst
{
  const std::string NO_MORE_PLACE = "There is no more space";
  const std::string ALREADY_EXISTS = "This already exists";
}

typedef enum _ErrorCodes_
{
  NO_ERROR,
  NO_EXIST
} ErrorCodes;


#endif