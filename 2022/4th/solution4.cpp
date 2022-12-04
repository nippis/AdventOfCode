#include <fstream>

#include "../solutions.hh"

bool getLimits(const std::string& row, int* l)
{
  int i = 0, is2dig = 0;
  for (char a : row)
  {
    if (!std::isdigit(a) && ++i) is2dig = 0;
    else l[i] = is2dig++?l[i]*10+a:a;
  }
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