
cmake_minimum_required(VERSION 3.27)
project(StudentCourseRegistration)

set(CMAKE_CXX_STANDARD 17)

# Executable for DateDriver.cpp
add_executable(DateTest Date.cpp DateDriver.cpp)

# Executable for StudentDriver.cpp
add_executable(StudentTest Student.cpp StudentDriver.cpp Date.cpp)

# Executable for CourseRegistrationDriver.cpp
add_executable(CourseRegistrationTest CourseRegistration.cpp CourseRegistrationDriver.cpp)



