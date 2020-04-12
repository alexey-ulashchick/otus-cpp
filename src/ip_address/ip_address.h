#ifndef TEMPLATE_SRC_IP_ADDRESS_IP_ADDRESS_H
#define TEMPLATE_SRC_IP_ADDRESS_IP_ADDRESS_H

#include <iostream>

class IpAddress {
private:
  unsigned char oct1;
  unsigned char oct2;
  unsigned char oct3;
  unsigned char oct4;

  IpAddress(unsigned char oct1, unsigned char oct2, unsigned char oct3,
            unsigned char oct4)
      : oct1{oct1}, oct2{oct2}, oct3{oct3}, oct4{oct4} {};

public:
  static IpAddress fromString(const std::string &str);

  friend std::ostream &operator<<(std::ostream &os, const IpAddress &ipAddress);

  bool operator<(const IpAddress &val) const;
  bool isMatch(unsigned char oct1) const;
  bool isMatch(unsigned char oct1, unsigned char oct2) const;
  bool isMatchAny(unsigned char oct) const;
};

#endif