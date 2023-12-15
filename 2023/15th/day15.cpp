#include "../solutions.hh"

std::pair<std::string, std::string> day15::solve(std::ifstream f)
{
  char a;
  int sum = 0;
  int stepsum = 0;
  while (f.get(a) && a != '\n')
  {
    if (a == ',')
    {
      sum += stepsum;
      stepsum = 0;
      continue;
    }
    stepsum = (stepsum + a) * 17 % 256;
  }
  sum += stepsum;
  return {std::to_string(sum),""};
}