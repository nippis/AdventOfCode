#include "../solutions.hh"

std::pair<std::string, std::string> day01::solve(std::ifstream f)
{
  std::string row = "";
  std::vector<int> idlist1;
  std::vector<int> idlist2;

  while (getline(f, row)) 
  {
    idlist1.push_back(std::stoi(row.substr(0, 5)));
    idlist2.push_back(std::stoi(row.substr(8, 5)));
  }

  std::sort(idlist1.begin(), idlist1.end());
  std::sort(idlist2.begin(), idlist2.end());
  long long sum = 0;
  long long sum2 = 0;
  
  for (int i = 0; i<idlist1.size(); ++i)
  {
    sum += abs(idlist1.at(i) - idlist2.at(i));
    for (int j = 0; j<idlist2.size(); ++j)
      if (idlist2.at(j) == idlist1.at(i))
        sum2 += (idlist2.at(j) == idlist1.at(i)) * idlist1.at(i);
  }

  return {std::to_string(sum), std::to_string(sum2)};
}