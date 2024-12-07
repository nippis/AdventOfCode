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
  matrix(){}
  matrix(matrix& i) : map(i.getMap()){}

  void push_back(std::string s) {map.push_back(s);}
  char& at(vec l) {return map.at(l.x).at(l.y);}
  int addX() {return ++xCount;}
  int addO() {return ++oCount;}

  auto size() const {return map.size();}
  auto row(std::string::size_type i) const {return map.at(i);}
  const char at(vec l) const {return map.at(l.x).at(l.y);}
  const char next(vec l, vec d) const {return map.at((l+d).x).at((l+d).y);}
  const char prev(vec l, vec d) const {return map.at((l-d).x).at((l-d).y);}
  int getXCount(){return xCount;}
  int getOCount(){return oCount;}
  std::vector<std::string> getMap(){return map;}

  bool out(vec l) const
  {
    return !(l.x >= 0 && l.x < size() && l.y >= 0 && l.y < row(l.x).size());
  }

  private:
  std::vector<std::string> map;
  int xCount = 1;
  int oCount = 0;
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

bool findLoop(vec l, vec v, matrix* m)
{
  if (m->out(l))
    return false;
  if (m->at(l) == '#')
  {
    return findLoop(l-v, v.normal(), m);
  }
  if (m->at(l) == dir(v))
    return true;
  m->at(l) = dir(v);
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
  if (m.at(l) == dir(v))
    return false;
  matrix* copy = new matrix(m);
  if (!m.out(l+v))
    copy->at(l+v) = '#';
  //if (findLoop(l, v.normal(), copy))
  {
    //std::cout << "Travelled: " << m.getXCount() << " Found loop at: " << l.x << ", " << l.y << std::endl;
    m.addO();
  }
  delete copy;
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
    auto pos = row.find('^');
    if (pos != std::string::npos)
      loc = {map.size()-1, pos};
  }

  move(loc, v, map);
  
  return {std::to_string(map.getXCount()), std::to_string(map.getOCount())};
}