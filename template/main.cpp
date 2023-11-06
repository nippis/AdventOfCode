#include <chrono>
#include "solutions.hh"

void printRow(int i, std::pair<std::string, std::string>& values, int dur, int dur2)
{
  std::string a = values.first;
  std::string b = values.second;
  std::string du = std::to_string(dur);
  std::string du2 = std::to_string(dur2/10000);
  std::string d = std::to_string(i);
  std::cout << "|" 
  << whitespace(5-d.size()) << d 
  << whitespace(15-a.size()) << a 
  << whitespace(15-b.size()) << b 
  << whitespace(2);
  std::printf("%.3f", (double)dur/1000);
  std::cout << " ms" 
  << whitespace(3 - ((dur<10000)?0:1));
  std::printf("%.3f", (double)dur2/10000000);
  std::cout << " ms" 
  << "  |"<< std::endl;
}

int main(int argc, char** argv)
{
   std::vector<std::pair<std::string, std::string>(*)()> dayFunctions =
    {
      [](){return day1 ::solve(std::ifstream("inputs/input1.txt"));},
      [](){return day2 ::solve(std::ifstream("inputs/input2.txt"));},
      [](){return day3 ::solve(std::ifstream("inputs/input3.txt"));},
      [](){return day4 ::solve(std::ifstream("inputs/input4.txt"));},
      [](){return day5 ::solve(std::ifstream("inputs/input5.txt"));},
      [](){return day6 ::solve(std::ifstream("inputs/input6.txt"));},
      [](){return day7 ::solve(std::ifstream("inputs/input7.txt"));},
      [](){return day8 ::solve(std::ifstream("inputs/input8.txt"));},
      [](){return day9 ::solve(std::ifstream("inputs/input9.txt"));},
      [](){return day10::solve(std::ifstream("inputs/input10.txt"));},
      [](){return day11::solve(std::ifstream("inputs/input11.txt"));},
      [](){return day12::solve(std::ifstream("inputs/input12.txt"));},
      [](){return day13::solve(std::ifstream("inputs/input13.txt"));},
      [](){return day14::solve(std::ifstream("inputs/input14.txt"));},
      [](){return day15::solve(std::ifstream("inputs/input15.txt"));},
      [](){return day16::solve(std::ifstream("inputs/input16.txt"));},
      [](){return day17::solve(std::ifstream("inputs/input17.txt"));},
      [](){return day13::solve(std::ifstream("inputs/input18.txt"));},
      [](){return day13::solve(std::ifstream("inputs/input19.txt"));},
      [](){return day13::solve(std::ifstream("inputs/input20.txt"));},
      [](){return day13::solve(std::ifstream("inputs/input21.txt"));},
      [](){return day13::solve(std::ifstream("inputs/input22.txt"));},
      [](){return day13::solve(std::ifstream("inputs/input23.txt"));},
      [](){return day13::solve(std::ifstream("inputs/input24.txt"));},
    };

  std::cout << "| Day    Part 1          Part 2         Time     Avg 10000 |" << std::endl;
  std::cout << "|----------------------------------------------------------|" << std::endl;
  int i = 1;
  for (auto func : dayFunctions)
  {
    auto start = std::chrono::high_resolution_clock::now();
    auto values = func();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    start = std::chrono::high_resolution_clock::now();
    if (argc > 1) for (int i = 0; i<10000; i++) func();
    stop = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    printRow(i, values, duration.count(), duration2.count());
    i++;
  }
}