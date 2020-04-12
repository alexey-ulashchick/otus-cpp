#include "ip_address.h"
#include <iostream>
#include <string>
#include <vector>

std::ostream &operator<<(std::ostream &os, const IpAddress &ipAddress) {
  os << static_cast<unsigned>(ipAddress.oct1) << '.'
     << static_cast<unsigned>(ipAddress.oct2) << '.'
     << static_cast<unsigned>(ipAddress.oct3) << '.'
     << static_cast<unsigned>(ipAddress.oct4);
  return os;
}

IpAddress IpAddress::fromString(const std::string &str) {
  std::vector<char> r;

  const char DELIMETER = '.';

  std::string::size_type start = 0;
  std::string::size_type stop = str.find_first_of(DELIMETER);

  while (stop != std::string::npos) {
    r.push_back(std::stoi(str.substr(start, stop - start)));

    start = stop + 1;
    stop = str.find_first_of(DELIMETER, start);
  }

  r.push_back(std::stoi(str.substr(start)));

  return IpAddress(r.at(0), r.at(1), r.at(2), r.at(3));
}

bool IpAddress::operator<(const IpAddress &val) const {
  if (oct1 != val.oct1) {
    return val.oct1 < oct1;
  } else if (oct2 != val.oct2) {
    return val.oct2 < oct2;
  } else if (oct3 != val.oct3) {
    return val.oct3 < oct3;
  } else {
    return val.oct4 < oct4;
  }
}

bool IpAddress::isMatch(unsigned char oct1) const {
  return this->oct1 == oct1;
};

bool IpAddress::isMatch(unsigned char oct1, unsigned char oct2) const {
  return this->oct1 == oct1 && this->oct2 == oct2;
};

bool IpAddress::isMatchAny(unsigned char oct) const {
  return oct1 == oct || oct2 == oct || oct3 == oct || oct4 == oct;
};