#include <fstream>
#include <iostream>

int get_result(int opp, int you)
{
    if (opp==you) return 1;
    else if (you>>2&opp|you<<1&opp) return 0;
    else if (you<<2&opp|you>>1&opp) return 2;
    else return -1;
}

void main()
{
    std::string row = "";
    std::ifstream file ("input.txt");
    int points = 0;
    while (getline(file, row)) 
    {
        int opp = 1;
        int you = 1;
        if (row.size() > 3)
        {
            opp <<= (int)row.at(0) - 65;
            you <<= (int)row.at(2) - 88;
            points += get_result(opp, you)*3 + (you>>1)+1;
        }
    }
    std::cout << points << std::endl;
}