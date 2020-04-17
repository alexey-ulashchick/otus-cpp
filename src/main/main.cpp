#include "src/ip_address/filter.h"
#include "src/ip_address/ip_address.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>

std::string getFirstIpFromTabulatedString(const std::string &str) {
  std::stringstream ss(str);
  std::string ip;
  std::getline(ss, ip, '\t');

  return ip;
}

int main(int, char **) {
  std::vector<IpAddress<4>> ipAddresses;

  for (std::string line; std::getline(std::cin, line);) {
    std::string ipString = getFirstIpFromTabulatedString(line);
    ipAddresses.push_back(IpAddress<4>::fromString(ipString));
  }

  std::sort(ipAddresses.begin(), ipAddresses.end());

  for (auto ipAddress : ipAddresses) {
    std::cout << ipAddress << std::endl;
  }

  for (auto ipAddress : filter(ipAddresses, 1)) {
    std::cout << ipAddress << std::endl;
  }

  for (auto ipAddress : filter(ipAddresses, 46, 70)) {
    std::cout << ipAddress << std::endl;
  }

  for (auto ipAddress : filterAny(ipAddresses, 46)) {
    std::cout << ipAddress << std::endl;
  }

  return 0;
}