#include <iostream>
#include"Passenger.h"
#include"Train.h"
#include"Travellist.h"
using namespace std;


Passenger::Passenger():
        Train(),passenger_name(""),age(0),distance_btw_cities(0),seatPreference(""),PNR(0),coach(""){}

Passenger::Passenger(std::string source,std::string destination,std::string trainnumber, std::string trainname,std::string name,int age,double distance,std::string seat):
        Train(source,destination,trainnumber,trainname),passenger_name(name),age(age),distance_btw_cities(distance),seatPreference(seat){PNR=generatePNR();coach=getCoach();}

double Passenger::travelTime(){
    double timetaken=distance_btw_cities/(float(getSpeed())/float(60));
    cout<<"Travel time= "<<timetaken<<" mins"<<endl;
    return timetaken;
}

double Passenger::fare(){
    cout<<distance_btw_cities*10<<endl;
return distance_btw_cities*10;}


int Passenger::generatePNR(){
static int PNR=999;
PNR++;
return PNR;
}

int Passenger::getPNR(){

return PNR;}

void Passenger::display(){
std::cout<<PNR<<"   "<<passenger_name<<"     "<<age<<"     "<<seatPreference<<"     "<<coach<<std::endl;

}

void Passenger::displayDetails(){
    std::string Name=getTrainName();
    std::string Number=getTrainNumber();
    std::string Source=getSource();
    std::string Destination=getDestination();
std::cout<<Number<<"     "<<Name<<"   "<<Source<<"  "<<Destination<<"     "<<PNR<<"  "<<passenger_name<<"  "<<age<<"   "<<seatPreference<<"    "<<coach<<std::endl;

}

std::string Passenger::getName(){
return passenger_name;}

int Passenger::getAge(){
return age;}

double Passenger::getDistance(){
return distance_btw_cities;}

std::string Passenger::getSeatPreference(){
return seatPreference;}

std::string Passenger::getCoach(){
    if (PNR>=1000 && PNR <1060)
    {
        coach="S1";
        return coach;
    }
    else if (PNR>=1060 && PNR<1120)
    {
        coach="S2";
        return coach;
    }
    else
    {
        coach="WL";
        return coach;
    }
}
