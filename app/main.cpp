#include <iostream>
#include "batzerlDB.hpp"

int main(int, char**) {
  std::cout << "Welcome to BatzerlDB" << std::endl;
  BatzerlDB* db = new BatzerlDB();

  delete db;
  return 0;
}