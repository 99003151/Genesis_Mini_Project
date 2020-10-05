all: all.out 
all.out: Train.o Passenger.o Travellist.o test.o Dbtest.o
	g++ $^ -o $@ -lgtest -lgtest_main -lpthread
test.o: test.cpp Train.h Passenger.h
	g++ $< -c
Dbtest.o: Dbtest.cpp Train.h Passenger.h Travellist.h 
	g++ $< -c

Travellist.o: Travellist.cpp Travellist.h Passenger.h Train.h
	g++ $< -c
Passenger.o: Passenger.cpp Passenger.h Train.h
	g++ $< -c
Train.o: Train.cpp Train.h
	g++ $< -c
valgrind: ./all.out
	valgrind ./all.out
cppcheck: *.cpp
	cppcheck *.cpp
clean:
	rm -rf *.o all.out
