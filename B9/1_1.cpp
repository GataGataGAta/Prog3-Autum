#include <iostream>

int main(void)
{
    int n;
    std::cout << "ジンバブエドルの金額を入力してください: " << std::endl;
    std::cin >> n;
    double yen = n * 0.412962;
    std::cout << n << "ジンバブエドルは" << yen << "円です" << std::endl;
    return 0;
}