/**
 * @file Student.h
 * @brief Header file for the implementation of the Student class
 */

#ifndef STUDENTCOURSEREGISTRATION_STUDENT_H
#define STUDENTCOURSEREGISTRATION_STUDENT_H

#include <iostream>
#include "Date.h"

class Student {
private:
    int identifier;
    std::string firstName;
    std::string lastName;
    std::string address;
    Date enrollmentDate;
    int creditHoursCompleted;

public:
    /**
 * @brief Constructor for the Student class
 *
 * Initializes a new Student object with optional parameters for the student's details
 * If no arguments are provided, default values are used
 *
 * @param id The student's unique id number. Default is 0
 * @param first The student's first name. Default is an empty string
 * @param last The student's last name. Default is an empty string
 * @param addr The student's address. Default is an empty string
 * @param date The student's birthday. Default is a default-constructed Date object
 * @param credits The number of credits the student has earned. Default is 0
 */
    Student(int id = 0, const std::string& first = "", const std::string& last = "", const std::string& addr = "",
            const Date& date = Date(), int credits = 0);

    // Getter and Setter methods
    int getIdentifier() const;
    void setIdentifier(int id);
    const std::string& getFirstName() const;
    void setFirstName(const std::string& first);
    const std::string& getLastName() const;
    void setLastName(const std::string& last);
    const std::string& getAddress() const;
    void setAddress(const std::string& addr);
    const Date& getEnrollmentDate() const;
    void setEnrollmentDate(const Date& date);
    int getCreditHoursCompleted() const;
    void setCreditHoursCompleted(int credits);

    // Input and Output operators
    friend std::istream& operator>>(std::istream& in, Student& student);
    friend std::ostream& operator<<(std::ostream& out, const Student& student);
};


#endif //STUDENTCOURSEREGISTRATION_STUDENT_H
