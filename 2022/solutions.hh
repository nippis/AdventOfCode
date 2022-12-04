#ifndef SOLUTION_HH
#define SOLUTION_HH

#include <utility>
#include <vector>

#include <fstream>

std::string whitespace(int length);

std::pair<int, int> day1();
std::pair<int, int> day2();
std::pair<int, int> day3();
std::pair<int, int> day4(std::ifstream file);

#endif