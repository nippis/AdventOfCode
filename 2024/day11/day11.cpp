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

std::unordered_map<uint64_t, uint64_t> results;

int blink(const uint64_t& stone, int n)
{
  if (n >= 45)
    return 1;
  if (stone == 0)
  {
    if (n == 35)
    {
      if (results.find(stone) != results.end())
        return results.at(stone);
      uint64_t r = blink(1, n+1);
      results.insert({stone, r});
      return r;
    }
    return blink(1, n+1);
  }
  else if (getDigitCount(stone) % 2 == 0)
  {
    auto numbers = splitNumber(stone);
    if (n == 35)
    {
      if (results.find(numbers.first) != results.end() && results.find(numbers.second) != results.end())
        return results.at(numbers.first) + results.at(numbers.second);
      uint64_t r1 = blink(numbers.first, n+1);
      uint64_t r2 = blink(numbers.second, n+1);
      results.insert({numbers.first, r1});
      results.insert({numbers.second, r2});
      return r1+r2;
    }
    return blink(numbers.first, n+1) + blink(numbers.second, n+1);
  }
  else
  {
    if (n == 35)
    {
      if (results.find(stone) != results.end())
        return results.at(stone);
      uint64_t r = blink(stone*2024, n+1);
      results.insert({stone, r});
      return r;
    }
    return blink(stone*2024, n+1);
  }
  return 0;
}

std::pair<std::string, std::string> day11::solve(std::ifstream f)
{
  char input;
  std::string number;
  std::vector<uint64_t> stones;
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
    threads.push_back(std::async(blink, stone, 0));
  for (auto& thread : threads)
    sum += thread.get();

  long long sum2 = 0;

  return {std::to_string(sum), std::to_string(sum2)};
}