#include "hall.h"
#include <iostream>

Hall::Hall(){
    m_hallNumber = 0;
    m_rowsNumber = 0;
    m_seatesNumber = 0;
    m_availableSeaes = 0;
}

void Hall::setHallNumber(const unsigned int hallNumber){
    m_hallNumber = hallNumber;
}

void Hall::setRowsNumber(const unsigned int rowsNumber){
    m_rowsNumber = rowsNumber;
}

void Hall::setSeatesNumber(const unsigned int seatesNumber){
    m_seatesNumber = seatesNumber;
}

void Hall::setAvailableSeates(){
    m_availableSeaes = CAPACITY;
}

void Hall::printHall(){
    std::cout << "Hall number: " << m_hallNumber << "\n";
    std::cout << "Rows number: " << m_rowsNumber << "\n";
    std::cout << "Seates number: " << m_seatesNumber << "\n";
}
