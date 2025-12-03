#include "../solutions.hh"

std::pair<std::string, std::string> day3::solve(std::ifstream f)
{
  unsigned int result = 0;
  std::string row;
  while (getline(f, row))
  {
    auto first = std::max_element(row.begin(), row.end()-1);
    result += *first * 10 + *std::max_element(first+1, row.end()) - 480 - 48;
  }
  return {std::to_string(result),""};
}