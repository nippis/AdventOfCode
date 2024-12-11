#include "../solutions.hh"
#include <thread>
#include <future>

std::vector<uint64_t> p = []()
{
  std::vector<uint64_t> p;
  for (int i = 0; i<21; ++i)
  {
    p.push_back(std::pow(10, i));
  }
  return p;
}();

int getDigitCount(const uint64_t& x)
{
  char i = 0;
  while(x>=p.at(i)) ++i;
  return i;
}

std::pair<uint64_t, uint64_t> splitNumber(const uint64_t& x)
{
  uint64_t div = p.at(getDigitCount(x)/2);
  return std::make_pair(x/div, x%div);
}

std::vector<std::future<int>> threads;

int blink(uint64_t stone, int n, int depth)
{
  if (n >= 25)
    return 1;
  std::vector<uint64_t> stones;
  if (stone == 0)
    return blink(1, n+1, depth);
  else if (getDigitCount(stone) % 2 == 0)
  {
    auto numbers = splitNumber(stone);
    return blink(numbers.first, n+1, depth) + blink(numbers.second, n+1, depth);
  }
  else
    return blink(stone*2024, n+1, depth);
  return 0;
}

std::pair<std::string, std::string> day11::solve(std::ifstream f)
{
  char input;
  std::string number;
  std::list<uint64_t> stones;
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

  long long sum = 0;
  for (auto stone : stones)
    sum += blink(stone, 0, 0);
  for (auto& thread : threads)
    sum += thread.get();

  //std::vector<std::future<int>> threads; // std::async

  long long sum2 = 0;

  return {std::to_string(sum), std::to_string(sum2)};
}