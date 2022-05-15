#pragma once
#include <cassert>
#include <iostream>
#include <fstream>

const unsigned int MONTH_DAYS[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date{

private:
    unsigned int m_day;
    unsigned int m_month;
    unsigned int m_year;

public:
    Date();
    Date(unsigned int day, unsigned int month, unsigned int year);
    bool isLeap(unsigned int year);

    unsigned int getDay(){ return m_day; };
    unsigned int getMonth(){ return m_month; };
    unsigned int getYear(){ return m_year; };
     
    void printDate();
    bool operator==(const Date& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Date& date);
    
};