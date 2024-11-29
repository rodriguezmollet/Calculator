/*
 *  File: OperationsTest.cpp
 *  Created Date: Friday, November 29th 2024
 *  Author: Rodriguez M
 *  Email: <rodriguezmollet@outlook.com>
 */

#include "../Header Files/Operations.h"
#include <gtest/gtest.h>

namespace Operations
{
    /*
        Unit test for the add function
    */
    TEST(Operations, Add) // NOLINT
    {
        EXPECT_DOUBLE_EQ(add(2.0, 3.0), 5.0);
        EXPECT_DOUBLE_EQ(add(-2.0, 3.0), 1.0);
        EXPECT_DOUBLE_EQ(add(0.0, 0.0), 0.0);
    }

    /*
        Unit test for the subtract function
    */
    TEST(Operations, Subtract) // NOLINT
    {
        EXPECT_DOUBLE_EQ(subtract(5.0, 3.0), 2.0);
        EXPECT_DOUBLE_EQ(subtract(2.0, 5.0), -3.0);
        EXPECT_DOUBLE_EQ(subtract(0.0, 0.0), 0.0);
    }

    /*
        Unit test for the multiply function
    */
    TEST(Operations, Multiply) // NOLINT
    {
        EXPECT_DOUBLE_EQ(multiply(2.0, 3.0), 6.0);
        EXPECT_DOUBLE_EQ(multiply(-2.0, 3.0), -6.0);
        EXPECT_DOUBLE_EQ(multiply(0.0, 3.0), 0.0);
    }

    /*
        Unit test for the divide function
    */
    TEST(Operations, Divide) // NOLINT
    {
        EXPECT_DOUBLE_EQ(divide(6.0, 3.0), 2.0);
        EXPECT_DOUBLE_EQ(divide(-6.0, 3.0), -2.0);
        EXPECT_DOUBLE_EQ(divide(5.0, 2.0), 2.5);
    }
} // namespace Operations

auto main(int argc, char** argv) -> int
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}