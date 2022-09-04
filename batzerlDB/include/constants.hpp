#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

namespace ValueConst
{
  const int HASH_TABLE_LENGTH = 100;
} // namespace DataStorage

namespace StringConst
{
  const char NO_MORE_PLACE[] = "There is no more space";
  const char ALREADY_EXISTS[] = "This already exists";
}

typedef enum _ErrorCodes_
{
  NO_ERROR,
  NO_EXIST,
  ALREADY_EXIST
} ErrorCodes;


#endif