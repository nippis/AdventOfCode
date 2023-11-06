#include <functional>
#include <set>
#include <memory>
#include "../solutions.hh"

std::vector<int> findFactors(int x)
{
  std::vector<int> factors = {x};
  bool allFound = false;
  while (!allFound)
  {
    for (int i=0; i*i<=x; i++)
    {
      if (factors.back()%i == 0)
      {
        factors.push_back(factors.back()/i);
        factors.at(factors.size()-2) = i;
        break;
      }
      if (i*i>=x) allFound = true;
    }
  }
  return factors;
}

int tokenize(std::vector<std::string>& tokens, const std::string input, char delim=' ', std::string strip = "")
{
  int begin = 0;
  tokens.clear();
  for (int i=0; i<input.size(); ++i)
  {
    if (input.at(i) == delim && i>0)
    {
      std::string token = input.substr(begin, i-begin);
      if (!token.empty() && token != " ") tokens.push_back(token);
      begin = i;
    }
    else if ( i == input.size()-1)
    {
      tokens.push_back(input.substr(begin));
    }
  }
  for (int j=0; j<tokens.size(); j++) 
  {
    while (strip.find(tokens.at(j).back()) != std::string::npos)
      tokens.at(j).pop_back();
    while (strip.find(tokens.at(j).front()) != std::string::npos)
      tokens.at(j).erase(0, 1);
  }
  return tokens.size();
}

struct Item
{
  Item(std::vector<int> a) : summables({a}) {}
  std::vector<std::vector<int>> summables;
  bool isDivisible(int divider)
  {
    for ( auto summable : summables )
    {
      if (std::find(summable.begin(), summable.end(), divider) == summable.end())
        return false;
    }
    return true;
  }
};

struct Monkey
{
  int name;
  int inspectCount = 0;
  int testDivider = 1;
  int trueTarget = -1;
  int falseTarget = -1;
  std::deque<Item> items;
  void(*operation)(Item&, int);
  int operationInput = 0;
  void throwTo(std::shared_ptr<Monkey> target)
  {
    target->items.push_back(items.front());
    items.pop_front();
  }
};

std::pair<std::string, std::string> day11(std::ifstream file)
{
  std::string row;
  std::vector<std::string> tokens;
  std::vector<std::shared_ptr<Monkey>> monkeys;
  while (false && getline(file, row))
  {
    if (row.empty()) continue;
    int tokenCount = tokenize(tokens, row, ' ', ":, ");
    if (tokens.at(0) == "Monkey")
    {
      monkeys.push_back(std::make_shared<Monkey>());
      monkeys.back()->name = std::stoi(tokens.at(1));
      std::cout << "Monkey number " <<  tokens.at(1) << " initialized." << std::endl;
    }
    else if (tokens.at(0) == "Starting")
    {
      std::cout << "Items: ";
      for (int i = 2; i<tokens.size(); i++)
      {
        monkeys.back()->items.push_back(findFactors(std::stoi(tokens.at(i))));
        std::cout << tokens.at(i) << " ";
      }
      std::cout << std::endl;
    }
    else if (tokens.at(0) == "Operation")
    {
      std::cout << "Operation is old ";
      if (tokens.at(4) == "*" && tokens.at(5) == "old")
      {
        monkeys.back()->operation = [](Item& lhs, int rhs) {};
        std::cout << "* old" << std::endl;
      }
      else if (tokens.at(4) == "*")
      {
        monkeys.back()->operation = [](Item& lhs, int rhs){for (auto summable : lhs.summables) summable.push_back(rhs);};
        std::cout << "* " << tokens.at(5) << std::endl;
        monkeys.back()->operationInput = std::stoi(tokens.at(5));
      }
      else if (tokens.at(4) == "+")
      {
        monkeys.back()->operation = [](Item& lhs, int rhs){lhs.summables.push_back({rhs});};
        std::cout << "+ " << tokens.at(5) << std::endl;
        monkeys.back()->operationInput = std::stoi(tokens.at(5));
      }
    }
    else if (tokens.at(0) == "Test")
    {
      std::cout << "Divider: " << tokens.at(3) << std::endl;
      monkeys.back()->testDivider = std::stoi(tokens.at(3));
    }
    else if (tokens.at(1) == "true")
    {
      std::cout << "Targets: " << tokens.at(5) << " ";
      monkeys.back()->trueTarget = std::stoi(tokens.at(5));
    }
    else if (tokens.at(1) == "false")
    {
      std::cout << tokens.at(5) << std::endl << std::endl;
      monkeys.back()->falseTarget = std::stoi(tokens.at(5));
    }
  }
  int itemcount = 0;
  for (auto monki : monkeys)
  {
    for (auto itemi : monki->items) itemcount++;
  }
  std::cout << itemcount << std::endl << std::endl;

  for (int i=0; i<10000; i++)
  {
    for (auto monki : monkeys)
    {
      while (monki->items.size() > 0)
      {
        // Inspect
        monki->inspectCount++;
        // Operation
        //monki->items.front() = monki->operation(monki->items.front(), monki->operationInput);
        // Divide by 3
        //monki->items.front() = monki->items.front()/3;
        // Test
        if (monki->items.front().isDivisible(monki->testDivider))
        {
          monki->throwTo(monkeys.at(monki->trueTarget));
        }
        else
        {
          monki->throwTo(monkeys.at(monki->falseTarget));
        }
      }
    }
  }
  itemcount = 0;
  for (auto monki : monkeys)
  {
    //for (auto itemi : monki->items) std::cout << itemi << " ";
    std::cout << monki->inspectCount << std::endl;
  }
  long long sum = (long long)142489*(long long)142500;
  std::string summa = std::to_string(sum);
  std::cout << std::endl<< summa << std::endl;
  return {"", ""};
}
