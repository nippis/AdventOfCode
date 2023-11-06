#include "../solutions.hh"

static int x=1, i=0, sum=0;
int print()
{
  sum += (!((i+1)%20)&&(i+1)%40)*(i+1)*x; // Part 1
  //std::cout<<(char)(i%40>=x-1&&i%40<=x+1?35:32)<<(char)(++i%40==0?10:0); // Part2
  return 1;
}

std::pair<std::string, std::string> day10(std::ifstream file)
{
  for (std::string row; getline(file, row) && print(); x+=row.size()>4?std::stoi(row.substr(5)):0)
    if (row.substr(0, 4) == "addx") print();
  return {std::to_string(sum), "0"};
}