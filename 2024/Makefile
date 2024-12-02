ifeq ($(OS),Windows_NT)
	output = AOC.exe
else
	output = AOC.out
endif

all: main

main: main.o solutions
	g++ -o $(output) -O3 main.o utility.o \
									day01.o day02.o day03.o day04.o day05.o \
									day06.o day07.o day08.o day09.o day10.o \
									day11.o day12.o day13.o day14.o day15.o \
									day16.o day17.o day18.o day19.o day20.o \
									day21.o day22.o day23.o day24.o

main.o: main.cpp
	g++ -c main.cpp

solutions: day01/day01.cpp day02/day02.cpp day03/day03.cpp day04/day04.cpp day05/day05.cpp \
					day06/day06.cpp day07/day07.cpp day08/day08.cpp  day09/day09.cpp day10/day10.cpp \
					day11/day11.cpp day12/day12.cpp day13/day13.cpp  day14/day14.cpp day15/day15.cpp \
					day16/day16.cpp day17/day17.cpp day18/day18.cpp  day19/day19.cpp day20/day20.cpp \
					day21/day21.cpp day22/day22.cpp day23/day23.cpp  day24/day24.cpp \
					utility.cpp solutions.hh
	g++ -c -O3 utility.cpp \
				 	day01/day01.cpp day02/day02.cpp day03/day03.cpp  day04/day04.cpp day05/day05.cpp \
					day06/day06.cpp day07/day07.cpp day08/day08.cpp  day09/day09.cpp day10/day10.cpp \
					day11/day11.cpp day12/day12.cpp day13/day13.cpp  day14/day14.cpp day15/day15.cpp \
					day16/day16.cpp day17/day17.cpp day18/day18.cpp  day19/day19.cpp day20/day20.cpp \
					day21/day21.cpp day22/day22.cpp day23/day23.cpp  day24/day24.cpp