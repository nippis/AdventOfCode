#include "../solutions.hh"
#include <ranges>
#include <functional>

std::pair<std::string, std::string> day4::solve(std::ifstream f)
{
  unsigned int result = 0;
  std::vector<bool> rolls;
  std::string row;
  int width = 0;
  while (std::getline(f, row))
  {
    if (!width)
      width = row.length();
    for (char a : row)
      rolls.push_back(a == '@' ? true : false);
  }

  auto& rolls = std::views::istream<std::string>(f);
  int width = rolls.at(0).size();
  std::vector<int> uai = {-width-1, -width, -width+1, -1, 1, width-1, width, width+1};

  namespace views = std::views;
  namespace ranges = std::ranges;
  auto result = rolls
    | views::enumerate
    | views::transform([&](auto t){
      auto&& [i, s] = t;
      return s
        | views::enumerate
        | views::transform([&](auto tt){
          auto&& [j, c] = tt;
          return ranges::distance(
            {rolls.at(i-1)}
              | views::transform([&](auto x){
                return x+
              })
          );
        });
    });

  result = std::ranges::distance
  (
    rolls | 
    views::enumerate |
    views::filter([&](auto x)
    {
      return true;
    })
  );

  std::ranges::for_each(std::views::iota(0u, rolls.size()), [&](int i)
  {
    result += std::ranges::distance(
      unfiltered_adjacent_indices |
      std::views::transform([&](int x){return x+i;}) |
      std::views::filter([&](int x){return x >= 0 && x < rolls.size();}) |
      std::views::filter([&](int x){return rolls.at(x);}) |
      std::views::filter([&](int x){return abs(x % width - i % width) <=1;})) < 4;
  });

  return {std::to_string(result),""};
}