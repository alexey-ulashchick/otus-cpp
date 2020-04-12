#include "filter.h"
#include "ip_address.h"

std::vector<IpAddress> filter(const std::vector<IpAddress> &src,
                              const unsigned char &oct1) {
  std::vector<IpAddress> out;
  std::copy_if(
      src.begin(), src.end(), std::back_inserter(out),
      [&oct1](IpAddress ipAddress) { return ipAddress.isMatch(oct1); });

  return out;
};

std::vector<IpAddress> filter(const std::vector<IpAddress> &src,
                              const unsigned char &oct1, const unsigned char &oct2) {
  std::vector<IpAddress> out;
  std::copy_if(
      src.begin(), src.end(), std::back_inserter(out),
      [&oct1, &oct2](IpAddress ipAddress) { return ipAddress.isMatch(oct1, oct2); });

  return out;
};

std::vector<IpAddress> filterAny(const std::vector<IpAddress> &src, const unsigned char &oct) {
  std::vector<IpAddress> out;
  std::copy_if(
      src.begin(), src.end(), std::back_inserter(out),
      [&oct](IpAddress ipAddress) { return ipAddress.isMatchAny(oct); });

  return out;
}
