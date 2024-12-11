#include "../solutions.hh"

struct node
{
  node(int h) : height(h) {}
  int height;
  std::vector<node*> trails;
};

std::pair<std::string, std::string> day10::solve(std::ifstream f)
{
  std::vector<std::vector<node>> map;
  std::string row;
  while (getline(f, row))
  {
    map.push_back({});
    for (char a : row)
      map.back().push_back(node(a-48));
  }
  for (int x = 0; x < map.size(); ++x)
  {
    for (int y = 0; y < map.at(x).size(); ++y)
    {
      if (x > 0)
        if (map.at(x-1).at(y).height - map.at(x).at(y).height == 1)
          map.at(x).at(y).trails.push_back(&map.at(x-1).at(y));
      if (x < map.size()-1)
        if (map.at(x+1).at(y).height - map.at(x).at(y).height == 1)
          map.at(x).at(y).trails.push_back(&map.at(x+1).at(y));
      if (y > 0)
        if (map.at(x).at(y-1).height - map.at(x).at(y).height == 1)
          map.at(x).at(y).trails.push_back(&map.at(x).at(y-1));
      if (y < map.back().size()-1)
        if (map.at(x-1).at(y).height - map.at(x).at(y).height == 1)
          map.at(x).at(y).trails.push_back(&map.at(x).at(y+1));
    }
  }
  return {"",""};
}