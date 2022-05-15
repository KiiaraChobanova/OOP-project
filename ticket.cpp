#include "ticket.h"
#include <iostream>

Ticket::Ticket(){
    Date d;
    Performance p;
    m_password = 0;
    m_ticketDate = d;
    m_performance = p;
}

void Ticket::setPassword(const unsigned int password){
    m_password = password;
}

void Ticket::setDate(const Date& ticketDate){
    m_ticketDate = ticketDate;
}

void Ticket::setPerformance(const Performance& performance){
    m_performance = performance;
}

void Ticket::setRowAndSeat(unsigned int rowNumber, unsigned int seatNumber){
    m_rowNumber = rowNumber;
    m_seatNumber = seatNumber;
}

void Ticket::print(){
    //std::cout << "Ticket for: " << getPerformanceName() << " on " << getDate() <<std::endl;
    std::cout << "Password is: " << m_password << std::endl;
    std::cout << "There is: " << getAvailableSeates() << " available seates" << std::endl;
}
