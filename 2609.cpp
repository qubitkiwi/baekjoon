#include <iostream>

int gcd(int a, int b)
{
    if(a%b != 0)
        return gcd(b, a%b);
    else
        return b;
}

int main()
{
    int a, b;
    std::cin >> a >> b;

    std::cout << gcd(a, b) << std::endl;
    std::cout << (a*b)/gcd(a, b) << std::endl;

    return 0;
}