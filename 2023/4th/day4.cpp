#include "../solutions.hh"

std::pair<std::string, std::string> day4::solve(std::ifstream f)
{
  std::string line;
  int sum = 0;
  int sumb = 0;
  std::deque<int> copies({1});
  while (getline(f, line))
  {
    int i = 0;
    for (;i<line.size();i++) if (line.at(i) == ':') break;
    std::vector<int> winning, own, *list = &winning;
    std::string last_number;
    for (;i<line.size();i++)
    {
      if (line.at(i) == '|') list = &own;
      else if (isdigit(line.at(i))) last_number.push_back(line.at(i));
      else if (line.at(i) == ' ') if (!last_number.empty())
      {
        list->push_back(stoi(last_number));
        last_number.clear();
      }
    }
    list->push_back(stoi(last_number));

    int winning_numbers = 0;
    for (int winning_number : winning)
    {
      for (int own_number : own) if (own_number == winning_number)
      {
        ++winning_numbers;
        break;
      }
    }
    sum += (winning_numbers>0) ? pow(2, winning_numbers-1) : 0;
    /*for (int j = 0; j < winning_numbers; j++)
    {
      if (j+1 > copies.size()) copies.push_back(copies.front()+1);
      else copies.at(j+1) += copies.front();
    }
    sumb += copies.front();
    copies.pop_front();*/
  }
  return {std::to_string(sum),std::to_string(sumb)};
}