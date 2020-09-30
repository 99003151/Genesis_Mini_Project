#include <iostream>
#include"Travellist.h"
#include"Passenger.h"
#include"Train.h"


void PassengerList::addTrip(std::string source,std::string destination,std::string trainnumber, std::string trainname,std::string name,int age,double distance,std::string seat){
    TripList.push_back(Passenger(source,destination,trainnumber,trainname,name,age,distance,seat));
    }

void PassengerList::displayAll(){
std::list<Passenger>::iterator iter;
for(iter=TripList.begin();iter!=TripList.end();++iter)
{
    iter->display();
}
}

