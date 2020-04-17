#include "src/ip_address/ip_address.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>
#include <array>
#include <stdexcept>

TEST(IpAddress, BasicBuilderAndStringOutputV4) {
  auto ipAddress = IpAddress<4>::fromString("127.0.0.1");
  std::ostringstream out;

  out << ipAddress;

  ASSERT_EQ("127.0.0.1", out.str());
}

TEST(IpAddress, ThrowExceptionWhenInvalidIpProvided) {
  ASSERT_THROW(IpAddress<4>::fromString("-127.0.0.1"), std::invalid_argument);
  ASSERT_THROW(IpAddress<4>::fromString("127.0.1"), std::invalid_argument);
  ASSERT_THROW(IpAddress<4>::fromString("127.0.0.0.1"), std::invalid_argument);
  ASSERT_THROW(IpAddress<4>::fromString("tro.x.y.z"), std::invalid_argument);
}

TEST(IpAddress, ReversedComparator) {
  auto ipAddress1 = IpAddress<4>::fromString("1.1.1.1");
  auto ipAddress2 = IpAddress<4>::fromString("1.2.1.1");

  ASSERT_LT(ipAddress2, ipAddress1);
}

TEST(IpAddress, Equality) {
  auto ipAddress1 = IpAddress<4>::fromString("1.2.4.5");
  auto ipAddress2 = IpAddress<4>::fromString("1.2.4.5");

  ASSERT_EQ(ipAddress1, ipAddress2);
}

TEST(IpAddress, isMatchFirstOctet) {
  auto ipAddress = IpAddress<4>::fromString("1.2.3.4");

  ASSERT_TRUE(ipAddress.isMatch(1));
  ASSERT_FALSE(ipAddress.isMatch(2));
}

TEST(IpAddress, isMatchSecondOctet) {
  auto ipAddress = IpAddress<4>::fromString("1.2.3.4");

  ASSERT_TRUE(ipAddress.isMatch(1, 2));
  ASSERT_FALSE(ipAddress.isMatch(2, 1));
}

TEST(IpAddress, isMatchAnyOctet) {
  auto ipAddress = IpAddress<4>::fromString("1.2.3.4");

  ASSERT_TRUE(ipAddress.isMatchAny(1));
  ASSERT_TRUE(ipAddress.isMatchAny(2));
  ASSERT_TRUE(ipAddress.isMatchAny(3));
  ASSERT_TRUE(ipAddress.isMatchAny(4));
  ASSERT_FALSE(ipAddress.isMatchAny(5));
}
