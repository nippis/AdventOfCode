#include "../solutions.hh"

std::pair<std::string, std::string> day1::solve(std::ifstream f)
{
    std::string row = "";
    int sum = 0;
    while (getline(f, row)) 
    {
        char a = 0, b = 0;
        for (char digit : row)
        {
          if (digit > 47 && digit < 58 && a == 0)
            a = digit;
          else  if (digit > 47 && digit < 58)
            b = digit;
        }
        if (b == 0) b = a;
        std::string sumstr = std::string(1, a)+std::string(1, b);
        sum += stoi(sumstr);
    }

    return {std::to_string(sum), ""};
}