#ifndef OUTPUT_HPP
#define OUTPUT_HPP

#include <string>
#include <vector>
#include "constants.hpp"

class Output
{
  private:
    std::string name_;
    std::vector<std::string> list_;
    ErrorCodes error_code_;
  public:
    Output(/* args */);
    ~Output();

    std::string getName();
    std::vector<std::string> getList();
    ErrorCodes getErrorCode();
};


#endif