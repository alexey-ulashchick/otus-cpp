#include "src/ip_address/filter.h"
#include "src/ip_address/ip_address.h"
#include "gtest/gtest.h"

class FilterTest : public ::testing::Test {
protected:
  std::vector<IpAddress> pool_;

  virtual void SetUp() {
    IpAddress ipAddress1 = IpAddress::fromString("1.1.1.1");
    IpAddress ipAddress2 = IpAddress::fromString("2.1.1.1");
    IpAddress ipAddress3 = IpAddress::fromString("2.2.1.1");

    pool_ = {ipAddress1, ipAddress2, ipAddress3};
  }
};

TEST_F(FilterTest, FilterByFirstOctet) {
  std::vector<IpAddress> filteredPool = filter(pool_, 1);

  ASSERT_EQ(filteredPool.size(), 1);
  ASSERT_EQ(filteredPool.at(0), IpAddress::fromString("1.1.1.1"));
}

TEST_F(FilterTest, FilterByFirstAndSecondOctet) {
  std::vector<IpAddress> filteredPool = filter(pool_, 2, 2);

  ASSERT_EQ(filteredPool.size(), 1);
  ASSERT_EQ(filteredPool.at(0), IpAddress::fromString("2.2.1.1"));
}

TEST_F(FilterTest, FilterAny) {
  std::vector<IpAddress> filteredPool = filterAny(pool_, 2);

  ASSERT_EQ(filteredPool.size(), 2);
  ASSERT_EQ(filteredPool.at(0), IpAddress::fromString("2.1.1.1"));
  ASSERT_EQ(filteredPool.at(1), IpAddress::fromString("2.2.1.1"));
}
