/**
 * @file CourseRegistration.h
 * @brief Contains the declaration of the CourseRegistration class for course registration management.
 */

#ifndef STUDENTCOURSEREGISTRATION_COURSEREGISTRATION_H
#define STUDENTCOURSEREGISTRATION_COURSEREGISTRATION_H

#include <iostream>
#include <string>

/**
 * @class CourseRegistration
 * @brief Represents a course registration record
 *
 * This class stores information about a course registration, including
 * course identifier, student id, number of credit hours, and the course grade
 */
class CourseRegistration {
public:
    std::string courseIdentifier;
    std::string studentIdentifier;
    int numberOfCreditHours;
    char courseGrade;

    // Constructors with default arguments
    CourseRegistration(const std::string& courseID = "", const std::string& studentID = "", int creditHours = 0, char grade = ' ');

    /**
     * @brief Input stream extraction operator for CourseRegistration objects
     *
     * This operator allows you to input a CourseRegistration object from an input stream
     * by reading course registration information.
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


#endif //STUDENTCOURSEREGISTRATION_COURSEREGISTRATION_H
