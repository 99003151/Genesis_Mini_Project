
#include<iostream>

#ifndef __PASSENGER_H
#define __PASSENGER_H
#include"Train.h"

class Passenger:public Train
{
private:
    std::string passenger_name;
    int age;
    double distance_btw_cities;
    std::string seatPreference;
    int PNR;
    std::string coach;


public:

    Passenger();
    Passenger(std::string,std::string,std::string, std::string,std::string,int,double,std::string);
    double fare();
    double travelTime();
    void display();
    std::string getName();
    int getAge();
    double getDistance();
    std::string getSeatPreference();
    std::string getCoach();
    int generatePNR();
    int getPNR();
    void displayDetails();

};

#endif

