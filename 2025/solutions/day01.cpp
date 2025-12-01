#include "../solutions.hh"

std::pair<std::string, std::string> day1::solve(std::ifstream f)
{
  std::string row = "";
  unsigned int pw = 0;
  unsigned int pw2 = 0;
  int dial = 50;
  int prev_dial = 0;
  while (getline(f, row))
  {
    prev_dial = dial;
    dial += std::stoi(row.replace(0, 1, row.at(0) == 'R' ? "-" : ""));
    pw += dial % 100 == 0;
    pw2 += abs(prev_dial/100 - dial/100) + (dial*prev_dial < 0);
  }
  return {std::to_string(pw), std::to_string(pw2)};
}