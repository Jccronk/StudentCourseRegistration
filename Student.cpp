/**
 * @file Student.cpp
 * @brief File for the implementation of the Student class
 */

#include "Student.h"
#include "Date.h"
#include <cstdlib> // For strtol
#include <cerrno> // For errno


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

bool Student::Pack(IOBuffer &buffer) const {
    buffer.Clear(); // Clear any existing content in the buffer
    // Convert identifier (int) to string and pack
    std::string identifierStr = std::to_string(this->identifier);
    if (buffer.Pack(identifierStr.c_str()) == -1) return false;
    if (buffer.Pack(this->firstName.c_str()) == -1) return false;
    if (buffer.Pack(this->lastName.c_str()) == -1) return false;
    if (buffer.Pack(this->address.c_str()) == -1) return false;

    // Constructing a date string from Date object
    std::string dateStr = std::to_string(this->enrollmentDate.getMonth()) + "/" +
                          std::to_string(this->enrollmentDate.getDay()) + "/" +
                          std::to_string(this->enrollmentDate.getYear());
    if (buffer.Pack(dateStr.c_str()) == -1) return false;

    std::string creditHoursCompletedStr = std::to_string(this->creditHoursCompleted);
    if (buffer.Pack(creditHoursCompletedStr.c_str()) == -1) return false;
    return true;
}

bool Student::Unpack(IOBuffer &buffer) {
    char buf[100]; // Adjust size based on expected maximum length of attributes
    char *end;
    // Unpack identifier from the buffer and convert to int
    if (buffer.Unpack(buf) == -1) return false;
    this->identifier = std::stoi(buf);
    if (buffer.Unpack(buf) == -1) return false;
    this->firstName = buf;
    if (buffer.Unpack(buf) == -1) return false;
    this->lastName = buf;
    if (buffer.Unpack(buf) == -1) return false;
    this->address = buf;

    // Unpack date string and reconstruct Date object
    if (buffer.Unpack(buf) == -1) return false;
    errno = 0; // Reset errno before conversion
    long month = strtol(buf, &end, 10);
    if (buf == end || errno != 0) return false; // Check conversion error
    long day = strtol(end + 1, &end, 10); // Skip delimiter
    if (*end != '/' || errno != 0) return false; // Check format and conversion error
    long year = strtol(end + 1, &end, 10); // Skip next delimiter
    if (*end != '\0' || errno != 0) return false; // Check for final conversion error

    this->enrollmentDate.setDay(static_cast<int>(day));
    this->enrollmentDate.setMonth(static_cast<int>(month));
    this->enrollmentDate.setYear(static_cast<int>(year));


    if (buffer.Unpack(buf) == -1) return false;
    this->creditHoursCompleted = std::stoi(buf);
    return true;
}



