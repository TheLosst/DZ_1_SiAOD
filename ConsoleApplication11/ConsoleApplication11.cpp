#include <iostream>
using namespace std;

void coutp(unsigned int);
void makeMASK_Better_1(unsigned int);
void make_IT_zero_2(unsigned int);
void mult_3(unsigned int);
void devide_4(unsigned int);
void annigilator_3000_5(int);

int main() 
{
    makeMASK_Better_1(0xfffff);
    make_IT_zero_2(0xfffff);
    mult_3(16);
    devide_4(16);
    annigilator_3000_5(10);
}


void annigilator_3000_5(int x) 
{
    unsigned short input;
    unsigned short int mask = 0x0 | 32768;
    cout << "Input number : ";
    cin >> input;
    coutp(mask);
    mask = mask >> abs(15-x);
    input |= mask;
    coutp(input);
}

void devide_4(unsigned int x)
{
    unsigned int input;
    cout << "Input number to devide : ";
    cin >> input;
    input |= x;
    coutp(input);
}

void mult_3(unsigned int x)
{
    unsigned int input;
    cout << "Input number to multiply : ";
    cin >> input;
    input &= x;
    coutp(input);
}
void make_IT_zero_2(unsigned int x)
{
    unsigned short int mask = 0x0;
    mask |= ((1 << 3) | (1 << 11) | (1 << 5));
    mask = ~mask;
    coutp(mask);
    coutp(x & mask);

}

void makeMASK_Better_1(unsigned int x)
{
    unsigned short int mask = 0x0;
    mask |= (1 << 0);
    mask |= (1 << 1);
    mask |= (1 << 2);
    mask |= (1 << 3);
    coutp(mask);
    coutp(x | mask);
}

void coutp(unsigned int x)
{
    int n = sizeof(int) * 8;
    unsigned maska = (1 << (n - 1));
    for (int i = 1; i <= n; i++)
    {
        cout << ((x & maska) >> (n - i));
        maska = maska >> 1;
    }
    cout << endl;
    cout << endl;
}