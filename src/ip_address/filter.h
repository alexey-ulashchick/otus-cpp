#ifndef TEMPLATE_SRC_IP_ADDRESS_FILTER_H
#define TEMPLATE_SRC_IP_ADDRESS_FILTER_H

#include "ip_address.h"
#include <algorithm>
#include <vector>

template <int T>
std::vector<IpAddress<T>> filter(const std::vector<IpAddress<T>> &src,
                                 const uint16_t &oct1) {
  std::vector<IpAddress<T>> out;
  std::copy_if(
      src.begin(), src.end(), std::back_inserter(out),
      [&oct1](IpAddress<T> ipAddress) { return ipAddress.isMatch(oct1); });

  return out;
};

template <int T>
std::vector<IpAddress<T>> filter(const std::vector<IpAddress<T>> &src,
                                 const uint16_t &oct1, const uint16_t &oct2) {
  std::vector<IpAddress<T>> out;
  std::copy_if(src.begin(), src.end(), std::back_inserter(out),
               [&oct1, &oct2](IpAddress<T> ipAddress) {
                 return ipAddress.isMatch(oct1, oct2);
               });

  return out;
};

template <int T>
std::vector<IpAddress<T>> filterAny(const std::vector<IpAddress<T>> &src,
                                    const uint16_t &oct) {
  std::vector<IpAddress<T>> out;
  std::copy_if(
      src.begin(), src.end(), std::back_inserter(out),
      [&oct](IpAddress<T> ipAddress) { return ipAddress.isMatchAny(oct); });

  return out;
}

#endif
