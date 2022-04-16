#include <iostream>

int main(void)
{
    int L, P, i, T;

    std::cin >> L >> P;

    for (i=0; i<5; i++)
    {
        std::cin >> T;
        std::cout << T-L*P << " ";
    }
    std::cout << std::endl;

    return 0;
}