#include <iostream>
#include <fstream>
#include"Travellist.h"
#include"Passenger.h"
#include"Train.h"
#include<semaphore.h>
#include<pthread.h>
#include <gtest/gtest.h>
using namespace std;

pthread_mutex_t m1=PTHREAD_MUTEX_INITIALIZER;
sem_t s1;
PassengerList L2;


void* sem1(void* pv){



        pthread_mutex_lock(&m1);

        L2.addTrip("Bangalore","Chennai","104958","Janashathabdhi","Sam",25,500,"WS");
        pthread_mutex_unlock(&m1);
        sem_post(&s1);
		return NULL;
}


void* sem2(void* pv)        
{


        sem_wait(&s1);            
        pthread_mutex_lock(&m1);

		L2.addTrip("Bangalore","Delhi","104520","Express","Sarah",35,500,"WS");		
		
        pthread_mutex_unlock(&m1);
		return NULL;
        
}






namespace {

class PassengerListDbTest : public ::testing::Test {

protected:
  void SetUp() { 
    std::ifstream ip("data.csv");

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
  }
  void TearDown() {}
  PassengerList L1;
};
TEST_F(PassengerListDbTest, AddPassengerTestAndCountTotalPassengers) {
  EXPECT_EQ(50, L1.countNumberOfPassengers());
  EXPECT_EQ(1002, L1.findPNR("SMITH",45));
  L1.addTrip("Mumbai","Delhi", "105440","Express","Rahul",25,150,"WS");
  EXPECT_NE((Passenger*)NULL, L1.findPassengerByPNR(1050));
  EXPECT_EQ(51, L1.countNumberOfPassengers());
}

TEST_F(PassengerListDbTest, AddTripSemTest) {

    pthread_t pt1,pt2;    
    sem_init(&s1,0,0);
    pthread_create(&pt1,NULL,sem1,NULL);
    pthread_create(&pt2,NULL,sem2,NULL);
    pthread_join(pt1,NULL);
    pthread_join(pt2,NULL);

    L2.addTrip("Bangalore","Chennai","104958","Janashathabdhi","Shah",30,500,"WS");
    EXPECT_EQ(3, L2.countNumberOfPassengers());

    sem_destroy(&s1);
    pthread_mutex_destroy(&m1);
}





TEST_F(PassengerListDbTest, RemovePassengerTest) {

  L1.removeTripByPNR(1050);
  EXPECT_EQ(NULL, L1.findPassengerByPNR(1050));
  EXPECT_EQ(50, L1.countNumberOfPassengers());
}

TEST_F(PassengerListDbTest, TotalPassengersFromSource) {


  EXPECT_EQ(6, L1.totalPassengersFromSource("Mumbai"));
  EXPECT_EQ(16, L1.totalPassengersFromSource("Chennai"));
  
}

TEST_F(PassengerListDbTest, TotalPassengersToADestination) {


  EXPECT_EQ(19, L1.totalPassengersToADestination("Mumbai"));
  EXPECT_EQ(3, L1.totalPassengersToADestination("Chennai"));
  
}

TEST_F(PassengerListDbTest, totalPassengersFromSourcetoDestination) {


  EXPECT_EQ(3, L1.totalPassengersFromSourcetoDestination("Mumbai","Delhi"));
  EXPECT_EQ(4, L1.totalPassengersFromSourcetoDestination("Chennai","Mumbai"));
  
}
} 

