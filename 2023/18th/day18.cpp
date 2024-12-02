#include "../solutions.hh"

struct Cube
{
  Cube() : isDug(false), color(-1) {};
  Cube(bool isDug, int color) : isDug(isDug), color(color) {};
  void dig(std::string& color_in)
  {
    isDug = true;
    color = stoi(color_in);
  }
  void dig() {isDug = true;};
  bool isDug = false;
  // -1 = not painted
  int color = -1;
  char inside = 1;
};

void fill_pool(std::deque<std::deque<Cube>>& ground, int x, int y)
{
  ground.at(y).at(x).dig();

  if ( y>0                      && !ground.at(y-1).at(x)  .isDug ) fill_pool(ground, y-1, x);
  if ( x<ground.at(y).size()-1  && !ground.at(y)  .at(x+1).isDug ) fill_pool(ground, y, x+1);
  if ( y<ground.size()-1        && !ground.at(y+1).at(x)  .isDug ) fill_pool(ground, y+1, x);
  if ( x>0                      && !ground.at(y)  .at(x-1).isDug ) fill_pool(ground, y, x-1);
}

std::pair<std::string, std::string> day18::solve(std::ifstream f)
{
  std::deque<std::deque<Cube>> ground({{Cube()}});

  std::string line;
  int x = 0;
  int y = 0;
  int origin_x = 0;
  int origin_y = 0;
  while (getline(f, line))
  {
    char dir = line.at(0);
    int dist = (line.size() == 13) ? (line.at(2)-48) : stoi(line.substr(2, 2));
    std::string color = "0x" + line.substr(((line.size() == 13) ? 6 : 7), 6);
    for (int i = 0; i < dist; ++i)
    {
      if (dir == 'U')
      {
        if (y == 0)
        {
          ground.push_front(std::deque<Cube>(ground.front().size(), Cube()));
          ground.front().at(x).dig(color);
          origin_y++;
        }
        else
        {
          ground.at(--y).at(x).dig(color);
        }
      }
      else if (dir == 'D')
      {
        if (y == ground.size()-1)
        {
          ground.push_back(std::deque<Cube>(ground.back().size(), Cube()));
          ground.back().at(x).dig(color);
        }
        else
        {
          ground.at(++y).at(x).dig(color);
        }
      }
      else if (dir == 'L')
      {
        if (x == 0)
        {
          for (auto& row : ground) row.push_front(Cube());
          ground.at(y).front().dig(color);
          origin_x++;
        }
        else
        {
          ground.at(y).at(--x).dig(color);
        }
      }
      else if (dir == 'R')
      {
        if (x == ground.at(y).size()-1)
        {
          for (auto& row : ground) row.push_back(Cube());
          ground.at(y).back().dig(color);
        }
        else
        {
          ground.at(y).at(++x).dig(color);
        }
      }
    }
  }

  //fill_pool(ground, origin_x, origin_y+1);

  int sum = 0;
  std::ofstream file;
  file.open("output.txt");
  for (auto& row : ground) 
  {
    for (auto col : row)
    {
      sum++;
      file << (col.isDug ? '#' : '.') << ',';
    }
    file << std::endl;
  }

  return {std::to_string(sum),""};
}