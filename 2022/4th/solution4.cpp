#include <iostream>
#include <fstream>
#include <vector>

#include "../solutions.hh"

bool getLimits(std::string row, int* l, int i = 0)
{
  std::string lstr[4];
  for (char a : row)
  {
    if (!std::isdigit(a)) i++;
    else lstr[i] += a;
  }
  for (int j=0; j<4; j++) l[j]=std::stoi(lstr[j]);
  return true;
}

std::pair<int, int> day4(std::ifstream file)
{
  std::string row;
  int l[4], a = 0, b = 0;
  while (getline(file, row) && getLimits(row, l))
  {
    a += (l[0]>=l[2] && l[1]<=l[3] || l[0]<=l[2] && l[1]>=l[3]);
    b += (l[1]>=l[2] && l[0]<=l[2] || l[3]>=l[0] && l[2]<=l[0]);
  }
  return {a, b};
}