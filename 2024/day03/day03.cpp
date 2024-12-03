#include "../solutions.hh"

constexpr int MAX_TOKEN_LENGTH = 3;

enum tokenType
{
  t_none,
  t_integer,
  t_multiply,
  t_do,
  t_dont,
  t_lparen,
  t_rparen,
  t_comma,
};

using tokenPair = std::pair<tokenType, std::string>;
using tokenList = std::vector<std::pair<tokenType, std::string>>;

const std::vector<tokenPair> KEYWORDS =
{
  {t_multiply, "mul"},
  {t_dont, "don't"},
  {t_do, "do"},
};

bool isDigit(char a)
{
  return a >= '0' && a <= '9';
}

tokenPair findNextToken(const std::string& input)
{
  for (auto keyword : KEYWORDS)
  {
    if (input.substr(0, keyword.second.size()) == keyword.second)
    {
      return std::make_pair(keyword.first, keyword.second);
    }
  }

  if (isDigit(input.front()))
  { 
    std::string number;
    for (int i = 0; i < input.size() && isDigit(input.at(i)); i++)
      number.push_back(input.at(i));
    return std::make_pair(t_integer, number);
  }
  
  if (input.front() == '(')
    return std::make_pair(t_lparen, "(");

  if (input.front() == ')')
    return std::make_pair(t_rparen, ")");

  if (input.front() == ',')
    return std::make_pair(t_comma, ",");

  return std::make_pair(t_none, " ");
}

void getTokens(tokenList& tokens, const std::string& input)
{
  for (int i = 0; i < input.size();)
  {
    tokenPair nextToken = findNextToken(input.substr(i, MAX_TOKEN_LENGTH));
    tokens.push_back(nextToken);
    i += nextToken.second.size();
  }
}

std::pair<std::string, std::string> day03::solve(std::ifstream f)
{
  int sum = 0;
  int sum2 = 0;
  std::string row;
  tokenList tokens;
  while(getline(f, row))
    getTokens(tokens, row);
  
  std::vector<tokenType> tokenTypes;

  bool sumEnabled;

  for (int i = 0; i < tokens.size(); ++i)
  {
    if (tokens.at(i).first == t_multiply && i+6 <= tokens.size())
    {
      if (tokens.at(i+1).first == t_lparen &&
          tokens.at(i+2).first == t_integer &&
          tokens.at(i+3).first == t_comma &&
          tokens.at(i+4).first == t_integer &&
          tokens.at(i+5).first == t_rparen)
        {
          sum += std::stoi(tokens.at(i+2).second) * std::stoi(tokens.at(i+4).second);
          sum2 += sumEnabled ? std::stoi(tokens.at(i+2).second) * std::stoi(tokens.at(i+4).second) : 0;
        }
    }

    if ((tokens.at(i).first == t_do || tokens.at(i).first == t_dont) && i+3 <= tokens.size())
    {
      if (tokens.at(i+1).first == t_lparen &&
          tokens.at(i+2).first == t_rparen)
        {
          sumEnabled = (tokens.at(i).first == t_do);
        }
    }

  }

  return {std::to_string(sum),std::to_string(sum2)};
}