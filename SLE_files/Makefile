all: main

main: main.o tests.o functions.o
	g++ -o main main.o tests.o functions.o

main.o: main.cpp
	g++ -c main.cpp

functions.o: functions.cpp
	g++ -c functions.cpp

tests.o: tests.cpp
	g++ -c tests.cpp

