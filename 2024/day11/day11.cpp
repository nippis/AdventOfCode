#include "../solutions.hh"

int getDigitCount(const unsigned long long& x)
{
  for (int i = 0; i<21; ++i)
  {
    if (x < std::pow(10, i))
      return i;
  }
  return 0;
}

std::pair<unsigned long long, unsigned long long> splitNumber(const unsigned long long& x)
{
  unsigned long long first = x/(std::pow(10, getDigitCount(x)/2));
  return std::make_pair(first, x-first*std::pow(10, getDigitCount(x)/2));
}

unsigned long long blink(std::list<unsigned long long>& stones)
{
  for (auto stone = stones.begin(); stone != stones.end(); ++stone)
  {
    if (*stone == 0)
      *stone = 1;
    else if (std::to_string(*stone).size() % 2 == 0)
    {
      auto numbers = splitNumber(*stone);
      stones.insert(stone, numbers.first);
      *stone = numbers.second;
    }
    else
      *stone = (*stone)*2024;
  }
  return stones.size();
}

unsigned long long iterateBlinks(std::list<unsigned long long> stones, int n)
{
  unsigned long long sum = 0;
  for (int i = 0; i<n; ++i)
  {
    sum += blink(stones);
  }
  return stones.size();
}

std::pair<std::string, std::string> day11::solve(std::ifstream f)
{
  char input;
  std::string number;
  std::list<unsigned long long> stones;
  while(f.get(input))
  {
    if (input != ' ')
    {
      number.push_back(input);
      continue;
    }
    stones.push_back(std::stoi(number));
    number.clear();
  }
  stones.push_back(std::stoi(number));

  unsigned long long sum = iterateBlinks(stones, 25);

  long long sum2 = 0;

  return {std::to_string(sum), std::to_string(sum2)};
}