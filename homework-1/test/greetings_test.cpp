#include "gtest/gtest.h"
#include "greetings.h"

TEST(greetings, basic)
{
    ASSERT_EQ(greetings(), "Hello World!");
}
