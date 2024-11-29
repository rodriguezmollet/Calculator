/*
 *  File: Calculator.cpp
 *  Created Date: Friday, November 29th 2024
 *  Author: Rodriguez M
 *  Email: <rodriguezmollet@outlook.com>
 */

#include "../Header Files/Calculator.h"
#include "../Header Files/Operations.h"
#include <iostream>
#include <limits> // For numeric_limits
#include <string_view>

namespace Calculator
{
    /*
        To ignore everything up to and including the next ‘\n’ character
    */
    void ignoreLine()
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    /*
        Checks if there is any unprocessed input remaining in 'std::cin' on the current line,
        excluding the newline character.

        Returns:
            true  - if there is extra input on the current line.
            false - if there is no extra input or if EOF has been reached.

        Note:
            - The function first checks '!std::cin.eof()' to ensure EOF has not been reached
                before calling 'std::cin.peek()'.
            - 'std::cin.peek()' looks at the next character without extracting it.
            - If the next character is not '\n', it means there is unextracted input remaining.
    */
    bool hasUnextractedInput()
    {
        return !std::cin.eof() && std::cin.peek() != '\n';
    }

    /*
        Returns true if extraction failed, false otherwise
    */
    bool clearFailedExtraction()
    {
        // If the previous extraction failed or if std::cin has unextracted input in the buffer
        if (!(std::cin) || hasUnextractedInput())
        {
            // If the user entered an EOF (end-of-file) character
            if (std::cin.eof())
            {
                std::cout << "\nUser enter an EOF character. Shutting down the program now\n";
                std::exit(0); // NOLINT
            }

            // Puts std::cin back in normal operation mode so that we can try to extract input
            // again. It clears any error flags that have been set inside std::cin.
            std::cin.clear();
            // Remove the bad input from the stream
            ignoreLine();

            return true;
        }

        return false;
    }

    double getNumber(std::string_view prompt)
    {
        // Loop until user enters a valid input
        while (true)
        {
            std::cout << prompt;
            double number {};
            std::cin >> number;

            if (clearFailedExtraction())
            {
                std::cout << "Oops, that input is invalid. Please try again.\n";
                continue;
            }

            // Our extraction succeeded. Remove any additional extraneous input
            ignoreLine();

            // Return the value we extracted
            return number;
        }
    }

    char getOperator()
    {
        // Loop until user enters a valid input
        while (true)
        {
            std::cout << "\nEnter a mathematical operator (+, -, *, or /): ";
            char operation {};
            std::cin >> operation;

            if (clearFailedExtraction())
            {
                std::cout << "Oops, that input is invalid. Please try again.\n";
                continue;
            }

            // Our extraction succeeded. Remove any additional extraneous input
            ignoreLine();

            switch (operation)
            {
                case '+':
                case '-':
                case '*':
                case '/':
                    // Return the entered char to the caller
                    return operation;
                // Otherwise tell the user what went wrong
                default:
                    std::cout << "Oops, that input is invalid. Please try again.\n";
            }
        }
    }

    void printResult(double numOne, double numTwo, char operation) // NOLINT
    {
        std::cout << numOne << ' ' << operation << ' ' << numTwo << " = ";

        switch (operation) // NOLINT
        {
            case '+':
                std::cout << Operations::add(numOne, numTwo) << '\n';
                return;
            case '-':
                std::cout << Operations::subtract(numOne, numTwo) << '\n';
                return;
            case '*':
                std::cout << Operations::multiply(numOne, numTwo) << '\n';
                return;
            case '/':
                if (numTwo == 0.0)
                {
                    std::cout << "Division by zero is not allowed.\n";
                    return;
                }

                std::cout << Operations::divide(numOne, numTwo) << '\n';
                return;
        }
    }
} // namespace Calculator