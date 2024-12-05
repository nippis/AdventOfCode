#include "../solutions.hh"

using rulePair = std::pair<int, int>;

std::pair<std::string, std::string> day05::solve(std::ifstream f)
{
  std::vector<rulePair> rules;
  std::vector<std::vector<int>> updates;

  std::string row;
  while (getline(f, row))
  {
    if (row.empty())
      break;
    rules.push_back(std::make_pair(std::stoi(row.substr(0, 2)), std::stoi(row.substr(3, 2))));
  }
  while (getline(f, row))
  {
    updates.push_back({});
    for (int i = 0; i < row.size(); i += 3)
      updates.back().push_back(std::stoi(row.substr(i, 2)));
  }

  int sum = 0;
  int sum2 = 0;
  for (auto update : updates)
  {
    if (std::all_of(rules.begin(), rules.end(),
      [=](auto r)
      {
        return
          std::find(update.begin(), update.end(), r.first) != update.end() &&
          std::find(update.begin(), update.end(), r.second) != update.end() &&
          std::find(std::find(update.begin(), update.end(), r.first), update.end(), r.second) != update.end();
      }
    ))
      sum += update.at(update.size()/2);
    else
    {
      std::sort(update.begin(), update.end(), 
        [=](int a, int b)
        {
          for (auto rule : rules)
            if (rule.first == a && rule.second == b || rule.first == b && rule.second == a)
              return rule.first == a;
          return false;
        });
      sum2 += update.at(update.size()/2);
    }
  }
  return {std::to_string(sum), std::to_string(sum2)};
}