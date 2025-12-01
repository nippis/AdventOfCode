#include "../solutions.hh"
#include <thread>
#include <future>
#include <stdio.h>
#include <gmpxx.h>

static std::vector<uint64_t> p = []()
{
  std::vector<uint64_t> p;
  for (int i = 0; i<21; ++i)
    p.push_back(std::pow(10, i));
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

static int m = 35;
int blink(const uint64_t& stone, int n)
{
  if (n >= 70)
    return 1;
  if (n == m)
    if (results.find(stone) != results.end())
    {
      //std::cout << stone << std::endl;
      return results.at(stone);
    }
  if (stone == 0)
  {
    uint64_t r = blink(1, n+1);
    if (n == m)
    {
      results.insert({stone, r});
    }
    return r;
  }
  else if (getDigitCount(stone) % 2 == 0)
  {
    auto numbers = splitNumber(stone);
    uint64_t r = blink(numbers.first, n+1) + blink(numbers.second, n+1);
    if (n == m)
    {
      results.insert({stone, r});
    }
    return r;
  }
  else
  {
    uint64_t r = blink(stone*2024, n+1);
    if (n == m)
    {
      results.insert({stone, r});
    }
    return r;
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

  mpz_class sum = 0;
  for (auto stone : stones)
    mpz_add_ui += blink(stone, 0);
    //threads.push_back(std::async(blink, stone, 0));
  for (auto& thread : threads);
    //sum += thread.get();

  printf ("n = ");
  mpz_out_str(stdout,10,sum);
  printf ("\n");

  return {"", ""};
}