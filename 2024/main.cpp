#include <chrono>
#include "solutions.hh"
#include <format>

void printRow(int i, std::pair<std::string, std::string>& values, int dur, int dur2)
{
  std::string a = values.first;
  std::string b = values.second;
  std::string d = std::to_string(i);
  std::cout << "|" 
  << whitespace(3-d.size()) << d 
  << whitespace(20-a.size()) << a 
  << whitespace(20-b.size()) << b 
  << whitespace(2);
  std::printf("%.3f", (double)dur/1000);
  std::cout << " ms" 
  << whitespace(3 - ((dur<10000)?0:1));
  std::printf("%.3f", (double)dur2/1000000);
  std::cout << " ms" 
  << "  |"<< std::endl;
}

int main(int argc, char** argv)
{
   std::vector<std::pair<std::string, std::string>(*)(std::ifstream)> dayFunctions =
    {
      day01::solve,
      day02::solve,
      day03::solve,
      day04::solve,
      day05::solve,
      day06::solve,
      day07::solve,
      day08::solve,
      day09::solve,
      day10::solve,
      day11::solve,
      day12::solve,
      day13::solve,
      day14::solve,
      day15::solve,
      day16::solve,
      day17::solve,
      day18::solve,
      day19::solve,
      day20::solve,
      day21::solve,
      day22::solve,
      day23::solve,
      day24::solve,
      day25::solve,
    };

  std::cout << "| Day  Part 1               Part 2              Time     Avg 1000  |" << std::endl;
  std::cout << "|------------------------------------------------------------------|" << std::endl;
  int i = 1;
  for (auto func : dayFunctions)
  {
    auto start = std::chrono::high_resolution_clock::now();
    std::string inputFile = std::format("inputs/input{}.txt", i);
    auto values = func(std::ifstream(inputFile));
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    start = std::chrono::high_resolution_clock::now();
    if (argc > 1) for (int i = 0; i<1000; i++) func(std::ifstream(inputFile));
    stop = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    printRow(i, values, duration.count(), duration2.count());
    i++;
  }
}