#pragma once
#include "performance.h"
#include "ticket.h"

const unsigned int INITIAL_SYSTEM_CAPACITY = 2;
const unsigned int INITIAL_TICKETS_CAPACITY = 2;
const unsigned int SYSTEM_INCREASE_STEP = 2;
const unsigned int TICKETS_INCREASE_STEP = 2;

class System : public Performance {

private:
    Performance* m_performances;
    Date* m_dates;
    Ticket* m_freeTickets;
    Ticket* m_reservedTickets;
    Ticket* m_boughtTickets;

    unsigned int m_ticketsCapacity;
    unsigned int m_systemCapcity;
    unsigned int m_performancesNumber;
    unsigned int m_datesNumber;
    unsigned int m_freeTicketsNumber;
    unsigned int m_reservedTicketsNumber;
    unsigned int m_boughtTicketsNumber;

    void resizeFreeTickets();
    void resizeReservedTickets();
    void resizeBoughtTickets();
    void resizePerformances();
    void resizeDates();

    void copy(const System& other);
    void erase();
    bool isFreeSeat(unsigned int seat);

public:
    System();
    System(const System& other);
    ~System();
    System& operator=(const System& other);

    unsigned int getPefomanceIndex(char* performanceName);
    unsigned int getDateIndex(unsigned int day, unsigned int month, unsigned int year);
    unsigned int getFreeTicketIndex(unsigned int password);
    unsigned int getReservedTicketIndex(unsigned int password);
    unsigned int getBoughtTicketIndex(unsigned int password);


    void addNewPeformance(const Date& date, const char* name, Hall& hall);
    void addReservedTicket(const Ticket& reservedTikcet);
    void addFreeTicket(const Ticket& freeTikcet);
    void addBoughtTicket(const Ticket& boughtTikcet);

    void removeFreeTicket(unsigned int password);
    void removeReservedTicket(unsigned int password);

    void checkDate(const Date& date);
    void freeSetes(Performance& performance);
    void makeReservation(char* name, Date& date); 
    void cancelReservation(Ticket& ticket);
    void buyTicket(Ticket& ticket); 

    unsigned int getAvailableTickets();

    void printInfo(Date& startingDate, Date& endDate, Hall& hall);

};