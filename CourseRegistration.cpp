/**
 * @file CourseRegistration.cpp
 * @brief Contains the CourseRegistration class and related functions for course registration management.
 */

#include <iostream>
#include <string>
#include "Date.h"
#include <limits>

/**
 * @brief Class representing a course registration record.
 *
 * `CourseRegistration` class stores information about a course registration
 * including  course identifier, student id, number of credit hours, and
 * course grade
 */
class CourseRegistration {
public:
    std::string courseIdentifier; /**< Course identifier */
    std::string studentIdentifier; /**< Student identifier */
    int numberOfCreditHours; /**< Number of credit hours */
    char courseGrade; /**< Course grade */

    /**
    * @brief Default Constructor for the CourseRegistration class
    *
    * @param courseID  course identifier (default is an empty string)
    * @param studentID  student identifier (default is an empty string)
    * @param creditHours  number of credit hours (default is 0)
    * @param grade  course grade (default is a space character)
    */
    CourseRegistration(const std::string& courseID = "", const std::string& studentID = "", int creditHours = 0, char grade = ' ');

    /**
     * @brief Input stream extraction operator for CourseRegistration objects
     *
     * input a CourseRegistration object from an input stream
     * by reading course registration information
     *
     * @param input The input stream to read from
     * @param courseReg The CourseRegistration object to populate with input values
     * @return The input stream (input) after reading the CourseRegistration
     */
    friend std::istream& operator>>(std::istream& input, CourseRegistration& courseReg);

    /**
     * @brief Output stream insertion operator for CourseRegistration objects
     *
     * This operator allows you to output a CourseRegistration object to an output stream
     * by printing course registration information.
     *
     * @param output The output stream to write to
     * @param courseReg The CourseRegistration object to output
     * @return The output stream (output) after writing the CourseRegistration
     */
    friend std::ostream& operator<<(std::ostream& output, const CourseRegistration& courseReg);
};

// Constructor
CourseRegistration::CourseRegistration(const std::string& courseID, const std::string& studentID, int creditHours, char grade)
        : courseIdentifier(courseID), studentIdentifier(studentID), numberOfCreditHours(creditHours), courseGrade(grade) {}

/**
 * @brief Input stream extraction operator for CourseRegistration objects
 *
 * input a CourseRegistration object from an input stream
 * by reading course registration information
 *
 * @param input The input stream to read from
 * @param courseReg The CourseRegistration object to make with input values
 * @return The input stream (input) after reading the CourseRegistration
 */
std::istream& operator>>(std::istream& input, CourseRegistration& courseReg) {
    std::cout << "Enter course ID, or <cr> to end: ";
    std::getline(input, courseReg.courseIdentifier);

    std::cout << "Enter student ID: ";
    std::getline(input, courseReg.studentIdentifier);

    std::cout << "Enter number of credit hours: ";
    input >> courseReg.numberOfCreditHours;

    std::cout << "Enter course grade: ";
    input >> courseReg.courseGrade;

    // Clear the input buffer
    input.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return input;
}

/**
 * @brief Output stream insertion operator for CourseRegistration objects
 *
 * output a CourseRegistration object to an output stream
 * by printing course registration information
 *
 * @param output The output stream to write to
 * @param courseReg The CourseRegistration object to output
 * @return The output stream (output) after writing the CourseRegistration
 */
std::ostream& operator<<(std::ostream& output, const CourseRegistration& courseReg) {
    output << courseReg.courseIdentifier << "\n"
           << courseReg.studentIdentifier << "\n"
           << courseReg.numberOfCreditHours << "\n"
           << courseReg.courseGrade << "\n";
    return output;
}
