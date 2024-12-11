#include "../solutions.hh"

struct vec
{
  int x, y;
  vec(int a, int b) : x(a), y(b) {}
  vec operator+(vec i) const {return {x+i.x, y+i.y};}
  vec operator-(vec i) const {return {x-i.x, y-i.y};}
  vec operator*(int i) const {return {x*i, y*i};}
  bool operator==(vec i) const {return x==i.x && y==i.y;}
  vec normal() const {return vec(y, -x);}
};

bool onMap(vec point, vec size)
{
  return point.x >= 0 && point.x < size.x && point.y >= 0 && point.y < size.y;
}

std::pair<std::string, std::string> day08::solve(std::ifstream f)
{
  std::unordered_map<char, std::vector<vec>> antennas;
  std::vector<std::vector<bool>> antinodes;
  std::string row;
  int x = 0;
  while(getline(f, row))
  {
    antinodes.push_back({});
    for (int y = 0; y < row.size(); ++y)
    {
      if (row.at(y) != '.')
      {
        if (antennas.find(row.at(y)) == antennas.end())
          antennas.insert({row.at(y), {}});
        antennas.at(row.at(y)).push_back(vec(x,y));
      }
      antinodes.back().push_back(false);
    }
    ++x;
  }

  std::vector<std::vector<bool>> antinodes2(antinodes);
  
  for (auto freq : antennas)
    for (auto antenna1 : freq.second)
      for (auto antenna2 : freq.second)
      {
        if (antenna1 == antenna2)
          continue;
        vec antinode1 = antenna2 + (antenna2 - antenna1);
        vec antinode2 = antenna1 - (antenna2 - antenna1);
        if (onMap(antinode1, vec(antinodes.size(), antinodes.back().size())))
          antinodes.at(antinode1.x).at(antinode1.y) = true;
        if (onMap(antinode2, vec(antinodes.size(), antinodes.back().size())))
          antinodes.at(antinode2.x).at(antinode2.y) = true;
      }
  int sum = 0;
  for (auto x : antinodes)
   for (auto y : x)
    sum += y;

  return {std::to_string(sum),""};
}