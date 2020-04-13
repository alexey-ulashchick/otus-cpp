#include <cmath>
#include <iostream>
#include <stack>

int main(int, char **) {
  std::stack<uint64_t> nums;
  uint64_t value;

  while (std::cin >> value) {
    nums.push(value);
  }

  while (!nums.empty()) {
    printf("%.4f\n", std::sqrt(nums.top()));
    nums.pop();
  }

  return 0;
}