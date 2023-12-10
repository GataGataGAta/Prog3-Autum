#include <iostream>

void swap(int&a, int&b)
{
    int tmp = 0;
    tmp = a;
    a = b;
    b = tmp;
}

int main(void)
{
    int a = 10;
    int b = 20;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    swap(a, b);
    std::cout << "a = " << a << ", b = " << b << std::endl;
    return 0;    
}