#include "../solutions.hh"

long long get_next_number(std::stringstream &input_stream)
{
  std::string number = "";
  char a;
  while(input_stream.get(a))
  {
    if (isdigit(a))
      number.push_back(a);
    else if (!number.empty())
      break;
  }
  if (!number.empty())
    return stoll(number);
  else return -1;
}

std::pair<std::string, std::string> day5::solve(std::ifstream f)
{

  return {"",""};
  std::string line;
  std::vector<long long> ids;

  if (getline(f, line))
  {
    std::stringstream line_stream(line);
    bool range_in = false;
    long long number;
    while (true)
    {
      long long input = get_next_number(line_stream);
      if (input >= 0)
      {
        if (!range_in)
        {
          number = input;
          range_in = true;
        }
        else
        {
          for (long long i = number; i<number+input; i++) ids.push_back(i);
          range_in = false;
        }
      }
      else break;
    }
  }
  else return {"",""};

  for (int i = 0; i<8; ++i)
  {
    std::set<long long> changed;
    while (getline(f, line) && !line.empty())
    {
      if (isdigit(line.at(0)))
      {
        std::stringstream line_stream(line);
        long long dest_start = get_next_number(line_stream), 
                  source_start = get_next_number(line_stream),
                  range = get_next_number(line_stream);
        
        for (long long j = 0; j < ids.size(); j++)
        {
          if (ids.at(j)>=source_start && ids.at(j)<source_start+range && changed.find(j) == changed.end())
          {
            ids.at(j) = ids.at(j)-source_start+dest_start;
            changed.insert(j);
          }
        }
      }
    }
  }

  long long min = ids.at(0);
  for (long long id : ids) if (id<min) min = id;

  return {std::to_string(min),""};
}