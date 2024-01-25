/**
 * @file StudentDriver.cpp
 * @brief Contains test function for the implementation of the Student class
 */

#include <iostream>
#include <fstream> // Include the file stream library
#include "Student.h"

/**
 * @brief Tests the Student class.
 *
 * This function asks the user to input the number of students and then
 * iterates to collect information for each student. It creates Student objects
 * based on user input and writes the student data to a file named 'student_data.txt'.
 */
int main() {
    int numStudents;
    std::cout << "Enter the number of students: ";
    std::cin >> numStudents;

    // Create an output file stream
    std::ofstream outputFile("student_data.txt");

    for (int i = 0; i < numStudents; ++i) {
        Student student;
        std::cout << "Enter details for student " << i + 1 << ":" << std::endl;
        std::cin >> student;
        outputFile << student; // Write student data to the file
    }

    // Close the output file stream
    outputFile.close();

    std::cout << "Student data has been written to 'student_data.txt'" << std::endl;

    return 0;
}