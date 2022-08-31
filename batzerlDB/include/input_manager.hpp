#ifndef INPUT_MANAGER_HPP
#define INPUT_MANAGER_HPP

#include <iostream>
#include <string>
#include <vector>
#include "error_manager.hpp"

class InputManager
{
private:
  std::vector<std::string> input_;
  //----------------------------------
  // gets the input from a user and chops it in manageable sub strings
  void getInputFromUser();
public:
  InputManager(size_t max);
  ~InputManager();
  size_t getInputLength();
};


#endif