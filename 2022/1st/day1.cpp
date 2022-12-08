#include "../solutions.hh"

std::pair<std::string, std::string> day1()
{
  std::ifstream file("inputs/input1.txt");
  std::string row;
  int max = 0;
  int sum = 0;
  while (getline(file, row))
  {
    if (row.size() > 0)
    {
      sum += std::stoi(row);
    }
    else
    {
      if (sum > max) max = sum;
      sum = 0;
    }
  }
  return {std::to_string(max), "0"};
}