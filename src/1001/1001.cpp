#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

int main(int, char **) {
  std::stringstream stringStream;
  std::string str;

  while (std::getline(std::cin, str)) {
    stringStream << str << " ";
  }

  std::vector<long> nums;

  while (stringStream >> str) {
    nums.push_back(std::stol(str));
  }

  for (auto rit = nums.rbegin(); rit != nums.rend(); ++rit) {
    printf("%.4f\n", std::sqrt(*rit));
  }

  return 0;
}