#ifndef TEMPLATE_IP_ADDRESS_H
#define TEMPLATE_IP_ADDRESS_H

#include <iostream>

class IpAddress {
private:
  unsigned char sec1;
  unsigned char sec2;
  unsigned char sec3;
  unsigned char sec4;

  IpAddress(unsigned char sec1, unsigned char sec2, unsigned char sec3,
            unsigned char sec4)
      : sec1{sec1}, sec2{sec2}, sec3{sec3}, sec4{sec4} {};

public:
  static IpAddress fromString(const std::string &str);

  friend std::ostream &operator<<(std::ostream &os, const IpAddress &ipAddress);

  bool operator<(const IpAddress &val) const;
};

#endif