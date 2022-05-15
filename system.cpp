#include "system.h"

System::System(){

    m_ticketsCapacity = INITIAL_TICKETS_CAPACITY;
    m_systemCapcity = INITIAL_SYSTEM_CAPACITY;

    m_performancesNumber = 0;
    m_datesNumber = 0;
    m_freeTicketsNumber = m_ticketsCapacity;
    m_reservedTicketsNumber = 0;
    m_boughtTicketsNumber = 0;

    m_performances = new (std::nothrow) Performance[m_systemCapcity];
    if(!m_performances){
        std::cout << "Memory problem!";
        return;
    }

    m_dates = new (std::nothrow) Date[m_systemCapcity];
    if(!m_dates){
        std::cout << "Memory problem!";
        return;
    }

    m_freeTickets = new (std::nothrow) Ticket[m_ticketsCapacity];
    if(!m_freeTickets){
        std::cout << "Memory problem!";
        return;
    }

    m_reservedTickets = nullptr;
    m_boughtTickets = nullptr;

}

System::System(const System& other){
    copy(other);
}

System::~System(){
    erase();
}

System& System::operator=(const System& other){
    if(this != &other){
        erase();
        copy(other);
    }
    return *this;
}

void System::copy(const System& other){
    m_performancesNumber = other.m_performancesNumber;
    m_datesNumber = other.m_datesNumber;
    m_freeTicketsNumber = other.m_freeTicketsNumber;
    m_reservedTicketsNumber = other.m_reservedTicketsNumber;
    m_boughtTicketsNumber = other.m_boughtTicketsNumber;

    m_systemCapcity = other.m_systemCapcity;
    m_ticketsCapacity = other.m_ticketsCapacity;

    m_performances = new (std::nothrow) Performance[m_systemCapcity];
    if(!m_performances){
        std::cout << "Memory problem!";
        return;
    }
    for(int i = 0; i < m_performancesNumber; ++i){
        m_performances[i] = other.m_performances[i];
    }
    
    m_dates = new (std::nothrow) Date[m_systemCapcity];
    if(!m_dates){
        std::cout << "Memory problem!";
        return;
    }
    for(int i = 0; i < m_datesNumber; ++i){
        m_dates[i] = other.m_dates[i];
    }

    m_freeTickets = new (std::nothrow) Ticket[m_ticketsCapacity];
    if(!m_freeTickets){
        std::cout << "Memory problem!";
        return;
    }
    for(int i = 0; i < m_freeTicketsNumber; ++i){
        m_freeTickets[i] = other.m_freeTickets[i];
    }

    m_reservedTickets = new (std::nothrow) Ticket[m_ticketsCapacity];
    if(!m_reservedTickets){
        std::cout << "Memory problem!";
        return;
    }
    for(int i = 0; i < m_reservedTicketsNumber; ++i){
        m_reservedTickets[i] = other.m_reservedTickets[i];
    }

    m_boughtTickets = new (std::nothrow) Ticket[m_ticketsCapacity];
    if(!m_boughtTickets){
        std::cout << "Memory problem!";
        return;
    }
    for(int i = 0; i < m_boughtTicketsNumber; ++i){
        m_boughtTickets[i] = other.m_boughtTickets[i];
    }

}

void System::erase(){
    delete[] m_performances;
    delete[] m_dates;
    delete[] m_freeTickets;
    delete[] m_reservedTickets; 
    delete[] m_boughtTickets;
}

