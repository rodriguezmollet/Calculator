/*
 *  File: Operations.cpp
 *  Created Date: Friday, November 29th 2024
 *  Author: Rodriguez M
 *  Email: <rodriguezmollet@outlook.com>
 */

#include "../Header Files/Operations.h"

namespace Operations
{
    double add(double numOne, double numTwo)
    {
        return numOne + numTwo;
    }

    double subtract(double numOne, double numTwo)
    {
        return numOne - numTwo;
    }

    double multiply(double numOne, double numTwo)
    {
        return numOne * numTwo;
    }

    double divide(double numOne, double numTwo) // NOLINT
    {
        return numOne / numTwo;
    }
} // namespace Operations