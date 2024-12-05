#include "../solutions.hh"

std::pair<std::string, std::string> day05::solve(std::ifstream f)
{
  std::string row;
  std::vector<std::pair<int, int>> rules;
  while (getline(f, row))
  {
    if (row.empty())
      break;
    rules.push_back(std::make_pair(std::stoi(row.substr(0, 2)), std::stoi(row.substr(3, 2))));
  }

  std::vector<std::vector<int>> updates;
  while (getline(f, row))
  {
    std::vector<int> pages;
    std::string page;
    for (char a : row)
    {
      if (a == ',')
      {
        pages.push_back(std::stoi(page));
        page.clear();
        continue;
      }
      page.push_back(a);
    }
    pages.push_back(std::stoi(page));
    updates.push_back(pages);
  }

  int sum = 0;
  int sum2 = 0;
  for (auto update : updates)
  {
    std::vector<std::pair<int, int>> applicableRules;
    for (auto rule : rules)
    {
      if (std::find(update.begin(), update.end(), rule.first) == update.end() ||
          std::find(update.begin(), update.end(), rule.second) == update.end() )
        continue;
      applicableRules.push_back(rule);
    }
    bool correct = true;
    for (auto rule : applicableRules)
    {
      if (std::find(std::find(update.begin(), update.end(), rule.first), update.end(), rule.second) == update.end())
      {
        correct = false;
        break;
      }
    }
    if (correct)
    {
      sum += update.at(update.size()/2);
    }
    else
    {
      bool todo = true;
      while (todo)
      {
        todo = false;
        for (auto rule : applicableRules)
        {
          if (std::find(std::find(update.begin(), update.end(), rule.first), update.end(), rule.second) == update.end())
          {
            todo = true;
            update.insert(std::find(update.begin(), update.end(), rule.second), rule.first);
            update.erase(std::find(std::find(update.begin(), update.end(), rule.second), update.end(), rule.first));
          }
        }
      }
      sum2 += update.at(update.size()/2);
    }
  }
  return {std::to_string(sum), std::to_string(sum2)};
}