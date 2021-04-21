#include <handler.h>

#include <string>
#include <fstream>
#include <iostream>

std::string ReadAPIKey() {
  std::ifstream api_file("data/no_commit_api_key.txt");
  std::string api_key;

  getline(api_file, api_key);
  api_file.close();

  return api_key;
}

int main() {
  std::cout << ReadAPIKey() << std::endl;
  return 0;
}
