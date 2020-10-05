#include <iostream>
#include"Train.h"
#include"Passenger.h"
#include"Travellist.h"
using namespace std;




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
