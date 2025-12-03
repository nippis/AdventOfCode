#include "../solutions.hh"
#include <cmath>

std::pair<std::string, std::string> day3::solve(std::ifstream f)
{
  unsigned int result1 = 0;
  unsigned long long result2 = 0;
  std::string row;
  while (getline(f, row))
  {
    auto first = std::max_element(row.begin(), row.end()-1);
    result1 += (*first - 48) * 10 + *std::max_element(first+1, row.end()) - 48;

    auto digitIterator = row.begin();
    for (int i = 11; i >= 0; i--)
    {
      digitIterator = std::max_element(digitIterator, row.end()-i);
      result2 += (*digitIterator++ - 48) * pow(10, i);
    }
  }
  return {std::to_string(result1), std::to_string(result2)};
}