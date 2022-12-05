#include "../solutions.hh"

int readCrates(std::ifstream& file, std::vector<std::deque<char>>& crates)
{
  std::string a;
  while (getline(file, a) && a != "")
  {
    for (int i = 0; i<a.size(); i++)
    {
      if ((i+1)%2 == 0 && (i+1)%4 != 0)
      {
        if (isdigit(a.at(i))) break;
        if (crates.size() < (i/4)+1) crates.push_back({});
        if (a[i]!=' ') crates.at(i/4).push_front(a[i]);
      }
    }
  }
  return crates.size();
}

bool getDirections(std::ifstream& file, std::array<int, 3>& dir)
{
  int i = 0, is2dig = 0;
  dir.fill(0);
  char a;
  while (file.get(a))
  {
    if (!std::isdigit(a)) 
    {
      i += is2dig?1:0;
      is2dig = 0;
    }
    else
    {
      dir[i] = is2dig++?(dir[i]*10)+(a-'0'):(a-'0');
    }
    if (dir[2] != 0) return true;
  }
  return false;
}

std::pair<std::string, std::string> day5(std::ifstream file)
{
  std::vector<std::deque<char>> crates;
  int stackCount = readCrates(file, crates);
  std::vector<std::deque<char>> crates2 = crates;
  std::array<int, 3> dir;
  while (getDirections(file, dir))
  {
    for (int i=0; i<dir[0]; i++)
    {
      crates[dir[2]-1].push_back(crates[dir[1]-1].back());
      crates[dir[1]-1].pop_back();
      crates2[dir[2]-1].push_back(crates2[dir[1]-1].back());
      crates2[dir[1]-1].pop_back();
    }
    std::reverse(crates2[dir[2]-1].end()-dir[0], crates2[dir[2]-1].end());
  }
  std::string a,b;
  for (auto stack : crates)
    a.push_back(stack.back());
  for (auto stack : crates2)
    b.push_back(stack.back());
  return {a, b};
}