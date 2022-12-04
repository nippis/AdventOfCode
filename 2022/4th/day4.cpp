#include "../solutions.hh"

bool getLimits(std::ifstream& file, int* l)
{
  int i = 0, is2dig = 0;
  char a;
  while (file.get(a))
  {
    if (!std::isdigit(a) && ++i) 
    {
      is2dig = 0;
      if (i>=4) return true;
    }
    else l[i] = is2dig++?l[i]*10+a:a;
  }
  return false;
}

std::pair<int, int> day4(std::ifstream file)
{
  int l[4], a = 0, b = 0;
  while (getLimits(file, l))
  {
    a += (l[0]>=l[2] && l[1]<=l[3] || l[0]<=l[2] && l[1]>=l[3]);
    b += (l[1]>=l[2] && l[0]<=l[2] || l[3]>=l[0] && l[2]<=l[0]);
  }
  return {a, b};
}