#include <fstream>
#include <iostream>

int main() {
    std::string r;
    std::ifstream file ("input.txt");
    long a = 0, b = 0;
    while (getline(file, r)) {
        char x = (1<<r[0]-65) + (1<<r[2]-85);
        a += (x&7&x>>3?1:(x>>5&x&7|x>>2&x&7?0:2))*3+(x>>4)+1+(((((x>>3&1)?(x&1?(x&7)<<2:(x&7)>>1):(x>>3&2?(x&7):(x&4?(x&7)>>2:(x&7)<<1)))>>1)+1+(x>>4)*3)<<16);
    }
    std::cout<<(a&65535)<<std::endl<<(a>>16)<<std::endl;
    return 0;
}