#include <iostream>

int add(int a, int b)
{
    return a + b;
}

int add(int a, int b, int c)
{
    return a + b + c;
}

double add(double a, double b)
{
    return a + b;
}

int main(void)
{
    std::cout << add(1, 2) << std::endl;
    std::cout << add(1, 2, 3) << std::endl;
    std::cout << add(1.0, 2.0) << std::endl;
    return 0;
}