#include <iostream>
#include <fstream>
#include <vector>

#include "../solutions.hh"

int getLimits(std::string row, std::vector<int>& limits)
{
  limits.clear();
  std::vector<std::string> limitStrings = {""};
  for (char a : row)
  {
    if (a == '-' || a == ',') limitStrings.push_back("");
    else
    {
        limitStrings.back() += a;
    }
  }
  for (std::string str : limitStrings)
    limits.push_back(std::stoi(str));
  return limits.size();
}

std::pair<int, int> day4()
{
  std::ifstream file("inputs/input4.txt");
  std::string row;
  std::vector<int> l;
  int a = 0, b = 0;
  while (getline(file, row) && getLimits(row, l))
  {
    a += (l[0]>=l[2] && l[1]<=l[3] ||
          l[0]<=l[2] && l[1]>=l[3]);
    b += (l[1]>=l[2] && l[0]<=l[2] ||
          l[3]>=l[0] && l[2]<=l[0]);
  }
  return {a, b};
}