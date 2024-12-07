#include "../solutions.hh"

std::vector<std::vector<bool>> generatePermutations(std::vector<bool> binary, int depth, int max)
{
  if (depth >= max)
    return {binary};
  
  binary.push_back(false);
  std::vector<std::vector<bool>> permutations1 = generatePermutations(binary, depth+1, max);
  binary.back() = true;
  std::vector<std::vector<bool>> permutations2 = generatePermutations(binary, depth+1, max);
  permutations1.insert(permutations1.end(), permutations2.begin(), permutations2.end());
  return permutations1;
}

enum operation
{
  plus,
  mult,
  conc
};

std::vector<std::vector<operation>> generatePermutations2(std::vector<operation> binary, int depth, int max)
{
  if (depth >= max)
    return {binary};
  
  binary.push_back(plus);
  std::vector<std::vector<operation>> permutations1 = generatePermutations2(binary, depth+1, max);
  binary.back() = mult;
  std::vector<std::vector<operation>> permutations2 = generatePermutations2(binary, depth+1, max);
  binary.back() = conc;
  std::vector<std::vector<operation>> permutations3 = generatePermutations2(binary, depth+1, max);
  permutations1.insert(permutations1.end(), permutations2.begin(), permutations2.end());
  permutations1.insert(permutations1.end(), permutations3.begin(), permutations3.end());
  return permutations1;
}

std::pair<std::string, std::string> day07::solve(std::ifstream f)
{
  unsigned long long sum = 0, sum2 = 0;
  std::string row;
  while(getline(f, row))
  {
    std::stringstream rowStream(row);
    char a;
    std::vector<unsigned long long> equation;
    std::string number;
    while (rowStream.get(a))
    {
      if (a == ' ')
      {
        equation.push_back(std::stoll(number));
        number.clear();
      }
      if (a != ':')
        number.push_back(a);
    }
    equation.push_back(std::stoll(number));

    std::vector<bool> binary;
    std::vector<std::vector<bool>> permutations = generatePermutations(binary, 0, equation.size()-2);

    for (auto p : permutations)
    {
      unsigned long long result = equation.at(1);
      for (int i = 2; i<equation.size(); ++i)
      {
        if (!p.at(i-2))
          result += equation.at(i);
        else
          result *= equation.at(i);
      }
      if (result == equation.at(0))
      {
        sum += result;
        break;
      }
    }

    std::vector<operation> binary2;
    std::vector<std::vector<operation>> permutations2 = generatePermutations2(binary2, 0, equation.size()-2);

    for (auto p : permutations2)
    {
      unsigned long long result = equation.at(1);
      for (int i = 2; i<equation.size(); ++i)
      {
        if (p.at(i-2) == plus)
          result += equation.at(i);
        else if (p.at(i-2) == mult)
          result *= equation.at(i);
        else if (p.at(i-2) == conc)
          result = std::stoll(std::to_string(result) + std::to_string(equation.at(i)));
      }
      if (result == equation.at(0))
      {
        sum2 += result;
        break;
      }
    }
  }
  return {std::to_string(sum), std::to_string(sum2)};
}