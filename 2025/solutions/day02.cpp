#include "../solutions.hh"
#include <cmath>

using int_type = unsigned long long;

bool is_invalid1(std::string_view a)
{
  return (a.substr(0, a.length()/2) == a.substr(a.length()/2));
}

bool is_invalid2(std::string_view a)
{
  for (int seqLen = 1; seqLen <= a.length()/2; seqLen++)
  {
    if (a.length() % seqLen != 0)
      continue;
    std::string_view prev;
    bool valid = false;
    for (int seqPos = 0; seqPos < a.length() / seqLen; seqPos++)
    {
      if (!prev.empty() && a.substr(seqPos*seqLen, seqLen) != prev)
      {
        valid = true;
        break;
      }
      prev = a.substr(seqPos*seqLen, seqLen);
    }
    if (!valid)
      return true;
  }
  return false;
}

template <typename Func>
int_type find_invalid_ids(const std::string& Begin, const std::string& End, Func func)
{
  int_type invalids = 0;
  for (int_type i = stoll(Begin); i <= stoll(End); i++)
  {
    std::string id = std::to_string(i);
    invalids += func(id) ? i : 0;
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
      result1 += find_invalid_ids(first, second, is_invalid1);
      result2 += find_invalid_ids(first, second, is_invalid2);
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
  result1 += find_invalid_ids(first, second, is_invalid1);
  result2 += find_invalid_ids(first, second, is_invalid2);

  return {std::to_string(result1), std::to_string(result2)};
}