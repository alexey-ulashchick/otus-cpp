#include "ip_address.h"
#include <iostream>
#include <string>
#include <vector>

std::ostream &operator<<(std::ostream &os, const IpAddress &ipAddress) {
  os << static_cast<unsigned>(ipAddress.sec1) << '.'
     << static_cast<unsigned>(ipAddress.sec2) << '.'
     << static_cast<unsigned>(ipAddress.sec3) << '.'
     << static_cast<unsigned>(ipAddress.sec4);
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
  if (sec1 != val.sec1) {
    return val.sec1 < sec1;
  } else if (sec2 != val.sec2) {
    return val.sec2 < sec2;
  } else if (sec3 != val.sec3) {
    return val.sec3 < sec3;
  } else {
    return val.sec4 < sec4;
  }
}