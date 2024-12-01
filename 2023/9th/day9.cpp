#include "../solutions.hh"

int extrapolate_history(std::vector<int>& history)
{
  std::vector<std::vector<int>> sequences;
  
  return 1;
}

std::pair<std::string, std::string> day9::solve(std::ifstream f)
{
  std::string line;
  int sum = 0;
  while (getline(f, line))
  {
    std::vector<int> history;
    std::string last_number;
    for (char a : line)
    {
      if (a == ' ' && !last_number.empty()) 
      {
        history.push_back(stoi(last_number));
        last_number.clear();
      }
      else
      {
        last_number.push_back(a);
      }
    }

    sum += extrapolate_history(history);
  }

  return {std::to_string(sum), ""};
}