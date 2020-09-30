#ifndef __TRAVELLIST_H
#define __TRAVELLIST_H
#include<iostream>
#include<list>
#include"Passenger.h"

class PassengerList
{
private:
    std::list<Passenger> TripList;
public:
    void addTrip(std::string,std::string,std::string, std::string,std::string,int,double,std::string);

    void displayAll();

};

#endif // __TRAVELLIST_H
