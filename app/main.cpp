#include <iostream>
#include "batzerl_db.hpp"

int main(int, char**) {
  BatzerlDB* db = BatzerlDB::getInstance("db.json");

  std::vector<std::string> input = {"shelf", "easter", "europe"};
  db->put("paul", input);
  db->put("paul", input);
  input = {"books", "water", "hello there"};
  db->put("peter", input);
  input = {"shelf", "easter", "europe"};
  db->put("karl", input);
  input = {"shelf", "western", "america"};
  db->put("franz", input);

  // std::vector<std::string> output;
  // output = db->get("paul");
  // if (!output.empty())
  // {
  //   std::cout << output.at(0) << std::endl;
  // }
  // else
  // {
  //   std::cout << "this person doesn't exist"<<std::endl;
  // }
  
  // output = db->get("jeff");
  // if (!output.empty())
  // {
  //   std::cout << output.at(0) << std::endl;
  // }
  // else
  // {
  //   std::cout << "this person doesn't exist"<<std::endl;
  // }

  // db->remove("paul");
  // output = db->get("paul");
  // if (!output.empty())
  // {
  //   std::cout << output.at(0) << std::endl;
  // }
  // else
  // {
  //   std::cout << "this person doesn't exist"<<std::endl;
  // }

  return 0;
}