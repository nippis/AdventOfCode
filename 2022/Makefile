ifeq ($(OS),Windows_NT)
	output = AOC.exe
else
	output = AOC.out
endif

all: main

main: main.o solutions
	g++ -o $(output) -O2 main.o utility.o \
									day1.o day2.o day3.o day4.o day5.o \
									day6.o day7.o day8.o day9.o day10.o \
									day11.o day12.o day13.o

main.o: main.cpp
	g++ -c main.cpp

solutions: 1st/day1.cpp 2nd/day2.cpp 3rd/day3.cpp 4th/day4.cpp 5th/day5.cpp \
					 6th/day6.cpp 7th/day7.cpp 8th/day8.cpp  9th/day9.cpp 10th/day10.cpp \
					 11th/day11.cpp 12th/day12.cpp 13th/day13.cpp \
					 utility.cpp solutions.hh
	g++ -c -O2 utility.cpp \
				 1st/day1.cpp 2nd/day2.cpp 3rd/day3.cpp 4th/day4.cpp 5th/day5.cpp \
	       6th/day6.cpp 7th/day7.cpp 8th/day8.cpp 9th/day9.cpp 10th/day10.cpp \
				 11th/day11.cpp 12th/day12.cpp 13th/day13.cpp