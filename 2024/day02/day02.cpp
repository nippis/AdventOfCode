#include "../solutions.hh"

bool reportIsSafe(int type, std::list<int>::iterator it, std::list<int>& numbers)
{
  std::string inputNumber;
  if (it == numbers.end())
    return true;
  if (it == numbers.begin())
    return reportIsSafe(0, std::next(it), numbers);
  if ((type >= 0) && *it > *std::prev(it) && *it-*std::prev(it) <= 3)
    return reportIsSafe(1, std::next(it), numbers);
  if ((type <= 0) && *std::prev(it) > *it && *std::prev(it)-*it <= 3)
    return reportIsSafe(-1, std::next(it), numbers);
  return false;
}

std::pair<std::string, std::string> day02::solve(std::ifstream f)
{
  std::string row = "";
  int safeReports = 0;
  int safeReports2 = 0;
  while (getline(f, row))
  {
    std::stringstream rowStream(row);
    std::list<int> numbers;
    std::string number;
    while (getline(rowStream, number, ' '))
      numbers.push_back(stoi(number));
    
    // Part One
    safeReports += reportIsSafe(0, numbers.begin(), numbers);

    // Part Two
    for (int i = 0; i < numbers.size(); ++i)
    {
      std::list<int> numbers2(numbers);
      numbers2.erase(std::next(numbers2.begin(),i));
      if (reportIsSafe(0, numbers2.begin(), numbers2))
      {
        ++safeReports2;
        break;
      }
    }
  }
  return {std::to_string(safeReports),std::to_string(safeReports2)};
}