#include "../solutions.hh"

std::pair<std::string, std::string> day1::solve(std::ifstream f)
{
  char a;
  int firstBasement;
  int floor = 0;
  int i = 0;
  while (f.get(a) && ++i)
  {
    floor += a == '(' ? 1 : -1;
    if ( firstBasement == 0 && floor < 0) firstBasement = i;
  }
  return { std::to_string(floor),std::to_string(firstBasement)};
}