#include <iostream>
#include <fstream>
#include <vector>

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

int main()
{
  std::ifstream file("input.txt");
  std::string row;
  std::vector<int> limits;
  int a = 0, b = 0;
  while (getline(file, row))
  {
    getLimits(row, limits);
    a += (limits.at(0)>=limits.at(2) && limits.at(1)<=limits.at(3) ||
          limits.at(0)<=limits.at(2) && limits.at(1)>=limits.at(3));
    b += (limits.at(1)>=limits.at(2) && limits.at(0)<=limits.at(2) ||
          limits.at(3)>=limits.at(0) && limits.at(2)<=limits.at(0));
  }
  std::cout << a << std::endl << b << std::endl;
}