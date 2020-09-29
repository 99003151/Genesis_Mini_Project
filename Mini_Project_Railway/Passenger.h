#include<iostream>

#ifndef __PASSENGER_H
#define __PASSENGER_H
#include"Train.h"

class Passenger:public Train
{
private:
    std::string passenger_name;
    int age;
    int PNR;
    double distance_btw_cities;
    std::string seatPreference;
    std::string couchClass;

public:

    Passenger();
    double fare();
    double travelTime();
    void display();
    std::string getName();
    int getAge();
    double getDistance();
    std::string getSeatPreference();
    std::string getCoachClass();

};

#endif


