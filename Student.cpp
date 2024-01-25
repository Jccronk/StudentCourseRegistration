/**
 * @file Student.cpp
 * @brief File for the implementation of the Student class
 */

#include "Student.h"

/**
 * @brief Constructor for the Student class.
 *
 * This constructor initializes a Student object with the specified attributes.
 *
 * @param id The student id
 * @param first The first name of the student
 * @param last The last name of the student
 * @param addr The address of the student
 * @param date The enrollment date of the student (a Date object)
 * @param credits The number of credit hours completed by the student
 */
Student::Student(int id, const std::string& first, const std::string& last, const std::string& addr,
                 const Date& date, int credits) {
    identifier = id;
    firstName = first;
    lastName = last;
    address = addr;
    enrollmentDate = date;
    creditHoursCompleted = credits;
}

int Student::getIdentifier() const {
    return identifier;
}

void Student::setIdentifier(int id) {
    identifier = id;
}

const std::string& Student::getFirstName() const {
    return firstName;
}

void Student::setFirstName(const std::string& first) {
    firstName = first;
}

const std::string& Student::getLastName() const {
    return lastName;
}

void Student::setLastName(const std::string& last) {
    lastName = last;
}

const std::string& Student::getAddress() const {
    return address;
}

void Student::setAddress(const std::string& addr) {
    address = addr;
}

const Date& Student::getEnrollmentDate() const {
    return enrollmentDate;
}

void Student::setEnrollmentDate(const Date& date) {
    enrollmentDate = date;
}

int Student::getCreditHoursCompleted() const {
    return creditHoursCompleted;
}

void Student::setCreditHoursCompleted(int credits) {
    creditHoursCompleted = credits;
}



/**
 * @brief Input stream extraction operator for Student objects
 *
 * input a Student object from an input stream by
 * prompting the user to enter attributes of the student
 *
 * @param in The input stream to read from
 * @param student The Student object to populate with input values
 * @return The input stream (in) after reading the Student
 */
std::istream& operator>>(std::istream& in, Student& student) {
    std::cout << "Enter student ID, or <cr> to end:";
    in >> student.identifier;

    std::cout << "Enter first name:";
    in.ignore(); // Clear the newline character from the previous input
    std::getline(in, student.firstName);

    std::cout << "Enter last name:";
    std::getline(in, student.lastName);

    std::cout << "Enter address:";
    std::getline(in, student.address);

    std::cout << "Enter the date of first enrollment:" << std::endl;
    in >> student.enrollmentDate;

    std::cout << "Enter the number of credit hours completed:";
    in >> student.creditHoursCompleted;

    return in;
}


/**
 * @brief Output stream insertion operator for Student objects
 *
 * output a Student object to an output stream by
 * printing attributes of the student
 *
 * @param out The output stream to write to
 * @param student The Student object to output
 * @return The output stream (out) after writing the Student
 */
std::ostream& operator<<(std::ostream& out, const Student& student) {
    out << student.getIdentifier() << std::endl;
    out << student.getFirstName() << " " << student.getLastName() << std::endl;
    out << student.getAddress() << std::endl;
    out << student.getEnrollmentDate() << std::endl;
    out << student.getCreditHoursCompleted() << std::endl;

    return out;
}

