#include <iostream>
#include"Travellist.h"
#include"Passenger.h"
#include"Train.h"


void PassengerList::addTrip(std::string source,std::string destination,std::string trainnumber, std::string trainname,std::string name,int age,double distance,std::string seat){
    Janashathabdhi.push_back(Passenger(source,destination,trainnumber,trainname,name,age,distance,seat));
    }


void PassengerList::removeTripByPNR(int PNR){
std::list<Passenger>::iterator iter;
for(iter=Janashathabdhi.begin();iter!=Janashathabdhi.end();++iter)
    {
        if(iter->getPNR()==PNR)
            break;
    }
    if(iter!=Janashathabdhi.end())
    {
        std::cout<<"Cancelling Trip\n";
        Janashathabdhi.erase(iter);
    }
    else
    {
        std::cout<<"PNR not Found\n";
    }
}

Passenger* PassengerList::findPassengerByPNR(int PNR){
std::list<Passenger>::iterator iter;
for(iter=Janashathabdhi.begin();iter!=Janashathabdhi.end();++iter)
    {
        if(iter->getPNR()==PNR)
        {
            iter->display();
            return &(*iter);
        }
std::cout<<"Not Found In Database\n";
}
return NULL;
}

void PassengerList::displayAll(){
std::list<Passenger>::iterator iter;
for(iter=Janashathabdhi.begin();iter!=Janashathabdhi.end();++iter)
{
    iter->display();
}
}

int PassengerList::countNumberOfPassengers()
{
    int count =0;
    std::list<Passenger>::iterator iter;
    for(iter=Janashathabdhi.begin();iter!=Janashathabdhi.end();++iter)
    {
        count++;
    }
    return count;
}



