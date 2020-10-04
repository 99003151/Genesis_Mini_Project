#ifndef __TRAVELLIST_H
#define __TRAVELLIST_H
#include<iostream>
#include<list>
#include"Passenger.h"

class PassengerList
{
private:
    std::list<Passenger> TrainList;

public:
    void addTrip(std::string,std::string,std::string, std::string,std::string,int,double,std::string);
    void removeTripByPNR(int);
    Passenger* findPassengerByPNR(int);
    int countNumberOfPassengers();
    void displayAll();
    int findPNR(std::string,int);


};

#endif // __TRAVELLIST_H
