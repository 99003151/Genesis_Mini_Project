#include <iostream>
#include <fstream>
#include"Passenger.h"
#include"Train.h"
#include"Travellist.h"
using namespace std;

/*int main()
{
    std::string name;
    int age;
    PassengerList L1;

  ifstream ip("data.csv");

  if(!ip.is_open()) std::cout << "ERROR: File Open" << '\n';

  string Source;
  string Destination;
  string TNumber;
  string TName;
  string Name;
  string Age;
  string Distance;
  string Seat;
  int AGE;
  int DISTANCE;


  while(ip.good()){

    getline(ip,Source,',');
    getline(ip,Destination,',');
    getline(ip,TNumber,',');
    getline(ip,TName,',');
    getline(ip,Name,',');
    getline(ip,Age,',');
    getline(ip,Distance,',');
    getline(ip,Seat,'\n');
    AGE=stoi(Age);
    DISTANCE=stoi(Distance);

    if(Source!="")
    L1.addTrip(Source,Destination,TNumber,TName,Name,AGE,DISTANCE,Seat);
  }

  ip.close();
  
  L1.totalPassengersFromSource("Mumbai");
  
  L1.totalPassengersFromSourcetoDestination("Mumbai","Bangalore");

    std::string seat;
    int cancelPNR;
    int checkPNR;
    int option;
    char repeat;

    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout<<".......WELCOME TO RAILWAY RESERVATION SYSTEM..........\n";
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

    do{
    std::cout<<"Choose Option \n1.User\n2.Admin\n\n";

    std::cin>>option;


    switch (option)
    {
    case 1:
        std::cout<<"1.View Train Details\n";
        std::cout<<"2.Reservation\n";
        std::cout<<"3.Cancellation\n";
        std::cout<<"4.Find Passenger Details\n";
        std::cin>>option;
        switch(option)
        {
        case 1:
            std::cout<<"Train Number     Train Name         Source       Destination     Fare\n";
            std::cout<<"104958           Janashathabdhi     Bangalore    Chennai         500\n";
            std::cout<<"298764           Rajadhani          Chennai      Bangalore       700\n";
            break;

        case 2:
            std::cout<<"   Train Number     Train Name         Source       Destination     Fare\n";
            std::cout<<"1. 104958           Janashathabdhi     Bangalore    Chennai         500\n";
            std::cout<<"2. 298764           Rajadhani          Chennai      Bangalore       700\n";
            std::cout<<"\nTrain to be booked\n";
            std::cin>>option;
            switch(option)
            {
            case 1:
                std::cout<<"First Name: ";
                std::cin>>name;
                std::cout<<"\nAge: ";
                std::cin>>age;
                std::cout<<"\nSeat Preference(WS/SU/SL): ";
                std::cin>>seat;
                L1.addTrip("Bangalore","Chennai","104958","Janashathabdhi",name,age,500,seat);
                cout<<"Ticket Booked\nPNR:";
                L1.findPNR(name,age);
                break;
            case 2:
                std::cout<<"First Name: ";
                std::cin>>name;
                std::cout<<"\nAge: ";
                std::cin>>age;
                std::cout<<"\nSeat Preference(WS/SU/SL): ";
                std::cin>>seat;
                L2.addTrip("Bangalore","Chennai","298764","Rajadhani",name,age,500,seat);
                cout<<"\nTicket Booked\nPNR:";
                L2.findPNR(name,age);
                break;
            }
            break;

        case 3:
            std::cout<<"Enter the PNR Number to be cancelled\n";
            std::cin>>cancelPNR;
            std::cout<<"Select the Train name\n 1.Janashathabdhi\n 2.Rajadhani\n";
            std::cin>>option;
            switch(option)
            {
            case 1:
                L1.removeTripByPNR(cancelPNR);
                break;
            case 2:
                L2.removeTripByPNR(cancelPNR);
                break;
            }
            break;
        case 4:
            std::cout<<"Enter the PNR Number to be Checked\n";
            std::cin>>checkPNR;
            std::cout<<"Select the Train name\n 1.Janashathabdhi\n 2.Rajadhani\n";
            std::cin>>option;
            switch(option)
            {
            case 1:
                std::cout<<"------------------------------------------------------------------------------\n";
                std::cout<<"TrainNumber TrainName       Source    Destination  PNR  Name  Age  Seat Coach \n";
                std::cout<<"------------------------------------------------------------------------------\n";
                L1.findPassengerByPNR(checkPNR);
                break;
            case 2:
                std::cout<<"------------------------------------------------------------------------------\n";
                std::cout<<"TrainNumber TrainName   Source    Destination  PNR  Name  Age  Seat Coach \n";
                std::cout<<"------------------------------------------------------------------------------\n";
                L2.findPassengerByPNR(checkPNR);
                break;
            }

            break;
        }
        break;

    case 2:
        std::string password;
        std::cout<<"Enter Password: ";
        std::cin>>password;
        if(password=="password")
        {
            std::cout<<"Admin Login Successful\n";
            std::cout<<"1. List of All Passengers in Janashathabdhi\n";
            std::cout<<"2. List of All Passengers in Rajadhani\n";
            std::cout<<"3. Total Number of Passengers in Rajadhani\n";
            std::cout<<"4. Total Number of Passengers in Janashathabdhi\n";

            std::cin>>option;
            switch(option)
            {
            case 1:
                std::cout<<"------------------------------------\n";
                std::cout<<"List Of Passengers In Janashathabdhi\n";
                std::cout<<"------------------------------------\n";
                std::cout<<"PNR    Name    Age    Seat   Coach \n";
                std::cout<<"------------------------------------\n";
                L1.displayAll();
                std::cout<<"------------------------------------\n";
                break;
            case 2:
                std::cout<<"------------------------------------\n";
                std::cout<<"List Of Passengers In Rajadhani\n";
                std::cout<<"------------------------------------\n";
                std::cout<<"PNR    Name    Age    Seat   Coach \n";
                std::cout<<"------------------------------------\n";
                L2.displayAll();
                std::cout<<"------------------------------------\n";
                break;
            case 3:
                std::cout<<"--------------------------------------------\n";
                cout<<"Total Number Of Passengers In Janashathabdhi: ";
                L1.countNumberOfPassengers();
                std::cout<<"\n------------------------------------------\n";
                break;
            case 4:
                std::cout<<"-------------------------------------------\n";
                cout<<"Total Number Of Passengers In Rajadhani: ";
                L2.countNumberOfPassengers();
                std::cout<<"\n-----------------------------------------\n";
                break;
            }
        }
        else
        {
            std::cout<<"Incorrect Password\n";
            break;
        }

        break;
    }
    std::cout<<"\nRepeat Again(Y/N)\n";
    std::cin>>repeat;

    }while(repeat=='y'||repeat=='Y');




    return 0;
}*/
