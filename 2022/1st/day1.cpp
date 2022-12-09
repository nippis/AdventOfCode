#include "../solutions.hh"

std::pair<std::string, std::string> day1(std::ifstream f)
{
  std::string r;
  std::array<int,3> m{0,0,0};
  for(int s=0;getline(f,r);m={s<m[0]?m[0]:(s<m[1]?s:m[1]),s<m[2]?m[2]:(s<m[1]?s:m[1]),s>m[2]?s:m[2]}) s=r.size()>0?s+std::stoi(r):0;
  return {std::to_string(m[2]), std::to_string(m[0]+m[1]+m[2])};
}