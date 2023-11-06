#include "../solutions.hh"

std::pair<std::string, std::string> day3(std::ifstream file) 
{
  std::string row;
  std::vector<int> n;
  unsigned int a = 0;
  while (getline(file, row)) n.push_back(std::stoi(row, nullptr, 2));
  for (int x=1, c=0; x <= 2048; x *= 2)
    {
      for (auto i : n) c += !!(i&x);
      if (c>n.size()/2) a += x;
    }
  return {std::to_string(a * (a^4095)), ""};
}