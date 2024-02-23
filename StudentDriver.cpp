#include <iostream>
#include <fstream>
#include "Student.h"
#include "delim1.h" // Assume this is a part of your IOBuffer implementation
#include "buffile2.h"

void TestDelimitedFieldBuffer() {
    // Initialize a Student object with test data
    Student testStudent;
    testStudent.setIdentifier(123);
    testStudent.setFirstName("John");
    testStudent.setLastName("Doe");
    testStudent.setAddress("123 Main St");
    Date enrollmentDate;
    enrollmentDate.setDay(1);
    enrollmentDate.setMonth(1);
    enrollmentDate.setYear(2020);
    testStudent.setEnrollmentDate(enrollmentDate);
    testStudent.setCreditHoursCompleted(30);

    // Initialize a Delimited Field Buffer
    DelimFieldBuffer buffer('|', 1000); // Assuming '|' as a delimiter and a buffer size of 1000

    // Pack the student data into the buffer
    testStudent.Pack(buffer);

    // Write the buffer to a file
    BufferFile testFile(buffer);
    testFile.Create("student_data.txt", ios::out | ios::trunc);
    testFile.Write();

    // Read the data back into a buffer
    testFile.Open("student_data.txt", ios::in);
    testFile.Read();

    // Unpack the data into a new Student object
    Student unpackedStudent;
    unpackedStudent.Unpack(buffer);

    // Print both the original and unpacked Student data to verify

    // Assuming a Print method exists for the Student object
    // Previously assumed Print method calls are now replaced with:
    std::cout << "Original Student Data:\n" << testStudent << "\n";



    std::cout << "Unpacked Student Data:\n" << unpackedStudent << "\n";
}



int main() {
    TestDelimitedFieldBuffer();

    return 0;
}
