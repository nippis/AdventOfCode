#include "../solutions.hh"

std::pair<std::string, std::string> day6(std::ifstream file)
{
  char a;
  int i = 0, r1= 0;
  std::string prev, prev2;
  while (file.get(a) && ++i)
  {
    if (r1 == 0 && prev.size() > 3) prev.pop_back();
    if (r1 == 0 && prev.rfind(a) != std::string::npos) prev.erase(prev.rfind(a));
    if (r1 == 0 && prev.size() == 3) r1 = i;
    if (prev2.size() > 13) prev2.pop_back();
    if (prev2.rfind(a) != std::string::npos) prev2.erase(prev2.rfind(a));
    if (prev2.size() == 13) return {std::to_string(r1), std::to_string(i)};
    if (r1 == 0) prev.insert(prev.begin(), a);
    prev2.insert(prev2.begin(), a);
  }
  return {"0", "0"};
}