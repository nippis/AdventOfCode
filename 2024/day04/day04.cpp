#include "../solutions.hh"

struct point
{
  int x, y;
  void operator+=(const point& r) {x=x+r.x; y=y+r.y;}
};

constexpr std::string word = "XMAS";

std::pair<std::string, std::string> day04::solve(std::ifstream f)
{
  std::string row;
  std::vector<std::string> wordGrid;
  while (getline(f, row))
  {
    wordGrid.push_back({});
    for (char a : row)
      wordGrid.back().push_back(a);
  }

  const std::vector<point> directions = {{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1},{-1, 0},{-1,-1}};
  int sum = 0;
  for (int x = 0; x < wordGrid.size(); ++x)
  for (int y = 0; y < wordGrid.at(x).size(); ++y)
  if (wordGrid.at(x).at(y) == word.front())
  for (auto direction : directions)
  {
    point location = {x, y};
    for (char a : word.substr(1))
    {
      location += direction;
      if (location.x<0 || location.y<0 || 
          location.x >= wordGrid.size() || location.y >= wordGrid.at(x).size())
        break;
      if (wordGrid.at(location.x).at(location.y) != a)
        break;
      if (a == word.back())
        ++sum;
    }
  }

  int sum2 = 0;
  for (int x = 1; x < wordGrid.size()-1; ++x)
  for (int y = 1; y < wordGrid.at(x).size()-1; ++y)
  if (wordGrid.at(x).at(y) == 'A' &&
      (wordGrid.at(x-1).at(y-1) == 'M' && wordGrid.at(x+1).at(y+1) == 'S' ||
      wordGrid.at(x+1).at(y+1) == 'M' && wordGrid.at(x-1).at(y-1) == 'S') &&
      (wordGrid.at(x+1).at(y-1) == 'M' && wordGrid.at(x-1).at(y+1) == 'S' ||
      wordGrid.at(x-1).at(y+1) == 'M' && wordGrid.at(x+1).at(y-1) == 'S'))
      ++sum2;

  return {std::to_string(sum),std::to_string(sum2)};
}