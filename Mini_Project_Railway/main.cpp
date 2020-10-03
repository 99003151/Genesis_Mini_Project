#include <iostream>
#include"Passenger.h"
#include"Train.h"
#include"Travellist.h"
using namespace std;

int main()
{
    std::string name;
    int age;
    PassengerList L1;
    std::string seat;

    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    std::cout<<".......WELCOME TO RAILWAY RESERVATION SYSTEM..........\n";
    std::cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n";

    std::cout<<"Choose Option \n1.User\n2.Admin\n\n";
    int option;
    char repeat;
    std::cin>>option;

    do{
    switch (option)
    {
    case 1:
        std::cout<<"1.View Train Details\n";
        std::cout<<"2.Reservation\n";
        std::cin>>option;
        switch(option)
        {
        case 1:
            std::cout<<"Train Number     Train Name         Source       Destination     Fare\n";
            std::cout<<"104958           Janashathabdhi     Bangalore    Chennai         500\n";
            std::cout<<"298764           Rajadhani          Chennai      Bangalore\n";
            break;

        case 2:
            std::cout<<"Train Number     Train Name         Source       Destination\n";
            std::cout<<"1. 104958        Janashathabdhi     Bangalore    Chennai\n";
            std::cout<<"2. 298764        Rajadhani          Chennai      Bangalore\n";
            std::cout<<"\nTrain Number to be booked\n";
            std::cin>>option;
            switch(option)
            {
            case 1:
                std::cout<<"Name: ";
                std::cin>>name;
                std::cout<<"\nAge: ";
                std::cin>>age;
                std::cout<<"\nSeat Preference: ";
                std::cin>>seat;
                L1.addTrip("Bangalore","Chennai","104958","Janashathabdhi",name,age,500,seat);
                L1.displayAll();
                break;
            }}
            break;



    case 2:
        std::string password;
        std::cout<<"Enter Password: ";
        std::cin>>password;
        if(password=="password")
        {
            std::cout<<"Admin Login Successful\n";
        }
        else
        {
            std::cout<<"Incorrect Password\n";
            break;
        }
        L1.displayAll();
        break;
    }
    std::cout<<"Repeat Again(Y/N)\n";
    std::cin>>repeat;

    }while(repeat=='y'||repeat=='Y');




    return 0;
}
