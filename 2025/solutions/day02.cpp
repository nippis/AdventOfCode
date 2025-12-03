#include "../solutions.hh"
#include <cmath>

using int_type = unsigned long long;

unsigned int digit_count(int_type a)
{
  return log10l(a)+1;
}

int_type subdigitset(int_type a, unsigned int pos, unsigned int count)
{
  if (digit_count(a)-pos < count)
    return 0;
  a = a / (int_type)pow(10, digit_count(a)-pos-count);
  if (pos > 0)
    a = a % (a / (int_type)pow(10, count) * (int_type)pow(10, count));
  return a;
}

int_type is_invalid(int_type a)
{
  for (int i = 1; i <= digit_count(a)/2; i++)
  {
    if (digit_count(a) % i != 0)
      continue;
    std::vector<int> sets;
    for (int j = 0; j < digit_count(a) / i; j++)
    {
      sets.push_back(subdigitset(a, j*i, i));
    }
    if (std::all_of(sets.begin(), sets.end(), [=](auto i){return i == sets.at(0);}))
    {
      return a;
    }
  }
  return 0;
}

std::pair<int_type, int_type> find_invalid_ids(const std::string& Begin, const std::string& End)
{
  std::pair<int_type, int_type> invalids = {0,0};
  for (int_type i = stoll(Begin); i <= stoll(End); i++)
  {
    std::string id = std::to_string(i);
    invalids.first += (id.substr(0, id.length()/2) == id.substr(id.length()/2)) ? stoll(id) : 0;
    invalids.second += is_invalid(i) ? i : 0;
  }
  return invalids;
}

std::pair<std::string, std::string> day2::solve(std::ifstream f)
{
  int_type result1 = 0;
  int_type result2 = 0;
  char a;
  std::string first;
  std::string second;
  std::string* temp = &first;
  while (f.get(a))
  {
    if (a == ',')
    {
      auto invalids = find_invalid_ids(first, second);
      result1 += invalids.first;
      result2 += invalids.second;
      first.clear();
      second.clear();
      temp = &first;
    }
    else if (a == '-')
    {
      temp = &second;
    }
    else
    {
      temp->push_back(a);
    }
  }
  auto invalids = find_invalid_ids(first, second);
  result1 += invalids.first;
  result2 += invalids.second;

  return {std::to_string(result1), std::to_string(result2)};
}