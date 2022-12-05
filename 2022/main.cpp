#include <chrono>
#include "solutions.hh"

void printRow(int i, std::pair<std::string, std::string>& values, int dur, int dur2)
{
  std::string a = values.first;
  std::string b = values.second;
  std::string du = std::to_string(dur);
  std::string du2 = std::to_string(dur2/1000);
  std::string d = std::to_string(i);
  std::cout << "|" 
  << whitespace(5-d.size()) << d 
  << whitespace(15-a.size()) << a 
  << whitespace(15-b.size()) << b 
  << whitespace(7-du.size()) << du << " \xC2\xB5" << "s" 
  << whitespace(7-du2.size()) << du2 << " \xC2\xB5" << "s" 
  << " |"<< std::endl;
}

int main(int argc, char** argv)
{
   std::vector<std::pair<std::string, std::string>(*)()> dayFunctions =
    {
      [](){return day1();},
      [](){return day2(std::ifstream("inputs/input2.txt"));},
      [](){return day3(std::ifstream("inputs/input3.txt"));},
      [](){return day4(std::ifstream("inputs/input4.txt"));},
      [](){return day5(std::ifstream("inputs/input5.txt"));},
    };

  std::cout << "| Day    Part 1          Part 2         Time    Avg 1000 |" << std::endl;
  std::cout << "|--------------------------------------------------------|" << std::endl;
  int i = 1;
  for (auto func : dayFunctions)
  {
    auto start = std::chrono::high_resolution_clock::now();
    auto values = func();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    start = std::chrono::high_resolution_clock::now();
    if (argc > 1) for (int i = 0; i<1000; i++) func();
    stop = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    printRow(i, values, duration.count(), duration2.count());
    i++;
  }
}