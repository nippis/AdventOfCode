#include "../solutions.hh"

struct cpu
{
  int x = 1;
  int i = 0;
  int strength_sum = 0;
  void sum_signal_strength() {strength_sum += i*x;}
  void print_char()
  {
    if (x-1==i%40 || x==i%40 || x+1 == i%40) std::cout << "# ";
    else std::cout <<"  ";
    if (++i%40 == 0) std::cout << std::endl;
  }
  void noop()
  {
    print_char();
  }
  void addx(int add)
  {
    for (int j : {0, 1})
    {
      print_char();
    }
    x += add;
  }
};

std::pair<std::string, std::string> day10(std::ifstream file)
{
  std::string row;
  cpu c;
  while (getline(file, row))
  {
    if (row.substr(0, 4) == "noop") c.noop();
    else if (row.substr(0, 4) == "addx") c.addx(std::stoi(row.substr(5)));
  }
  return {std::to_string(c.strength_sum), "0"};
}