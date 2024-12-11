#include "../solutions.hh"

struct matrix;

struct vec
{
  int x, y;
  vec(int a, int b) : x(a), y(b) {}
  vec operator+(vec i) const {return {x+i.x, y+i.y};}
  vec operator-(vec i) const {return {x-i.x, y-i.y};}
  bool operator==(vec i) const {return x==i.x && y==i.y;}
  vec normal() const {return vec(y, -x);}
};

struct matrix
{
  matrix():start({0,0}){}
  matrix(const matrix& i) : start(i.getStart()) {map = i.getMap(); visits = i.getVisits();}

  void push_back(std::string s) {map.push_back(s);}
  char& at(vec l) {return map.at(l.x).at(l.y);}
  int addX() {return ++xCount;}

  auto size() const {return map.size();}
  auto row(std::string::size_type i) const {return map.at(i);}
  const char at(vec l) const {return map.at(l.x).at(l.y);}
  int getXCount(){return xCount;}
  std::vector<std::string> getMap() const {return map;}
  std::vector<std::vector<int>> getVisits() const {return visits;}
  std::vector<std::vector<int>>& getVisits() {return visits;}
  void setStart(vec i) {start = i;}
  vec getStart() const {return start;}

  bool out(vec l) const
  {
    return !(l.x >= 0 && l.x < size() && l.y >= 0 && l.y < row(l.x).size());
  }

  private:
  std::vector<std::string> map;
  std::vector<std::vector<int>> visits;
  int xCount = 1;
  vec start;
};

char dir(vec d)
{
  if (d == vec(0, 1))
    return 'U';
  if (d == vec(1, 0))
    return 'R';
  if (d == vec(0, -1))
    return 'D';
  if (d == vec(-1, 0))
    return 'L';
  return 'X';
}

bool findLoop(vec l, vec v, matrix& m)
{
  if (m.out(l))
    return false;
  if (m.at(l) == dir(v) || m.getVisits().at(l.x).at(l.y) > 1000)
    return true;
  if (m.at(l) == '#')
  {
    return findLoop(l-v, v.normal(), m);
  }
  m.at(l) = dir(v);
  ++m.getVisits().at(l.x).at(l.y);
  return findLoop(l+v, v, m);
}

bool move(vec l, vec v, matrix& m)
{
  if (m.out(l))
    return true;
  if (m.at(l) == '#')
  {
    return move(l-v, v.normal(), m);
  }
  if (m.at(l) == '.')
    m.addX();
  m.at(l) = dir(v);
  return move(l+v, v, m);
}

std::pair<std::string, std::string> day06::solve(std::ifstream f)
{
  matrix map;
  vec loc = {0,  0};
  vec v = {-1, 0};
  std::string row;
  while (getline(f, row))
  {
    map.push_back(row);
    map.getVisits().push_back(std::vector<int>(row.size(), 0));
    auto pos = row.find('^');
    if (pos != std::string::npos)
    {
      loc = {map.size()-1, pos};
      map.setStart(loc);
    }
  }

  int sum = 0;
  move(loc, v, map);
  for (int x = 0; x < map.size(); ++x)
    for (int y = 0; y < map.row(x).size(); ++y)
    {
      matrix copy(map);
      if (!(loc == vec(x, y)); map.at({x, y}) != '#' && findLoop({x, y}, v, copy))
        ++sum;
    }
      
  
  return {std::to_string(map.getXCount()), std::to_string(sum)};
}