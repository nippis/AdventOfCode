#include "../solutions.hh"

std::pair<std::string, std::string> day05::solve(std::ifstream f)
{
  std::vector<std::pair<int, int>> rules;
  std::string row;
  while (getline(f, row) && !row.empty())
    rules.push_back(std::make_pair(std::stoi(row.substr(0, 2)), std::stoi(row.substr(3, 2))));
  int sum1 = 0, sum2 = 0;
  while (getline(f, row))
  {
    std::string update;
    for (int i = 0; i < row.size(); i += 3)
      update.push_back(std::stoi(row.substr(i, 2)));
    auto cmp = [=](int a, int b) 
    {
      for (auto r : rules) if (r.first == a && r.second == b || r.first == b && r.second == a) 
        return r.first == a;
      return false;
    };
    if (std::is_sorted(update.begin(), update.end(), cmp) && (sum1 += update.at(update.size()/2)))
      continue;
    std::sort(update.begin(), update.end(), cmp);
    sum2 += update.at(update.size()/2);
  }
  return {std::to_string(sum1), std::to_string(sum2)};
}