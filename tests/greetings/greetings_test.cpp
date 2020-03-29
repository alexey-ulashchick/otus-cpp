#include "gtest/gtest.h"
#include "src/greetings/greetings.h"

TEST(greetings, basic)
{
    ASSERT_EQ(greetings(), "Hello World!");
}
