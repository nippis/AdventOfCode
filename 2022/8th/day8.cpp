#include "../solutions.hh"

int calc_scenic_score( const std::vector<std::vector<std::pair<int, bool>>>& grid,
                       const std::pair<int, int>& coord)
{
  int max = -1;
  std::vector<int> scores = {0, 0, 0, 0};
  for (int row = coord.first-1; row >= 0; --row)
  {
    if (max >= grid.at(coord.first).at(coord.second).first) break;
    if (grid.at(row).at(coord.second).first >= max) max = grid.at(row).at(coord.second).first;
    scores.at(0)++;
  }
  max = -1;
  for (int row = coord.first+1; row < grid.size(); ++row)
  {
    if (max >= grid.at(coord.first).at(coord.second).first) break;
    if (grid.at(row).at(coord.second).first >= max) max = grid.at(row).at(coord.second).first;
    scores.at(1)++;
  }
  max = -1;
  for (int col = coord.second-1; col >= 0; --col)
  {
    if (max >= grid.at(coord.first).at(coord.second).first) break;
    if (grid.at(coord.first).at(col).first >= max) max = grid.at(coord.first).at(col).first;
    scores.at(2)++;
  }
  max = -1;
  for (int col = coord.second+1; col < grid.front().size(); ++col)
  {
    if (max >= grid.at(coord.first).at(coord.second).first) break;
    if (grid.at(coord.first).at(col).first >= max) max = grid.at(coord.first).at(col).first;
    scores.at(3)++;
  }
  int score = 1;
  for (int x : scores) score *= x;
  return score;
}

int is_visible(int row, int col, int& max,
                std::vector<std::vector<std::pair<int, bool>>>& grid)
{
  if (grid.at(row).at(col).first > max)
  {
    max = grid.at(row).at(col).first;
    if (!(grid.at(row).at(col).second))
    {
      grid.at(row).at(col).second = true;
      return 1;
    }
  }
  return 0;
}

std::pair<std::string, std::string> day8(std::ifstream file)
{
  std::string row;
  std::vector<std::vector<std::pair<int, bool>>> grid;
  int visible;
  while (getline(file, row))
  {
    grid.push_back({});
    for (char a : row) grid.back().push_back({a-'0', false});
  }
  for (int row = 0; row < grid.size(); ++row)
  {
    int max = -1;
    for (int column = 0; column < grid.front().size(); ++column)
      visible += is_visible(row, column, max, grid);
    max = -1;
    for (int column = grid.front().size()-1; column >= 0; --column)
      visible += is_visible(row, column, max, grid);
  }
  for (int column = 0; column < grid.front().size(); ++column)
  {
    int max = -1;
    for (int row = 0; row < grid.size(); ++row)
      visible += is_visible(row, column, max, grid);
    max = -1;
    for (int row = grid.size()-1; row >= 0; --row)
      visible += is_visible(row, column, max, grid);
  }

  int max_score = 0;
  for (int row = 1; row < grid.size()-1; ++row) 
    for (int col = 1; col < grid.front().size()-1; ++col)
    {
      int score = calc_scenic_score(grid, {row, col});
      if (score > max_score) max_score = score;
    }

  return {std::to_string(visible), std::to_string(max_score)};
}