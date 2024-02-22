/**
 * @file CourseRegistrationDriver.cpp
 * @brief Tests the CourseRegistration class
 *
 * Prompts the user to enter the number of course registrations and then
 * collects information for each. It creates CourseRegistration objects
 * based on user input and writes the registration data to a file named 'course_registration_data.txt'.
 * The user can end the input process for course IDs by pressing Enter without typing.
 */

#include <iostream>
#include <fstream> // Include the file stream library
#include "CourseRegistration.h"
#include <limits>

int main() {
    int numRegistrations;
    std::cout << "Enter the number of course registrations: ";
    std::cin >> numRegistrations;

    // Consume the newline character left in the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Create an output file stream
    std::ofstream outputFile("course_registration_data.txt");

    for (int i = 0; i < numRegistrations; ++i) {
        CourseRegistration courseReg;
        std::cout << "Enter course ID, or <cr> to end: ";
        std::getline(std::cin, courseReg.courseIdentifier);

        if (courseReg.courseIdentifier.empty()) {
            break; // Break if the course ID is empty (user pressed Enter)
        }

        std::cout << "Enter student ID: ";
        std::getline(std::cin, courseReg.studentIdentifier);

        std::cout << "Enter number of credit hours: ";
        std::cin >> courseReg.numberOfCreditHours;

        std::cout << "Enter course grade: ";
        std::cin >> courseReg.courseGrade;

        // Clear the input buffer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        outputFile << courseReg; // Write course registration data to the file
    }

    // Close the output file stream
    outputFile.close();

    std::cout << "Course registration data has been written to 'course_registration_data.txt'" << std::endl;

    return 0;
}
