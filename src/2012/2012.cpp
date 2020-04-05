#include <iostream>

int main(int, char **) {
  const int TASK = 4 * 60 / 45;
  const int TOTAL = 12;

  int f;
  std::cin >> f;
  std::cout << (TOTAL <= (f + TASK) ? "YES" : "NO") << std::endl;

  return 0;
}