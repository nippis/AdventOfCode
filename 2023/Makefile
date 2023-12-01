ifeq ($(OS),Windows_NT)
	output = AOC.exe
else
	output = AOC.out
endif

solutions = 1st/day1.cpp 2nd/day2.cpp 3rd/day3.cpp 4th/day4.cpp 5th/day5.cpp \
			6th/day6.cpp 7th/day7.cpp 8th/day8.cpp  9th/day9.cpp 10th/day10.cpp \
			11th/day11.cpp 12th/day12.cpp 13th/day13.cpp  14th/day14.cpp 15th/day15.cpp \
			16th/day16.cpp 17th/day17.cpp 18th/day18.cpp  19th/day19.cpp 20th/day20.cpp \
			21st/day21.cpp 22nd/day22.cpp 23rd/day23.cpp  24th/day24.cpp

all: main

main: main.o solutions
	g++ -o $(output) -O2 *.o

main.o: main.cpp
	g++ -c main.cpp

solutions: $(solutions) utility.cpp solutions.hh
	g++ -c -O2 utility.cpp $(solutions)