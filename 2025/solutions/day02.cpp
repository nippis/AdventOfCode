#include "../solutions.hh"

long long find_invalid_ids(const std::string& Begin, const std::string& End)
{
  if (Begin.empty() || End.empty())
    return 0;
  if (Begin.length() % 2 != 0 && End.length() % 2 != 0)
    return 0;
  if (stoll(Begin) > stoll(End))
    return 0;

  long long invalidCount = 0;
  for (long long i = stoll(Begin); i <= stoll(End); i++)
  {
    std::string id = std::to_string(i);
    if (id.substr(0, id.length()/2) == id.substr(id.length()/2))
    {
      invalidCount += stoll(id);
    }
  }
  return invalidCount;
}

std::pair<std::string, std::string> day2::solve(std::ifstream f)
{
  long long result1 = 0;
  char a;
  std::string first;
  std::string second;
  std::string* temp = &first;
  while (f.get(a))
  {
    if (a == ',')
    {
      result1 += find_invalid_ids(first, second);
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
  result1 += find_invalid_ids(first, second);
  return {std::to_string(result1),""};
}