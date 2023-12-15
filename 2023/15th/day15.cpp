#include "../solutions.hh"

struct Lens
{
  Lens(const std::string& label, char fl) : label(label), fl(fl) {};
  std::string label;
  char fl;
};

void add_lens(std::forward_list<Lens>& box, const std::string& label, char fl)
{ 
  bool found = false;
  for (auto& lens : box)
  {
    if (lens.label == label)
    {
      lens.fl = fl;
      found = true;
      break;
    }
  }
  if (!found)
  {
    box.emplace_front(label, fl);
  }
}

void remove_lens(std::forward_list<Lens>& box, const std::string& label)
{
  auto prev_lens_it = box.before_begin();
  auto lens_it = box.begin();
  while (lens_it != box.end())
  {
    if ((*lens_it).label == label)
    {
      lens_it++;
      box.erase_after(prev_lens_it);
      prev_lens_it++;
    }
    else
    {
      lens_it++;
      prev_lens_it++;
    }
  }
}

std::pair<std::string, std::string> day15::solve(std::ifstream f)
{
  // input for part B
  std::string input;
  // Part A
  char a;
  int sum = 0;
  int stepsum = 0;
  while (f.get(a) && a != '\n')
  {
    input.push_back(a);
    if (a == ',')
    {
      sum += stepsum;
      stepsum = 0;
      continue;
    }
    stepsum = (stepsum + a) * 17 % 256;
  }
  sum += stepsum;

  // Part B
  std::array<std::forward_list<Lens>, 256> boxes;

  int boxid = 0;
  std::string label;
  std::stringstream input_stream(input);
  while (input_stream.get(a))
  {
    if (a == '=')
    {
      input_stream.get(a);
      int fl = a-'0';
      add_lens(boxes.at(boxid), label, fl);
      label.clear();
      boxid = 0;
    }
    else if (a == '-')
    {
      remove_lens(boxes.at(boxid), label);
      label.clear();
      boxid = 0;
    }
    else if (a != ',')
    {
      boxid = (boxid + a) * 17 % 256;
      label.push_back(a);
    }
  }

  long long total_focusing_power = 0;
  for (int i = 1; i<=256; ++i)
  {
    int lens_count = 0;
    for (auto& lens : boxes.at(i-1)) lens_count++;
    int slot = lens_count;
    for (auto& lens : boxes.at(i-1))
    {
      total_focusing_power += slot * i * lens.fl;
      --slot;
    }
  }

  return {std::to_string(sum), std::to_string(total_focusing_power)};
}