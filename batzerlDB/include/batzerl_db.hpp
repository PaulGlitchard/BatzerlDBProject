#ifndef BATZERLDB_HPP
#define BATZERLDB_HPP

#include <iostream>
#include <filesystem>

class BatzerlDB
{
  private:
    static BatzerlDB* instance_;
    BatzerlDB(/* args */);
    ~BatzerlDB();

    int write();
  public:
    BatzerlDB(BatzerlDB &other) = delete;
    void operator=(const BatzerlDB&) = delete;
    static BatzerlDB* getInstance();

    int put();
    int get();
    int remove();
};

#endif