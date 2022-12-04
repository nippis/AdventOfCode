all: main

main: main.o solutions
	g++ -o main.out main.o solution1.o solution2.o solution3.o solution4.o utility.o

main.o: main.cpp
	g++ -c main.cpp

solutions: 1st/solution1.cpp 2nd/solution2.cpp 3rd/solution3.cpp 4th/solution4.cpp utility.cpp solutions.hh
	g++ -c 1st/solution1.cpp 2nd/solution2.cpp 3rd/solution3.cpp 4th/solution4.cpp utility.cpp
