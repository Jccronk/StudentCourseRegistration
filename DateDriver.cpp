/**
 * @file DateDriver.cpp
 * @brief Contains test function for the implementation of the Date class
 */

#include <iostream>
#include "Date.h"

int main() {
    Date date1, date2;

    std::cout << "Enter details for date1:" << std::endl;
    std::cin >> date1;

    std::cout << "Enter details for date2:" << std::endl;
    std::cin >> date2;

    std::cout << "Date 1: " << date1 << std::endl;
    std::cout << "Date 2: " << date2 << std::endl;

    if (date1 < date2)
        std::cout << "Date 1 is earlier than Date 2" << std::endl;
    else if (date1 == date2)
        std::cout << "Date 1 is equal to Date 2" << std::endl;
    else
        std::cout << "Date 1 is later than Date 2" << std::endl;

    return 0;
}
