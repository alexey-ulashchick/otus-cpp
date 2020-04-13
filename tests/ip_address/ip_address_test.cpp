#include "src/ip_address/ip_address.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

TEST(IpAddress, BasicBuilderAndStringOutput) {
  IpAddress ipAddress = IpAddress::fromString("1.1.1.1");
  std::ostringstream out;

  out << ipAddress;

  ASSERT_EQ("1.1.1.1", out.str());
}

TEST(IpAddress, ReversedComparator) {
  IpAddress ipAddress1 = IpAddress::fromString("1.1.1.1");
  IpAddress ipAddress2 = IpAddress::fromString("1.2.1.1");

  ASSERT_LT(ipAddress2, ipAddress1);
}

TEST(IpAddress, Equality) {
  IpAddress ipAddress1 = IpAddress::fromString("1.2.4.5");
  IpAddress ipAddress2 = IpAddress::fromString("1.2.4.5");

  ASSERT_EQ(ipAddress1, ipAddress2);
}

TEST(IpAddress, isMatchFirstOctet) {
  IpAddress ipAddress = IpAddress::fromString("1.2.3.4");

  ASSERT_TRUE(ipAddress.isMatch(1));
  ASSERT_FALSE(ipAddress.isMatch(2));
}

TEST(IpAddress, isMatchSecondOctet) {
  IpAddress ipAddress = IpAddress::fromString("1.2.3.4");

  ASSERT_TRUE(ipAddress.isMatch(1, 2));
  ASSERT_FALSE(ipAddress.isMatch(2, 1));
}

TEST(IpAddress, isMatchAnyOctet) {
  IpAddress ipAddress = IpAddress::fromString("1.2.3.4");

  ASSERT_TRUE(ipAddress.isMatchAny(1));
  ASSERT_TRUE(ipAddress.isMatchAny(2));
  ASSERT_TRUE(ipAddress.isMatchAny(3));
  ASSERT_TRUE(ipAddress.isMatchAny(4));
  ASSERT_FALSE(ipAddress.isMatchAny(5));
}
