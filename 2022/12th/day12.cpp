#include <algorithm>
#include <cmath>
#include <sstream>
#include <windows.h>

#include "../solutions.hh"

struct coord
{
  int x;
  int y;
};

double distance(coord a, coord b)
{
  return std::sqrt(std::pow(b.x-a.x,2) + std::pow(b.y-a.y, 2));
}

struct mapPoint
{
  mapPoint(coord loc, char height) : m_loc(loc), m_height(height) {}
  bool m_isDest = false;
  bool m_deadEnd = false;
  bool m_potential_route = false;
  bool m_visited = false;
  char m_height;
  coord m_loc;
  std::vector<mapPoint*> m_routes;
};

// Returns the current point
mapPoint* readMap(std::vector<std::vector<mapPoint*>>& map, std::ifstream& file)
{
  std::string row;
  mapPoint* current;
  coord dest;
  int x = 0;
  while (getline(file, row))
  {
    map.push_back({});
    for (int y=0; y<row.size(); y++)
    {
      map.at(x).push_back(new mapPoint({x, y}, row.at(y)));
      if (row.at(y) == 'S')
      {
        current = map.at(x).back();
        current->m_height = 'a';
      }
      else if (row.at(y) == 'E')
      {
        map.at(x).back()->m_height = 'z';
        map.at(x).back()->m_isDest = true;
        dest.x = x;
        dest.y = y;
      }
    }
    x++;
  }
  //std::cout << std::endl;
  std::cout << "You are going from (" << current->m_loc.x << ", " << current->m_loc.y << ") to (" << dest.x << ", " << dest.y << ")" << std::endl;
  return current;
}

void connectPoints(std::vector<std::vector<mapPoint*>>& map)
{
  for (int x=0; x<map.size(); x++)
  {
    for (int y=0; y<map.at(x).size(); y++)
    {
      // down (1, 0), right (0, 1)
      if (y<map.at(x).size()-1 && 
          map.at(x).at(y+1)->m_height <= map.at(x).at(y)->m_height+1)
      {
        map.at(x).at(y)->m_routes.push_back(map.at(x).at(y+1));
      }
      if (x>0 && 
          map.at(x-1).at(y)->m_height <= map.at(x).at(y)->m_height+1)
      {
        map.at(x).at(y)->m_routes.push_back(map.at(x-1).at(y));
      }
      if (x<map.size()-1 && 
          map.at(x+1).at(y)->m_height <= map.at(x).at(y)->m_height+1)
      {
        map.at(x).at(y)->m_routes.push_back(map.at(x+1).at(y));
      }
      if (y>0 && 
          map.at(x).at(y-1)->m_height <= map.at(x).at(y)->m_height+1)
      {
        map.at(x).at(y)->m_routes.push_back(map.at(x).at(y-1));
      }
    }
  }
}

void printHeights(const std::vector<std::vector<mapPoint*>>& map)
{
  std::stringstream ss;
  for (auto row : map)
  {
    for (auto col : row)
    {
      ss << (col->m_visited?'@':col->m_height);
    }
    ss << std::endl;
  }
  ss << std::endl;
  std::cout << ss.str();
  std::cin;
  Sleep(1);
}

int count = 0;

void findRoute(std::vector<std::vector<mapPoint*>>& map, mapPoint* startingPoint, std::vector<int>& lengths, int& depth)
{
  depth++;

  depth--;
}

std::pair<std::string, std::string> day12(std::ifstream file)
{
  std::vector<std::vector<mapPoint*>> map;
  mapPoint* current = readMap(map, file);
  connectPoints(map);

  std::vector<int> routeLengths;
  int depth = 0;
  std::cout << "Searching for route" << std::endl;
  findRoute(map, current, routeLengths, depth);
  std::cout << "Shortest route is ";
  return {"", ""};
}