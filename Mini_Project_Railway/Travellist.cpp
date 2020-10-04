#include <iostream>
#include"Travellist.h"
#include"Passenger.h"
#include"Train.h"


void PassengerList::addTrip(std::string source,std::string destination,std::string trainnumber, std::string trainname,std::string name,int age,double distance,std::string seat){
    TrainList.push_back(Passenger(source,destination,trainnumber,trainname,name,age,distance,seat));
    }


void PassengerList::removeTripByPNR(int PNR){
std::list<Passenger>::iterator iter;
for(iter=TrainList.begin();iter!=TrainList.end();++iter)
    {
        if(iter->getPNR()==PNR)
            break;
    }
    if(iter!=TrainList.end())
    {
        std::cout<<"Cancelling Trip\n";
        TrainList.erase(iter);
    }
    else
    {
        std::cout<<"PNR not Found\n";
    }
}

Passenger* PassengerList::findPassengerByPNR(int PNR){
std::list<Passenger>::iterator iter;
for(iter=TrainList.begin();iter!=TrainList.end();++iter)
    {
        if(iter->getPNR()==PNR)
        {
            iter->displayDetails();
            return &(*iter);
        }

}
std::cout<<"Not Found In Database\n";
return NULL;
}

void PassengerList::displayAll(){
std::list<Passenger>::iterator iter;
for(iter=TrainList.begin();iter!=TrainList.end();++iter)
{
    iter->display();
}
}

int PassengerList::countNumberOfPassengers()
{
    int count =0;
    std::list<Passenger>::iterator iter;
    for(iter=TrainList.begin();iter!=TrainList.end();++iter)
    {
        count++;
    }
    std::cout<<count;
    return count;
}


int PassengerList::findPNR(std::string name,int age){
std::list<Passenger>::iterator iter;
    for(iter=TrainList.begin();iter!=TrainList.end();++iter)
    {
        if(iter->getName()==name && iter->getAge()==age)
        {
            break;
        }
    }
    if(iter!=TrainList.end())
    {
        std::cout<<iter->getPNR();
    }
    return iter->getPNR();
    }
