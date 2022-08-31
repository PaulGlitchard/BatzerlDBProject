#ifndef ERROR_MANAGER_HPP
#define ERROR_MANAGER_HPP

#include <string>
#include <vector>
#include <iostream>

const std::string NO_COMMAND = "There is no command. Please enter a command\n";
const std::string TOO_MANY_COMMANDS = "There are too many commands please only enter ";

class ErrorManager
{
  private:
    static ErrorManager* instance_;

    ErrorManager();
    ~ErrorManager();
  public:
    ErrorManager(ErrorManager &other) = delete;
    void operator=(const ErrorManager&) = delete;
    static ErrorManager* getInstance();

    bool checkForInputError(std::vector<std::string> input, size_t max);

};




#endif