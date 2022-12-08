#include "../solutions.hh"

std::pair<std::string, std::string> day1()
{
  std::ifstream f("inputs/input1.txt");
  std::string r;
  int m=0;
  for(int s=0;getline(f,r);m=s>m?s:m) s=r.size()>0?s+std::stoi(r):0;
  return {std::to_string(m), "0"};
}