/*
 *  File: CalculatorApp.cpp
 *  Created Date: Friday, November 29th 2024
 *  Author: Rodriguez M
 *  Email: <rodriguezmollet@outlook.com>
 */

#include "../Core/Header Files/Calculator.h"
#include <iostream>

int main()
{
    std::cout << "*** Calculator ***\n\n";

    double numOne {Calculator::getNumber("Enter the first number: ")};
    double numTwo {Calculator::getNumber("Enter the second number: ")};
    char operation {Calculator::getOperator()};

    std::cout << '\n';
    Calculator::printResult(numOne, numTwo, operation);

    return 0;
}