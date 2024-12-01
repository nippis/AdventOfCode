ifeq ($(OS),Windows_NT)
	output = AOC.exe
else
	output = AOC.out
endif

solutions = 11th/day11.cpp 12th/day12.cpp 13th/day13.cpp  14th/day14.cpp 15th/day15.cpp \
			16th/day16.cpp 17th/day17.cpp 18th/day18.cpp  19th/day19.cpp 20th/day20.cpp \
			21st/day21.cpp 22nd/day22.cpp 23rd/day23.cpp  24th/day24.cpp

all: main

main: main.o day9 utility solutions.hh
	g++ -o $(output) -Ofast *.o

main.o: main.cpp
	g++ -c main.cpp

utility: utility.cpp
	g++ -c -O2 utility.cpp 

solutions: $(solutions) utility.cpp solutions.hh
	g++ -c -O2 utility.cpp $(solutions)

day1: 1st/day1.cpp solutions.hh
	g++ -c -O2 1st/day1.cpp

day2: 2nd/day2.cpp solutions.hh
	g++ -c -O2 2nd/day2.cpp

day3: 3rd/day3.cpp solutions.hh
	g++ -c -O2 3rd/day3.cpp

day4: 4th/day4.cpp solutions.hh
	g++ -c -O2 4th/day4.cpp

day5: 5th/day5.cpp solutions.hh
	g++ -c -O2 5th/day5.cpp

day6: 6th/day6.cpp solutions.hh
	g++ -c -O2 6th/day6.cpp

day7: 7th/day7.cpp solutions.hh
	g++ -c -O2 7th/day7.cpp

day8: 8th/day8.cpp solutions.hh
	g++ -c -O2 8th/day8.cpp

day9: 9th/day9.cpp solutions.hh
	g++ -c -O2 9th/day9.cpp

day10: 10th/day10.cpp solutions.hh
	g++ -c -Ofast 10th/day10.cpp