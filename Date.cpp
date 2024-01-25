/**
 * @file Date.cpp
 * @brief Contains the implementation of the Date class
 */

#include "Date.h"

/**
 * @brief Constructor for the Date class.
 *
 * This constructor initializes a Date object with the specified day, month, and year.
 *
 * @param day The day of the date.
 * @param month The month of the date.
 * @param year The year of the date.
 */
Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

/**
 * @brief Get the Day of the month.
 * @return int Day of the month.
 */
int Date::getDay() const {
    return day;
}

/**
 * @brief Get the Month of the year.
 * @return int Month of the year.
 */
int Date::getMonth() const {
    return month;
}

/**
 * @brief Get the Year.
 * @return int Year.
 */
int Date::getYear() const {
    return year;
}

/**
 * @brief Set the Day of the month.
 * @param day Day of the month.
 */
void Date::setDay(int day) {
    this->day = day;
}

/**
 * @brief Set the Month of the year.
 * @param month Month of the year.
 */
void Date::setMonth(int month) {
    this->month = month;
}

/**
 * @brief Set the Year.
 * @param year Year.
 */
void Date::setYear(int year) {
    this->year = year;
}


/**
 * @brief Compare two Date objects for less-than comparison.
 *
 * This operator compares two Date objects and returns true if the current Date
 * is less than the other Date, based on the year, month, and day components.
 *
 * @param other The Date object to compare with.
 * @return True if the current Date is less than the other Date; false otherwise.
 */
bool Date::operator<(const Date& other) const {
    if (year < other.year)
        return true;
    else if (year > other.year)
        return false;
    else if (month < other.month)
        return true;
    else if (month > other.month)
        return false;
    else
        return day < other.day;
}

/**
 * @brief Compare two Date objects for equality.
 *
 * This operator compares two Date objects and returns true if they are equal
 *
 * @param other The Date object to compare with.
 * @return True if the two Date objects are equal and false otherwise
 */
bool Date::operator==(const Date& other) const {
    return (day == other.day) && (month == other.month) && (year == other.year);
}

/**
 * @brief Compare two Date objects for greater-than comparison
 *
 * This operator compares two Date objects and returns true if the current Date
 * is greater than the other Date, based on the year, month, and day
 *
 * @param other The Date object to compare with
 * @return True if the current Date is greater than the other Date and false otherwise
 */
bool Date::operator>(const Date& other) const {
    return !(*this < other) && !(*this == other);
}


/**
 * @brief Input stream extraction operator for Date objects
 *
 * input a Date object from an input stream. prompts
 * the user to enter the day, month, and year  of the date
 *
 * @param in The input stream to read from
 * @param date The Date object to populate with input values
 * @return The input stream (in) after reading the Date
 */
std::istream& operator>>(std::istream& in, Date& date) {
    int day, month, year;
    std::cout << "Enter day, or <cr> to end:";
    in >> day;

    std::cout << "Enter month:";
    in >> month;

    std::cout << "Enter year:";
    in >> year;

    date.setDay(day);
    date.setMonth(month);
    date.setYear(year);

    return in;
}

/**
 * @brief Output stream insertion operator for Date objects
 *
 * output a Date object to an output stream in the
 * format "month/day/year"
 *
 * @param out The output stream to write to
 * @param date The Date object to output
 * @return The output stream (out) after writing the Date
 */
std::ostream& operator<<(std::ostream& out, const Date& date) {
    out << date.getMonth() << "/" << date.getDay() << "/" << date.getYear();
    return out;
}