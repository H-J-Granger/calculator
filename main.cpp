#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>

std::string query(std::string str) {
  
}

int main(int argc, char** argv) {
  for (std::uint64_t i = 0;; i++) {
    std::printf("In[%d]: ", i);
    std::string str;
    std::cin >> str;
    if (str == "quit") { return 0; }
    std::printf("Out[%d]: ", i);
    try {
      std::cout << query(str) << std::endl;
    } catch (std::string error) {
      std::cout << "Expection: " << error;
    }
  }
  return 0;
}