
cmake_minimum_required(VERSION 3.27)
project(StudentCourseRegistration)

set(CMAKE_CXX_STANDARD 17)



# Executable for StudentDriver.cpp
add_executable(StudentTest Student.cpp Date.cpp StudentDriver.cpp
        buffile2.cpp
        delim1.cpp
        iobuffer1.cpp
        varlen1.cpp
        fixlen1.cpp)

# Executable for CourseRegistrationDriver.cpp
add_executable(CourseRegistrationTest CourseRegistration.cpp CourseRegistrationDriver.cpp)



