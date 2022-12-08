#ifndef SOLUTION_HH
#define SOLUTION_HH

#include <utility>
#include <vector>
#include <deque>
#include <array>
#include <fstream>
#include <iostream>
#include <algorithm>

std::string whitespace(int length);

std::pair<std::string, std::string> day1();
std::pair<std::string, std::string> day2(std::ifstream file);
std::pair<std::string, std::string> day3(std::ifstream file);
std::pair<std::string, std::string> day4(std::ifstream file);
std::pair<std::string, std::string> day5(std::ifstream file);
std::pair<std::string, std::string> day6(std::ifstream file);
std::pair<std::string, std::string> day7(std::ifstream file);
std::pair<std::string, std::string> day8(std::ifstream file);

#endif