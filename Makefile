all: projekt212

projekt212: main.o airport.o menu.o myMap.o Database.o
	g++ main.o airport.o menu.o myMap.o Database.o -o projekt212

main.o: main.cpp
	g++ -c main.cpp

airport.o: airport.cpp
	g++ -c airport.cpp

menu.o: menu.cpp
	g++ -c menu.cpp

myMap.o: myMap.cpp
	g++ -c myMap.cpp

Database.o: Database.cpp
	g++ -c Database.cpp