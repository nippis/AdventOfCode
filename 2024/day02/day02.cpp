#include "../solutions.hh"

enum ReportType
{
  none,
  asc,
  desc
};

bool reportIsSafe(ReportType type, int prev, std::list<int>::iterator it, std::list<int>::iterator end)
{
  std::string inputNumber;
  if (it == end)
    return true;
  if (prev < 0)
    return reportIsSafe(type, *it, std::next(it), end);
  if ((type == none || type == asc) && *it > prev && *it-prev <= 3)
    return reportIsSafe(asc, *it, std::next(it), end);
  if ((type == none || type == desc) && prev > *it && prev-*it <= 3)
    return reportIsSafe(desc, *it, std::next(it), end);
  return false;
}

std::pair<std::string, std::string> day2::solve(std::ifstream f)
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
    safeReports += reportIsSafe(none, -1, numbers.begin(), numbers.end());

    // Part Two
    for (int i = 0; i < numbers.size(); ++i)
    {
      std::list<int> numbers2(numbers);
      numbers2.erase(std::next(numbers2.begin(),i));
      if (reportIsSafe(none, -1, numbers2.begin(), numbers2.end()))
      {
        ++safeReports2;
        break;
      }
    }
  }
  return {std::to_string(safeReports),std::to_string(safeReports2)};
}