#include "../solutions.hh"
#include <sstream>
#include <ranges>
#include <numeric>

using int_type = long long;
namespace views = std::views;
namespace ranges = std::ranges;

std::pair<std::string, std::string> day6::solve(std::ifstream f)
{
	/*
  std::string line;
  std::vector<std::vector<std::string>> allLines;
  while (getline(f, line))
  {
    std::istringstream lineStream(line);
    allLines.push_back(views::istream<std::string>(lineStream)
      | ranges::to<std::vector<std::string>>());
  }

  auto operators = allLines.back() 
    | views::transform([](auto s)
    {
      return s == "+" ? [](int_type a, int_type b){return a+b;} : [](int_type a, int_type b){return a*b;};
    });
    
  auto resultVector = allLines
    | views::take(1)
    | views::join
    | views::transform([](auto s){return stoll(s);})
    | ranges::to<std::vector<int_type>>();

  for (auto line : views::counted(allLines.begin()+1, allLines.size()-2)
    | views::transform([](auto& line){return line | views::transform([](auto s){return stoll(s);});}))
  {
    for (auto parameters : views::zip(resultVector, operators, line))
    {
      auto [left, operation, right] = parameters;
      left = operation(left, right);
    }
  }

  int_type result1 = ranges::fold_left(resultVector, (int_type)0, std::plus<int_type>());
  return {std::to_string(result1),""};
	*/
	return {"",""};
}
