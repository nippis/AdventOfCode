all: main

main: main.o solutions
	g++ -o main.out main.o day1.o day2.o day3.o day4.o day5.o utility.o

main.o: main.cpp
	g++ -c -O3 main.cpp

solutions: 1st/day1.cpp 2nd/day2.cpp 3rd/day3.cpp 4th/day4.cpp 5th/day5.cpp utility.cpp solutions.hh
	g++ -c -O3 1st/day1.cpp 2nd/day2.cpp 3rd/day3.cpp 4th/day4.cpp 5th/day5.cpp utility.cpp
