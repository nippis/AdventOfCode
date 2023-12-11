#include "../solutions.hh"

struct Galaxy
{
  Galaxy(long long x, long long y) : x(x), y(y) {}
  long long x;
  long long y;
};

long long dist(const Galaxy& a, const Galaxy& b)
{
  return abs(a.x - b.x) + abs(a.y - b.y);
}

std::pair<std::string, std::string> day11::solve(std::ifstream f)
{
  std::vector<Galaxy> galaxies;
  std::string line;
  long long maxy = 0;
  long long maxx = 0;
  {
    long long y = 0;
    while (getline(f, line))
    {
      for (long long x = 0; x < line.size(); x++)
      {
        if (line.at(x) == '#') 
        {
          galaxies.push_back(Galaxy(x, y));
        }
      }
      y++;
      maxy++;
      if (maxx == 0) maxx = line.size();
    }
  }

  std::vector<Galaxy> galaxies2 = galaxies;

  for (long long y = maxy-1; y >= 0; y--)
  {
    if (std::find_if(galaxies.begin(), galaxies.end(), [y](Galaxy& g){return g.y == y;}) == galaxies.end())
    {
      for (auto& galaxy : galaxies) if (galaxy.y>y) galaxy.y++;
    }
  }
  for (long long x = maxx-1; x >= 0; x--)
  {
    if (std::find_if(galaxies.begin(), galaxies.end(), [x](Galaxy& g){return g.x == x;}) == galaxies.end())
    {
      for (auto& galaxy : galaxies) if (galaxy.x>x) galaxy.x++;
    }
  }

  for (long long y = maxy-1; y >= 0; y--)
  {
    if (std::find_if(galaxies2.begin(), galaxies2.end(), [y](Galaxy& g){return g.y == y;}) == galaxies2.end())
    {
      for (auto& galaxy : galaxies2) if (galaxy.y>y) galaxy.y += 999999;
    }
  }
  for (long long x = maxx-1; x >= 0; x--)
  {
    if (std::find_if(galaxies2.begin(), galaxies2.end(), [x](Galaxy& g){return g.x == x;}) == galaxies2.end())
    {
      for (auto& galaxy : galaxies2) if (galaxy.x>x) galaxy.x += 999999;
    }
  }

  long long sum = 0;
  for (long long i = 0; i<galaxies.size(); i++)
  {
    for (long long j = i+1; j<galaxies.size(); j++)
    {
      sum += dist(galaxies.at(i), galaxies.at(j));
    }
  }
  long long sum2 = 0;
  for (long long i = 0; i<galaxies2.size(); i++)
  {
    for (long long j = i+1; j<galaxies2.size(); j++)
    {
      sum2 += dist(galaxies2.at(i), galaxies2.at(j));
    }
  }
  return {std::to_string(sum), std::to_string(sum2)};
}