void System::resizePerformances(){
    Performance* newPerformance = new (std::nothrow) Performance [m_systemCapcity * SYSTEM_INCREASE_STEP];
    if(!newPerformance){
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    for(int i = 0; i < m_performancesNumber; ++i){
        newPerformance[i] = m_performances[i];
    }
    erase();
    m_performances = newPerformance;
    m_systemCapcity *= SYSTEM_INCREASE_STEP;
}

void System::resizeDates(){
    Date* newDate = new (std::nothrow) Date [m_systemCapcity * SYSTEM_INCREASE_STEP];
    if(!newDate){
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    for(int i = 0; i < m_datesNumber; ++i){
        newDate[i] = m_dates[i];
    }
    erase();
    m_dates = newDate;
    m_systemCapcity *= SYSTEM_INCREASE_STEP;
}

void System::resizeFreeTickets(){
    Ticket* newFreeTickets = new (std::nothrow) Ticket [m_ticketsCapacity * TICKETS_INCREASE_STEP];
    if(!newFreeTickets){
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    for(int i = 0; i < m_freeTicketsNumber; ++i){
        newFreeTickets[i] = m_freeTickets[i];
    }
    erase();
    m_freeTickets = newFreeTickets;
    m_ticketsCapacity *= TICKETS_INCREASE_STEP;
}

void System::resizeReservedTickets(){
    Ticket* newReservedTickets = new (std::nothrow) Ticket [m_ticketsCapacity * TICKETS_INCREASE_STEP];
    if(!newReservedTickets){
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    for(int i = 0; i < m_reservedTicketsNumber; ++i){
        newReservedTickets[i] = m_freeTickets[i];
    }
    erase();
    m_freeTickets = newReservedTickets;
    m_ticketsCapacity *= TICKETS_INCREASE_STEP;
}

void System::resizeBoughtTickets(){
    Ticket* newBoughtTickets = new (std::nothrow) Ticket [m_ticketsCapacity * TICKETS_INCREASE_STEP];
    if(!newBoughtTickets){
        std::cout << "Memory problem!" << std::endl;
        return;
    }
    for(int i = 0; i < m_boughtTicketsNumber; ++i){
        newBoughtTickets[i] = m_boughtTickets[i];
    }
    erase();
    m_boughtTickets = newBoughtTickets;
    m_ticketsCapacity *= TICKETS_INCREASE_STEP;
}

unsigned int System::getPefomanceIndex(char* performanceName){
    assert(performanceName);

    for(int i = 0; i < m_performancesNumber; ++i){
        if(strcmp(m_performances[i].getPerformanceName(), performanceName) == 0){
            return i;
        }
    }
    return -1;
}

unsigned int System::getDateIndex(unsigned int day, unsigned int month, unsigned int year){
    assert(day);
    assert(month);
    assert(year);

    for(int i = 0; i < m_datesNumber; ++i){
        if(m_dates[i].getDay() == day && m_dates[i].getMonth() == month && m_dates[i].getYear() == year){
               return i;
        }
    }
    return -1; 
}

unsigned int System::getFreeTicketIndex(unsigned int password){
    assert(password);

    for(int i = 0 ; i < m_freeTicketsNumber; ++i){
        if(m_freeTickets[i].getPassword() == password){
            return i;
        }
    }
    return -1;
}

unsigned int System::getReservedTicketIndex(unsigned int password){
    assert(password);

    for(int i = 0 ; i < m_reservedTicketsNumber; ++i){
        if(m_reservedTickets[i].getPassword() == password){
            return i;
        }
    }
    return -1;
}

unsigned int System::getBoughtTicketIndex(unsigned int password){
    assert(password);

    for(int i = 0 ; i < m_boughtTicketsNumber; ++i){
        if(m_boughtTickets[i].getPassword() == password){
            return i;
        }
    }
    return -1;
}

void System::addNewPeformance(const Date& date, const char* name, Hall& hall){
    Performance p;
    p.setPerformanceName(name);
    p.setPerformanceDate(date);
    p.setPerformanceHall(hall);

    // if(getDateIndex(date.getDay(), date.getMonth(), date.getYear()) != -1){
    //     std::cout << "There is alredy a performance on " << p.getPerformanceDate() << "!" << std::endl;
    //     return;
    // } 

    if(m_performancesNumber == m_systemCapcity){
        resizePerformances();
    }
    m_performances[m_performancesNumber++] = p;
}

void System::freeSetes(Performance& performance){
    for(int i = 0; i < m_performancesNumber; ++i){
        if(m_performances[i].getPerformanceName() == performance.getPerformanceName() && 
            m_performances[i].getPerformanceDate() == performance.getPerformanceDate()){
                std::cout << performance.getAvailableSeatesForPerformance();
        }
        std::cout << "There is no have performance with this name or on that date!";
    }
}

void System::removeFreeTicket(unsigned int password){

    int removeFreeTicketIndex = getFreeTicketIndex(password);

    if (removeFreeTicketIndex == -1){
        std::cout << "There is not a tickets with password: " << password << std::endl;
        return;
    }

    m_freeTickets[removeFreeTicketIndex] = m_freeTickets[--m_freeTicketsNumber];
}

void System::removeReservedTicket(unsigned int password){

    int ticketIndex = getReservedTicketIndex(password);

    if (ticketIndex == -1)
    {
        std::cout << "There is not a reserved tickets with password " << password << std::endl;
        return;
    }

    m_reservedTickets[ticketIndex] = m_reservedTickets[--m_reservedTicketsNumber];
}

void System::addReservedTicket(const Ticket& reservedTikcet){
    if (m_reservedTicketsNumber == m_ticketsCapacity){
        resizeReservedTickets();
    }
    m_reservedTickets[m_reservedTicketsNumber++] = reservedTikcet;
}

void System::addFreeTicket(const Ticket& freeTikcet){
    if (m_freeTicketsNumber == m_ticketsCapacity){
        resizeFreeTickets();
    }
    m_freeTickets[m_freeTicketsNumber++] = freeTikcet;
}

void System::addBoughtTicket(const Ticket& boughtTikcet){
    if (m_boughtTicketsNumber == m_ticketsCapacity){
        resizeBoughtTickets();
    }
    m_boughtTickets[m_boughtTicketsNumber++] = boughtTikcet;
}

void System::makeReservation(char* name, Date& date){
    unsigned int row, seat, password;
    char* notice, answer;

    std::cout << "Enter a row: ";
    std::cin >> row;
    std::cout << "Enter a seat: ";
    std::cin >> seat;
    std::cout << "Enter a password: ";
    std::cin >> password;

    std::cout << "Do you want to add notice? Choose between 0 and 1";
    std::cin >> answer;

    if(answer == 1){
        std::cout << "seat add your notice: ";
        std::cin >> notice;
    }
    else 
        for(int i = 0; i < m_freeTicketsNumber; ++i){
            if(name == m_freeTickets[i].getTicketPerformanceName() && date == m_freeTickets[i].getTicketDate()){
                addReservedTicket(m_freeTickets[i]);
                m_freeTickets[i].setRowAndSeat(row, seat);
                removeFreeTicket(m_freeTickets[i].getPassword());
            }
        }
}

void System::cancelReservation(Ticket& ticket){
    removeReservedTicket(ticket.getPassword());
    addFreeTicket(ticket);
} 

bool System::isFreeSeat(unsigned int seat){
    for(int i = 0; i < m_boughtTicketsNumber; ++i){
        return m_boughtTickets[i].getSeatNumber() != seat;
    }
    return true;
}

void System::buyTicket(Ticket& ticket){
    int password;
    if(isFreeSeat(ticket.getSeatNumber())){
        for(int i = 0; i < m_reservedTicketsNumber; ++i){
            if(m_reservedTickets[i].getSeatNumber() == ticket.getSeatNumber()){
                std::cout << "Place enter password: ";
                std::cin >> password;
                if(password == ticket.getPassword()){
                    addBoughtTicket(ticket);
                    removeReservedTicket(ticket.getPassword());
                }
                else
                    std::cout << "Password is not correct!";
                    return;
            }
        }
    }
    else 
        std::cout << "Ticket for this seat is already bought!";
        return; 
} 

void System::printInfo(Date& startingDate, Date& endDate, Hall& hall){

    for(int i = getDateIndex(startingDate.getDay(), startingDate.getMonth(), startingDate.getYear());
            i < getDateIndex(endDate.getDay(), endDate.getMonth(), endDate.getYear());
            ++i){
                
        m_performances[i].printPerformance();
    }
}
