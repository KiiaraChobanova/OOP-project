#include "performance.h"

Performance::Performance(){
    Date d;
    Hall h;
    m_date = d;
    m_hall = h;
    m_performanceName = copyDynStr("N/A");
}

void Performance::copyPerformance(const Performance& other){
    m_performanceName = new (std::nothrow) char [strlen(other.m_performanceName) + 1];
        if(!m_performanceName){
            std::cout << "Memory problem!";
            return;
        }
    strcpy(m_performanceName, other.m_performanceName);
}

void Performance::erase(){
    delete[] m_performanceName;
}

Performance::Performance(const Performance& other){
    copyPerformance(other);
}

Performance::~Performance(){
    erase();
}

void Performance::setPerformanceDate(const Date& date){
    m_date = date;
}

void Performance::setPerformanceName(const char* performanceName){
    m_performanceName = copyDynStr(performanceName); 
}

void Performance::setPerformanceHall(const Hall& hall){
    m_hall = hall;
}

unsigned int Performance::getAvailableSeatesForPerformance(){
    return m_hall.getAvailableSeates();
}

void Performance::printPerformance(){
    std::cout << "Perfomance is: "; 
    std::cout << getPerformanceName();
    std::cout << getPerformanceDate();
    m_hall.printHall();
}