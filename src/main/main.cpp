#include "src/ip_address/ip_address.h"
#include <iostream>
#include <sstream>
#include <vector>

std::string getFirstIpFromTabulatedString(const std::string &str) {
  std::stringstream ss(str);
  std::string token;
  std::getline(ss, token, '\t');

  return token;
}

int main(int, char **) {
  std::vector<IpAddress> ipAddresses;

  for (std::string line; std::getline(std::cin, line);) {
    std::string ipString = getFirstIpFromTabulatedString(line);
    ipAddresses.push_back(IpAddress::fromString(ipString));
  }

  std::sort(ipAddresses.begin(), ipAddresses.end());

  for (IpAddress ipAddress : ipAddresses) {
    std::cout << ipAddress << std::endl;
  }

  return 0;
}