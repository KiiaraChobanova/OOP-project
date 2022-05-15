#pragma once
#include "date.h"
#include "hall.h"
#include "Helper.h"
#include <cstring>

class Performance {

private:
    Date m_date;
    char* m_performanceName;
    Hall m_hall;

    void copyPerformance(const Performance& other);
    void erase();

public:
    Performance();
    Performance(const Performance& other);
    ~Performance();

    void setPerformanceDate(const Date& date);
    void setPerformanceName(const char* performanceName);
    void setPerformanceHall(const Hall& hall);

    Date getPerformanceDate() const { return m_date; };
    Hall getPerformanceHall() const { return m_hall; };
    char* getPerformanceName() const { return m_performanceName; }; 
    unsigned int getAvailableSeatesForPerformance();
    void printPerformance();
};