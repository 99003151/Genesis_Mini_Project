#include <iostream>
#include"Train.h"
#include"Passenger.h"
#include"Travellist.h"
using namespace std;

int main()
{
    char a;
    string b;
    string c;
    string d;
    int f;
    PassengerList L1;
    do{
    cout<<"Source:\n";
    cin>>b;
    cout<<"Destination:\n";
    cin>>c;
    cout<<"Name:\n";
    cin>>d;
    cout<<"Age:\n";
    cin>>f;
    L1.addTrip(b,c,"104958","Nethravathi",d,f,500,"WS");
    cout<<"Add More Passenger\n";
    cin>>a;
    }
    while(a=='Y'||a=='y');
    L1.displayAll();
    return 0;
}


Train::Train():
    source_station(""),destination_station(""),train_number(""),train_name(""){}

Train::Train(std::string source,std::string destination,std::string trainnumber,std::string trainname):
    source_station(source),destination_station(destination),train_number(trainnumber),train_name(trainname){}

std::string Train::getSource(){
return source_station;}

std::string Train::getDestination(){
return destination_station;}

std::string Train::getTrainNumber(){
return train_number;}

std::string Train::getTrainName(){
return train_name;}

int Train::getSpeed(){
return avgSpeed;}
