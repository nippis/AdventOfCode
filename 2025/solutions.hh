#ifndef SOLUTION_HH
#define SOLUTION_HH

#include <utility>
#include <vector>
#include <deque>
#include <array>
#include <unordered_set>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>

std::string whitespace(std::size_t length);
std::string whitespace(int length);

using PuzzleResult = std::pair<std::string, std::string>;

namespace day1  {PuzzleResult solve(std::ifstream file);}
namespace day2  {PuzzleResult solve(std::ifstream file);}
namespace day3  {PuzzleResult solve(std::ifstream file);}
namespace day4  {PuzzleResult solve(std::ifstream file);}
namespace day5  {PuzzleResult solve(std::ifstream file);}
namespace day6  {PuzzleResult solve(std::ifstream file);}
namespace day7  {PuzzleResult solve(std::ifstream file);}
namespace day8  {PuzzleResult solve(std::ifstream file);}
namespace day9  {PuzzleResult solve(std::ifstream file);}
namespace day10 {PuzzleResult solve(std::ifstream file);}
namespace day11 {PuzzleResult solve(std::ifstream file);}
namespace day12 {PuzzleResult solve(std::ifstream file);}
#endif