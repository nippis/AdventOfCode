#include "../solutions.hh"

std::pair<std::string, std::string> day6::solve(std::ifstream f)
{
  std::vector<int> times = {60, 94, 78, 82}, records = {475, 2138, 1015, 1650};
  long long timeb = 60947882, recordb = 475213810151650;

  int product = 1;
  for (int i = 0; i<times.size(); i++)
  {
    int sum = 0;
    for (int push_time = 0; push_time<times.at(i); push_time++)
      if ((times.at(i)-push_time)*push_time>records.at(i)) sum++;
    product *= sum;
  }

  long long sum = 0;
  for (long long push_time = 0; push_time<timeb; push_time++)
    if ((timeb-push_time)*push_time>recordb) sum++;
    
  return {std::to_string(product),std::to_string(sum)};
}