#include "../solutions.hh"

std::vector<std::string> numbers =
{
  "one",
  "two",
  "three",
  "four",
  "five",
  "six",
  "seven",
  "eight",
  "nine"
};

std::pair<std::string, std::string> day1::solve(std::ifstream f)
{
    std::string row = "";
    int sum = 0;
    int sumb = 0;
    while (getline(f, row)) 
    {
        char ac = 0, bc = 0;
        int i = 0, bi = 0, ai = 0;
        for (char digit : row)
        {
          if (digit > 47 && digit < 58 && ac == 0)
            {
              ac = digit;
              ai = i;
            }
          if (digit > 47 && digit < 58)
            {
              bc = digit;
              bi = i;
            }
          i++;
        }

        int a = ac-48;
        int b = bc-48;

        int ab = a;
        int bb = b;
        int bbi = 0, abi = row.size();
        for (int j = 0; j<numbers.size(); ++j)
        {
          size_t posa = row.find(numbers.at(j));
          if (posa != std::string::npos && posa < ai && posa < abi)
            {
              ab = j+1;
              abi = posa;
            }

          size_t posb = row.rfind(numbers.at(j));
          if (posb != std::string::npos && posb > bi && posb > bbi)
            {
              bb = j+1;
              bbi = posb;
            }
        }
        std::string sumstr = std::to_string(a)+std::to_string(b);
        std::string sumstrb = std::to_string(ab)+std::to_string(bb);
        sum += stoi(sumstr);
        sumb += stoi(sumstrb);
    }

    return {std::to_string(sum), std::to_string(sumb)};
}