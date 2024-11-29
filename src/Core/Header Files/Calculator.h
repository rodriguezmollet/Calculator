/*
 *  File: Calculator.h
 *  Created Date: Friday, November 29th 2024
 *  Author: Rodriguez M
 *  Email: <rodriguezmollet@outlook.com>
 */

#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <string_view>

namespace Calculator
{
    double getNumber(std::string_view prompt);
    char getOperator();
    void printResult(double numOne, double numTwo, char operation); // NOLINT
} // namespace Calculator

#endif // CALCULATOR_H