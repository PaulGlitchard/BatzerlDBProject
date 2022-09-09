#include "data_storage.hpp"


DataStorage::DataStorage(std::string path):
path_{path}
{
  // readDatabase();
}

DataStorage::~DataStorage()
{

}

void DataStorage::readDatabase()
{
  // ate = at the end, binary = open in binary
  // std::ifstream file(path_, std::ifstream::ate | std::ifstream::binary);
  // long file_size = file.tellg();
  // std::cout<<file_size<<std::endl;
  // file_in_memory_ = mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, file, 0);
}





