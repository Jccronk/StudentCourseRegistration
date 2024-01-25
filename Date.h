/**
 * @file Date.h
 * @brief Header file for the implementation of the Date class
 */

#ifndef STUDENTCOURSEREGISTRATION_DATE_H
#define STUDENTCOURSEREGISTRATION_DATE_H

#include <iostream>

/**
 * @brief Class representing a calendar date.
 */
class Date {
private:
    int day;   ///< Day of the month
    int month; ///< Month of the year
    int year;  ///< Year

public:
    /**
     * @brief Construct a new Date object with default values or provided values.
     * @param day The day of the month (default is 1).
     * @param month The month of the year (default is 1).
     * @param year The year (default is 2000).
     */
    Date(int day = 1, int month = 1, int year = 2000);

    /**
     * @brief Get the Day of the month.
     * @return int Day of the month.
     */
    int getDay() const;

    /**
     * @brief Get the Month of the year.
     * @return int Month of the year.
     */
    int getMonth() const;

    /**
     * @brief Get the Year.
     * @return int Year.
     */
    int getYear() const;

    /**
     * @brief Set the Day of the month.
     * @param day Day of the month.
     */
    void setDay(int day);

    /**
     * @brief Set the Month of the year.
     * @param month Month of the year.
     */
    void setMonth(int month);

    /**
     * @brief Set the Year.
     * @param year Year.
     */
    void setYear(int year);

    /**
     * @brief Compare this Date with another Date to determine if it is earlier.
     * @param other The other Date to compare to.
     * @return bool True if this Date is earlier than the other Date, false otherwise.
     */
    bool operator<(const Date& other) const;

    /**
     * @brief Compare two Date objects for equality.
     * This operator compares two Date objects and returns true if they are equal.
     * @param other The Date object to compare with.
     * @return True if the two Date objects are equal and false otherwise.
     */
    bool operator==(const Date& other) const;

    /**
     * @brief Compare two Date objects for greater-than comparison.
     * This operator compares two Date objects and returns true if the current Date
     * is greater than the other Date, based on the year, month, and day.
     * @param other The Date object to compare with.
     * @return True if the current Date is greater than the other Date and false otherwise.
     */
    bool operator>(const Date& other) const;

    friend std::istream& operator>>(std::istream& in, Date& date);

    friend std::ostream& operator<<(std::ostream& out, const Date& date);

};

#endif //STUDENTCOURSEREGISTRATION_DATE_H
