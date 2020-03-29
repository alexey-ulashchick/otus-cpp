#include "gtest/gtest.h"
#include "greetings.h"

TEST(greetings, basic)
{
    ASSERT_STREQ(greetings(), "Hello World!");
}
