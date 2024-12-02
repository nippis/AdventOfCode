ifeq ($(OS),Windows_NT)
	output = AOC.exe
else
	output = AOC.out
endif

all: main

main: main.o solutions 	day01.o day02.o day03.o day04.o day05.o \
						day06.o day07.o day08.o day09.o day10.o \
						day11.o day12.o day13.o day14.o day15.o \
						day16.o day17.o day18.o day19.o day20.o \
						day21.o day22.o day23.o day24.o day25.o
	g++ -o $(output) -O2 *.o

main.o: main.cpp
	g++ -c main.cpp

solutions: utility.cpp solutions.hh
	g++ -c -O2 utility.cpp

day01.o: day01/day01.cpp solutions.hh
	g++ -c -O2 day01/day01.cpp

day02.o: day02/day02.cpp solutions.hh
	g++ -c -O2 day02/day02.cpp

day03.o: day03/day03.cpp solutions.hh
	g++ -c -O2 day03/day03.cpp

day04.o: day04/day04.cpp solutions.hh
	g++ -c -O2 day04/day04.cpp

day05.o: day05/day05.cpp solutions.hh
	g++ -c -O2 day05/day05.cpp

day06.o: day06/day06.cpp solutions.hh
	g++ -c -O2 day06/day06.cpp

day07.o: day07/day07.cpp solutions.hh
	g++ -c -O2 day07/day07.cpp

day08.o: day08/day08.cpp solutions.hh
	g++ -c -O2 day08/day08.cpp

day09.o: day09/day09.cpp solutions.hh
	g++ -c -O2 day09/day09.cpp

day10.o: day10/day10.cpp solutions.hh
	g++ -c -O2 day10/day10.cpp

day11.o: day11/day11.cpp solutions.hh
	g++ -c -O2 day11/day11.cpp

day12.o: day12/day12.cpp solutions.hh
	g++ -c -O2 day12/day12.cpp

day13.o: day13/day13.cpp solutions.hh
	g++ -c -O2 day13/day13.cpp

day14.o: day14/day14.cpp solutions.hh
	g++ -c -O2 day14/day14.cpp

day15.o: day15/day15.cpp solutions.hh
	g++ -c -O2 day15/day15.cpp

day16.o: day16/day16.cpp solutions.hh
	g++ -c -O2 day16/day16.cpp

day17.o: day17/day17.cpp solutions.hh
	g++ -c -O2 day17/day17.cpp

day18.o: day18/day18.cpp solutions.hh
	g++ -c -O2 day18/day18.cpp

day19.o: day19/day19.cpp solutions.hh
	g++ -c -O2 day19/day19.cpp

day20.o: day20/day20.cpp solutions.hh
	g++ -c -O2 day20/day20.cpp

day21.o: day21/day21.cpp solutions.hh
	g++ -c -O2 day21/day21.cpp

day22.o: day22/day22.cpp solutions.hh
	g++ -c -O2 day22/day22.cpp

day23.o: day23/day23.cpp solutions.hh
	g++ -c -O2 day23/day23.cpp

day24.o: day24/day24.cpp solutions.hh
	g++ -c -O2 day24/day24.cpp

day25.o: day25/day25.cpp solutions.hh
	g++ -c -O2 day25/day25.cpp