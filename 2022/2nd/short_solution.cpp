#include <fstream>
#include <iostream>
#include <bitset>

int testi(int x)
{
    return (x&7&x>>3?1:!((x>>5|x>>2)&x&7)*2)*3+(x>>4)+1|((((x&8)?(x&1?(x&7)<<2:(x&7)>>1):(x&16?x&7:(x&4?(x&7)>>2:(x&7)<<1)))>>1)+1+(x>>4)*3)<<16;
}

int main() {
    std::string r;
    std::ifstream file ("input.txt");
    long a = 0, b = 0;
    while (getline(file, r)) {
        char x = (1<<r[0]-65) + (1<<r[2]-85);
        a += (x&7&x>>3?1:!((x>>5|x>>2)&x&7)*2)*3+(x>>4)+1|((((x&8)?(x&1?(x&7)<<2:(x&7)>>1):(x&16?x&7:(x&4?(x&7)>>2:(x&7)<<1)))>>1)+1+(x>>4)*3)<<16;
    }
    //std::cout<<(a&65535)<<std::endl<<(a>>16)<<std::endl;
    for (int i : {9,10,12,17,18,20,33,34,36}) 
    {
        std::bitset<8> x(((testi(i)&4) + ((testi(i)&983040)>>12)));
        std::bitset<8> y(i);
        std::cout << y << " " << x << std::endl;}
    return 0;
}