#include "../solutions.hh"

struct chunk
{
  int size, id;
};

std::vector<int>::iterator findSpace(std::vector<int>::iterator first, std::vector<int>::iterator last, int size)
{
  while (first != last)
  {
    for (int i = 0; i<size; ++i)
    {
      if (*(first+i) != -1)
        break;
      if (i == size-1)
        return first;
    }
    ++first;
  }
}

std::pair<std::string, std::string> day09::solve(std::ifstream f)
{
  std::vector<int> disk;
  std::vector<int> disk2(disk);
  char input;
  int id = 0;
  std::string row;
  while (f.get(input))
  {
    disk.insert(disk.end(), input-48, id);
    id++;
    if (!f.get(input))
      break;
    disk.insert(disk.end(), input-48, -1);
  }

  int i = 0;
  while (i < disk.size())
  {
    if (disk.at(i) == -1 && disk.back() != -1)
    {
      disk.at(i) = disk.back();
      disk.pop_back();
    }
    else if (disk.at(i) == -1)
      disk.pop_back();
    else if (disk.back() != -1)
      ++i;
    else
    {
      disk.pop_back();
      ++i;
    }
  }
  long long sum = 0;
  for (int i = 0; i < disk.size(); ++i)
    sum += disk.at(i)*i;

  int id = 10000;
  for (int j = disk.size()-1; j >= 0; --j)
  {
    
  }
  
  return {std::to_string(sum),""};
}