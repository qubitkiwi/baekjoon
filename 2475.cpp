#include <iostream>

int chek_num(int *num)
{
    int sum(0);
    for(int i=0; i<5; i++)
        sum += num[i]*num[i];
    return sum%10;
}

int main()
{
    int number[5];
    for(auto &i : number)
        std::cin >> i;

    std::cout << chek_num(number) << std::endl;

    return 0;
}