#pragma once

const unsigned int CAPACITY = 128;

class Hall{

private:
    unsigned int m_hallNumber;
    unsigned int m_rowsNumber;
    unsigned int m_seatesNumber;
    unsigned int m_availableSeaes;

public:
    Hall();

    void setHallNumber(const unsigned int hallNumber);
    void setRowsNumber(const unsigned int rowsNumber);
    void setSeatesNumber(const unsigned int seatesNumber);
    void setAvailableSeates();
    unsigned int getAvailableSeates(){ return m_availableSeaes; };
    unsigned int getHallNumber(){ return m_hallNumber; };
    void printHall();


};