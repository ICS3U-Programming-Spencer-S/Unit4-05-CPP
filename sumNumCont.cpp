// Copyright (c) 2022 Spencer Scarlett All rights reserved.
// .
// Created by: Spencer Scarlett
// Created on: Dec 4, 2022
//  Program that takes the users amount and numbers before adding to a sum

#include <iostream>
#include <string>

int main() {
    // Initializing variables
    int totalInt = 0, numInt, sumInt = 0, wait;
    std::string totalStr = "", numStr, sumStr;

    // Asks the user for the amount of numbers that will be entered
    std::cout << "Enter the amount of numbers to add: ";
    std::cin >> totalStr;
    std::cout << "\n";

    // Tries casting the total numbers to an integer
    try {
        totalInt = std::stoi(totalStr);
    } catch (const std::exception) {
        std::cout << "Inputs must be a positive integer only!";
        std::cout << "Please retry input: ";
        std::cin >> wait;
    }

    // If statement used to prevent invalid totalInt input
    if (totalInt > 0) {
        while (totalInt > 0) {
            // Asks the user for a number to add to sum
            std::cout << "Input a value to add to the sum: ";
            std::cin >> numStr;

            // Tries casting the number to an integer
            try {
                numInt = std::stoi(numStr);
            } catch (const std::exception) {
                std::cout << "Invalid input!";
                continue;
            }

            // Does not add '+' if last iteration
            if (totalInt == 1) {
                std::cout << "Added " << numInt << " to the sum.";
                sumStr += numStr + "\n";
                std::cout << sumStr << "\n";
                sumInt += numInt;
                totalInt--;
                continue;

                // if 0 is inputted, doesn't change amount left
            } else if (numInt == 0) {
                std::cout << "0 was added to the sum";
                continue;

                // for negative inputs
            } else if (numInt < 0) {
                std::cout << "Input must be a positive number";
                continue;

            } else {
                std::cout << "Added " << numInt << " to the sum.\n";
                sumStr += numStr + " + \n";
                std::cout << sumStr << " ";
                sumInt += numInt;
                totalInt--;
                continue;
            }
        }

    // if 0 is the numbers to add up to
    } else {
        std::cout << "Input must be greater then 0 to start\n";
        std::cout << "Please retry: ";
        std::cin >> wait;
    }

    // Displays sums and numbers to reach sum
    std::cout << sumStr << " = ";
    std::cout << sumInt << " ";
    std::cout << "Sum = " << sumInt << "\n";
}
