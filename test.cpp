#include <iostream>
#include"Travellist.h"
#include"Passenger.h"
#include"Train.h"
#include <gtest/gtest.h>

TEST(Passenger,DefaultConstructor) {
    Passenger p1;
    EXPECT_EQ("",p1.getName());
    EXPECT_EQ(0,p1.getAge());
    EXPECT_EQ(0,p1.getDistance());
    EXPECT_EQ("",p1.getSeatPreference());
   
}

TEST(Passenger,ParameterizedConstructor) {
    Passenger p2("Mumbai","Delhi", "105440","Express","Rahul",25,150,"WS");
    EXPECT_EQ("Rahul",p2.getName());
    EXPECT_EQ(25,p2.getAge());
    EXPECT_EQ(150,p2.getDistance());
    EXPECT_EQ("WS",p2.getSeatPreference());
}

TEST(Passenger,GetPNR) {
    Passenger p3("Mumbai","Delhi", "105440","Express","Arjun",40,150,"WS");
    EXPECT_EQ(1001,p3.getPNR());
    EXPECT_EQ(1500,p3.fare());
    EXPECT_EQ(180,p3.travelTime());
}



