#include <iostream>
#include <fstream>

int main()
{
    std::ifstream file("input.txt");
    std::string row;
    int a = 0, b = 0;
    while (getline(file, row))
    {

    }
    std::cout << a << std::endl << b << std::endl;
}