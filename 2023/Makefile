ifeq ($(OS),Windows_NT)
	output = AOC.exe
else
	output = AOC.out
endif

all: main

main: main.o solutions day1.o day2.o day3.o day4.o day5.o day6.o day7.o day8.o day9.o day10.o \
		day11.o day12.o day13.o day14.o day15.o day16.o day17.o day18.o day19.o day20.o
	g++ -o $(output) -O2 *.o

main.o: main.cpp
	g++ -c main.cpp

solutions: utility.cpp solutions.hh
	g++ -c -O2 utility.cpp

day1.o: 1st/day1.cpp solutions.hh
	g++ -c -O2 1st/day1.cpp

day2.o: 2nd/day2.cpp solutions.hh
	g++ -c -O2 2nd/day2.cpp

day3.o: 3rd/day3.cpp solutions.hh
	g++ -c -O2 3rd/day3.cpp

day4.o: 4th/day4.cpp solutions.hh
	g++ -c -O2 4th/day4.cpp

day5.o: 5th/day5.cpp solutions.hh
	g++ -c -O2 5th/day5.cpp

day6.o: 6th/day6.cpp solutions.hh
	g++ -c -O2 6th/day6.cpp

day7.o: 7th/day7.cpp solutions.hh
	g++ -c -O2 7th/day7.cpp

day8.o: 8th/day8.cpp solutions.hh
	g++ -c -O2 8th/day8.cpp

day9.o: 9th/day9.cpp solutions.hh
	g++ -c -O2 9th/day9.cpp

day10.o: 10th/day10.cpp solutions.hh
	g++ -c -O2 10th/day10.cpp

day11.o: 11th/day11.cpp solutions.hh
	g++ -c -O2 11th/day11.cpp

day12.o: 12th/day12.cpp solutions.hh
	g++ -c -O2 12th/day12.cpp

day13.o: 13th/day13.cpp solutions.hh
	g++ -c -O2 13th/day13.cpp

day14.o: 14th/day14.cpp solutions.hh
	g++ -c -O2 14th/day14.cpp

day15.o: 15th/day15.cpp solutions.hh
	g++ -c -O2 15th/day15.cpp

day16.o: 16th/day16.cpp solutions.hh
	g++ -c -O2 16th/day16.cpp

day17.o: 17th/day17.cpp solutions.hh
	g++ -c -O2 17th/day17.cpp

day18.o: 18th/day18.cpp solutions.hh
	g++ -c -O2 18th/day18.cpp

day19.o: 19th/day19.cpp solutions.hh
	g++ -c -O2 19th/day19.cpp

day20.o: 20th/day20.cpp solutions.hh
	g++ -c -O2 20th/day20.cpp
