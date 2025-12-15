CXXFLAGS = -std=c++23 -O2 -Wno-narrowing
CXX = g++

ifeq ($(OS),Windows_NT)
	output = AOC.exe
else
	output = AOC.out
endif

all: main

main: main.o solutions.hh day01.o day02.o day03.o day04.o day05.o day06.o \
											  day07.o day08.o day09.o day10.o day11.o day12.o
	$(CXX) $(CXXFLAGS) -o $(output) *.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

day01.o: solutions/day01.cpp solutions.hh
	$(CXX) $(CXXFLAGS) -c solutions/day01.cpp

day02.o: solutions/day02.cpp solutions.hh
	$(CXX) $(CXXFLAGS) -c solutions/day02.cpp

day03.o: solutions/day03.cpp solutions.hh
	$(CXX) $(CXXFLAGS) -c solutions/day03.cpp

day04.o: solutions/day04.cpp solutions.hh
	$(CXX) $(CXXFLAGS) -c solutions/day04.cpp

day05.o: solutions/day05.cpp solutions.hh
	$(CXX) $(CXXFLAGS) -c solutions/day05.cpp

day06.o: solutions/day06.cpp solutions.hh
	$(CXX) $(CXXFLAGS) -c solutions/day06.cpp

day07.o: solutions/day07.cpp solutions.hh
	$(CXX) $(CXXFLAGS) -c solutions/day07.cpp

day08.o: solutions/day08.cpp solutions.hh
	$(CXX) $(CXXFLAGS) -c solutions/day08.cpp

day09.o: solutions/day09.cpp solutions.hh
	$(CXX) $(CXXFLAGS) -c solutions/day09.cpp

day10.o: solutions/day10.cpp solutions.hh
	$(CXX) $(CXXFLAGS) -c solutions/day10.cpp

day11.o: solutions/day11.cpp solutions.hh
	$(CXX) $(CXXFLAGS) -c solutions/day11.cpp

day12.o: solutions/day12.cpp solutions.hh
	$(CXX) $(CXXFLAGS) -c solutions/day12.cpp