#include <iostream>
#include <chrono>
#include "solutions.hh"

std::string whitespace(int length)
{
  std::string space = "";
  for (int i = 0; i<length; i++)
    space += " ";
  return space;
}

void printRow(int i, std::pair<int, int> values, int dur)
{
  std::string a = std::to_string(values.first);
  std::string b = std::to_string(values.second);
  std::string du = std::to_string(dur);
  std::string d = std::to_string(i);
  std::cout << "|" << whitespace(5-d.size()) << d << whitespace(9-a.size()) << a << whitespace(9-b.size()) << b 
  <<whitespace(7-du.size()) << du << " \xC2\xB5" << "s" << " |"<< std::endl;
}

int main()
{
   std::vector<std::pair<int, int>(*)()> dayFunctions =
    {
      [](){return day1();},
      [](){return day2();},
      [](){return day3();},
      [](){return day4(std::ifstream("inputs/input4.txt"));},
    };

  std::cout << "| Day    Part 1    Part 2   Time   |" << std::endl;
  std::cout << "|----------------------------------|" << std::endl;
  int i = 1;
  for (auto func : dayFunctions)
  {
    auto start = std::chrono::high_resolution_clock::now();
    auto values = func();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    printRow(i, values, duration.count());
    i++;
  }
}