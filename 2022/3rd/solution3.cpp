#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../solutions.hh"

int priority(char a) {return (int)a - (std::islower(a) ? 96 : 38);}

std::pair<int, int> day3()
{
  std::ifstream file("inputs/input3.txt");
  std::string row;
  int prioritySum1 = 0, prioritySum2 = 0;
  std::vector<std::string> group;
  while (std::getline(file, row))
  {
    for (char a : row)
    {
      if (row.find(a, row.size() / 2) != std::string::npos)
      {
        prioritySum1 += priority(a);
        break;
      }
    }
    group.push_back(row);
    if (group.size() == 3)
    {
      for (char b : group.at(0))
      {
        if (group.at(1).find(b) != std::string::npos && group.at(2).find(b) != std::string::npos)
        {
          prioritySum2 += priority(b);
          break;
        }
      }
      group.clear();
    }
  }
  return {prioritySum1, prioritySum2};
}
