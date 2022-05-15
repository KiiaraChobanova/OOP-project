#include "date.h"
#include "Helper.h"

Date::Date(){
    m_day = 0;
    m_month = 0;
    m_year = 0;
}

Date::Date(unsigned int day, unsigned int month, unsigned int year){
    assert(month > 0 && month <= 12);
    assert(day > 0 && day <= MONTH_DAYS[month - 1] + (month == 2 && isLeap(year)));

    m_day = day;
    m_month = month;
    m_year = year;
}

bool Date::isLeap(unsigned int year){
    return ((year % 400 == 0) && (year % 4 == 0) || !(year % 100 == 0));
}

void Date::printDate(){
    std::cout << m_day << m_month << m_year;
}

bool Date::operator==(const Date &other) const{
    return (m_year == other.m_year && m_month == other.m_month && m_day == other.m_day);
}

std::ostream& operator<<(std::ostream& os, const Date& date)
{
    os << date.m_day << '/' << date.m_month << '/' << date.m_year;
    return os;
}