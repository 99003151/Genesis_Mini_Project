#include<iostream>
#ifndef __TRAIN_H
#define __TRAIN_H

class Train
{
    private:
        std::string source_station;
        std::string destination_station;
        std::string train_number;
        std::string train_name;
        const int avgSpeed=50;   //50km/hr
    public:
        Train();
        Train(std::string ,std::string,std::string,std::string);
        virtual double fare()=0;
        virtual double travelTime()=0;
        virtual void display()=0;
        std::string getSource();
        std::string getDestination();
        std::string getTrainNumber();
        std::string getTrainName();
        int getSpeed();
};
#endif
