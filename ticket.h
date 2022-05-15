#pragma once
#include "performance.h"

const int INITIAL_CAPACITY = 128;

class Ticket : public Performance, public Hall{

private:
    unsigned int m_password;
    unsigned int m_rowNumber; 
    unsigned int m_seatNumber;

public:
    Date m_ticketDate;
    Performance m_performance;

    Ticket();

    void setPassword(const unsigned int password);
    void setDate(const Date& date);
    void setPerformance(const Performance& performance);
    void setRowAndSeat(unsigned int rowNumber, unsigned int seatNumber);

    Date getTicketDate(){ return m_ticketDate; }; 
    char* getTicketPerformanceName() { return m_performance.getPerformanceName(); };
    unsigned int getPassword(){ return m_password; };
    unsigned int getSeatNumber(){ return m_seatNumber; };
    
    void print();

};