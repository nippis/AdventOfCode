#include "../solutions.hh"

// Returns ID of the game if it's possible, otherwise 0
int game_is_possible(std::string game)
{
  std::string game_id = "";
  std::string::iterator i = game.begin();
  for (;*i != ':';++i)
  {
    if (*i>='0' && *i<='9') game_id.push_back(*i);
  }
  i++;
  while (i != game.end())
  {
    std::string cube_count_str = "";
    std::string color = "";
    for (;i != game.end(); ++i)
    {
      if (*i == ',' || *i == ';')
      {
        ++i;
        break;
      }
      if (*i>='0' && *i<='9') 
      {
        cube_count_str.push_back(*i);
      }
      else if (*i != ' ' && *i>'9') 
      {
        color.push_back(*i);
      }
    }
    int cube_count = !cube_count_str.empty() ? stoi(cube_count_str) : 0;
    if (color == "red"   && cube_count > 12 ||
        color == "green" && cube_count > 13 ||
        color == "blue"  && cube_count > 14)
      return 0;
  }
  return stoi(game_id);
}

// Returns the power of the minimum cube counts
int power_of_mins(std::string game)
{
  std::string game_id = "";
  std::string::iterator i = game.begin();
  int redmin = 0;
  int greenmin = 0;
  int bluemin = 0;

  for (;*i != ':';++i)
  {
    if (*i>='0' && *i<='9') game_id.push_back(*i);
  }
  i++;
  while (i != game.end())
  {
    std::string cube_count_str = "";
    std::string color = "";
    for (;i != game.end(); ++i)
    {
      if (*i == ',' || *i == ';')
      {
        ++i;
        break;
      }
      if (*i>='0' && *i<='9') 
      {
        cube_count_str.push_back(*i);
      }
      else if (*i != ' ' && *i>'9') 
      {
        color.push_back(*i);
      }
    }
    int cube_count = !cube_count_str.empty() ? stoi(cube_count_str) : 0;
    if (color == "red"   && cube_count > redmin) redmin = cube_count;
    if (color == "green" && cube_count > greenmin) greenmin = cube_count;
    if (color == "blue"  && cube_count > bluemin) bluemin = cube_count;
  }
  return redmin*greenmin*bluemin;
}

std::pair<std::string, std::string> day2::solve(std::ifstream f)
{
  std::string row = "";
  int sum = 0;
  int sumb = 0;
  while (getline(f, row))
  {
    int game_id = game_is_possible(row);
    int pow = power_of_mins(row);
    sum += game_id; 
    sumb += pow;
  }
  return {std::to_string(sum), std::to_string(sumb)};
}