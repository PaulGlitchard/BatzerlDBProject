#include "input_manager.hpp"

InputManager::InputManager(size_t max):
input_{}
{
  while (1)
  {
    InputManager::getInputFromUser();
    if(!ErrorManager::getInstance()->checkForInputError(input_, max)) 
    {
      break;
    }
    input_.clear();
  }
  
}

InputManager::~InputManager()
{
}

void InputManager::getInputFromUser() 
{
  std::string text;
  std::getline(std::cin, text);
  if(text.at(text.length()-1) != ' ') 
  {
    text += ' ';
  }
  std::string sub_string;
  for (size_t counter = 0; counter < text.length(); counter++) 
  {
    if(text.at(counter) == ' ') 
    {
      input_.push_back(sub_string);
      sub_string.clear();
    }
    sub_string += text.at(counter);
  }
}

size_t InputManager::getInputLength()
{
  return input_.size();
}

