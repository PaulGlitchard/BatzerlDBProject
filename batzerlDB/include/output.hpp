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
    Output();
    Output(std::string name);
    ~Output();

    void setName(std::string name);
    void setList(std::vector<std::string> list);
    void setError(ErrorCodes error);
    std::string getName();
    std::vector<std::string> getList();
    ErrorCodes getErrorCode();
};


#endif