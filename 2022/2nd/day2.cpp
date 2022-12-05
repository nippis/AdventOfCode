#include "../solutions.hh"

std::pair<std::string, std::string> day2(std::ifstream file) 
{
    std::string row;
    int a = 0, b = 0;
    while (getline(file, row)) {
        int opp = 1<<(int)row.at(0)-65;
        int you = 1<<(int)row.at(2)-88;
        a += (opp==you?1:(you>>2&opp|you<<1&opp?0:2))*3 + (you>>1)+1;
        b += (((you&1)?(opp&1?opp<<2:opp>>1):(you&2?opp:(opp&4?opp>>2:opp<<1)))>>1)+1 + (you>>1)*3;
    }
    return {std::to_string(a), std::to_string(b)};
}