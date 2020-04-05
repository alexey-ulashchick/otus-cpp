#include <iostream>

int main(int, char **) {
  int x;
  std::cin >> x;

  if (x <= 4) {
    std::cout << "few";
  } else if (x <= 9) {
    std::cout << "several";
  } else if (x <= 19) {
    std::cout << "pack";
  } else if (x <= 49) {
    std::cout << "lots";
  } else if (x <= 99) {
    std::cout << "horde";
  } else if (x <= 249) {
    std::cout << "throng";
  } else if (x <= 499) {
    std::cout << "swarm";
  } else if (x <= 999) {
    std::cout << "zounds";
  } else {
    std::cout << "legion";
  }

  return 0;
}