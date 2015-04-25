#include "../Inc/gtest/gtest.h"
#include <iostream>

using namespace std;

void init()
{
}

void deinit()
{
}

class UnitTest : public testing::Test
{
};

TEST_F(UnitTest, true)
{
    EXPECT_TRUE(true);
}

TEST_F(UnitTest, double)
{
    EXPECT_DOUBLE_EQ(3.0, 3.0);
}

int main (int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    int returnValue;
    init();
    returnValue = RUN_ALL_TESTS();
    deinit();
    return returnValue;
}
