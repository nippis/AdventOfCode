#include "../solutions.hh"

struct Galaxy
{
  Galaxy(int x, int y) : x(x), y(y) {}
  int x;
  int y;
};

int dist(const Galaxy& a, const Galaxy& b)
{
  return abs(a.x - b.x) + abs(a.y - b.y);
}

std::pair<std::string, std::string> day11::solve(std::ifstream f)
{
  std::vector<Galaxy> galaxies;
  std::string line;
  int maxy = 0;
  int maxx = 0;
  {
    int y = 0;
    while (getline(f, line))
    {
      for (int x = 0; x < line.size(); x++)
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

  for (int y = maxy-1; y >= 0; y--)
  {
    if (std::find_if(galaxies.begin(), galaxies.end(), [y](Galaxy& g){return g.y == y;}) == galaxies.end())
    {
      for (auto& galaxy : galaxies) if (galaxy.y>y) galaxy.y++;
    }
  }
  for (int x = maxx-1; x >= 0; x--)
  {
    if (std::find_if(galaxies.begin(), galaxies.end(), [x](Galaxy& g){return g.x == x;}) == galaxies.end())
    {
      for (auto& galaxy : galaxies) if (galaxy.x>x) galaxy.x++;
    }
  }

  int sum = 0;
  for (int i = 0; i<galaxies.size(); i++)
  {
    for (int j = i+1; j<galaxies.size(); j++)
    {
      sum += dist(galaxies.at(i), galaxies.at(j));
    }
  }
  return {std::to_string(sum),""};
}