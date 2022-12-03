#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

int priority(char a) {return (int)a - (std::islower(a) ? 96 : 38);}

int sol()
{
  std::ifstream file("input.txt");
  std::string row;
  int prioritySum1 = 0, prioritySum2 = 0;
  std::vector<std::string> group;
  while (std::getline(file, row))
  {
    for (char a : row)
    {
      if (row.find(a, row.size() / 2) != std::string::npos)
      {
        prioritySum1 += priority(a);
        break;
      }
    }
    group.push_back(row);
    if (group.size() == 3)
    {
      for (char b : group.at(0))
      {
        if (group.at(1).find(b) != std::string::npos && group.at(2).find(b) != std::string::npos)
        {
          prioritySum2 += priority(b);
          break;
        }
      }
      group.clear();
    }
  }
  //std::cout << prioritySum1 << std::endl << prioritySum2 << std::endl;
  return 0;
}

int main()
{
  auto start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i<1000; i++) sol();
  auto stop = std::chrono::high_resolution_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
  std::cout << duration.count()/1000 << " mikrosekuntia" << std::endl;
}
