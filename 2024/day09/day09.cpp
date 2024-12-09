#include "../solutions.hh"

std::pair<std::string, std::string> day09::solve(std::ifstream f)
{
  std::vector<int> disk;
  char input;
  int id = 0;
  std::string row;
  while (input = f.get())
  {
    if (input == std::char_traits<char>::eof())
      break;
    disk.insert(disk.end(), input-48, id);
    id++;
    input = f.get();
    if (input == std::char_traits<char>::eof())
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
  return {std::to_string(sum),""};
}