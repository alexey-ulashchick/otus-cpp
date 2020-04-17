#ifndef TEMPLATE_SRC_IP_ADDRESS_IP_ADDRESS_H
#define TEMPLATE_SRC_IP_ADDRESS_IP_ADDRESS_H

#include "exceptions.h"
#include <array>
#include <iostream>

/**
 * Ip addrress representation. Can be parametrized with:
 *  - <4>  for IPv4.
 *  - <6>  for IPv6.
 */
template <int T> class IpAddress {
private:
  static const char DELIMITER = T == 4 ? '.' : ':';
  static const int SIZE = T == 4 ? 4 : 8;
  std::array<uint16_t, SIZE> address;

  IpAddress(const std::array<uint16_t, SIZE> &address) : address(address){};

public:
  static IpAddress<T> fromString(const std::string &str) {
    static_assert(T == 4 || T == 6,
                  "Ip address should be parametrized with <4> or <6>.");

    std::array<uint16_t, SIZE> address;

    int i = 0;
    std::string::size_type start = 0;

    while (i != SIZE && start < str.length()) {
      std::string::size_type stop = str.find_first_of(DELIMITER, start);
      stop = stop == std::string::npos ? str.length() : stop;

      try {
        //TODO: Add logic for parshing hex values for IPv6
        std::string subString = str.substr(start, stop - start);
        int v = std::stoi(subString);

        if (v < 0) {
          throwCannotConvertToIp();
        }

        address[i++] = static_cast<uint16_t>(v);
      } catch (...) { // Covering std::invalid_argument and std::out_of_range
        throwCannotConvertToIp();
      }

      start = stop + 1;
    }

    if (start != str.length() + 1 || i != T) {
      throwInvalidArgumentError(T);
    }

    return IpAddress<T>(address);
  };

  friend std::ostream &operator<<(std::ostream &os,
                                  const IpAddress<T> &ipAddress) {
    for (int i = 0; i < IpAddress::SIZE; i++) {
      if (i != 0) {
        os << IpAddress::DELIMITER;
      }

      os << ipAddress.address[i];
    }

    return os;
  };

  bool operator<(const IpAddress<T> &val) const {
    for (auto i=0; i<IpAddress::SIZE; i++) {
      if (val.address[i] != address[i]) {
        return val.address[i] < address[i];
      }
    }

    return false;
  }

  bool operator==(const IpAddress &val) const {
    return address == val.address;
  };

  bool isMatch(uint16_t oct1) const {
     return address[0] == oct1;
  };

  bool isMatch(uint16_t oct1, uint16_t oct2) const {
     return isMatch(oct1) && address[1] == oct2;
  };

  bool isMatchAny(uint16_t oct) const {
    for (auto i=0; i<IpAddress::SIZE; i++) {
      if (address[i] == oct) {
        return true;
      }
    }

    return false;
  };
};

#endif