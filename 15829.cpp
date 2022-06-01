#include <iostream>
#include <string>

long long int hashing(std::string str, int l)
{
    long long int sum(0), r(31), mod(1234567891), t;

    for(int i=0; i<l; i++)
    {
        t = 1;
        for (int j = 0; j < i; j++)
        {
            t *= r;
            t%=mod;
        }        
        sum += (str[i]-'`')*t;
        sum %= mod;
    }
    return sum;
}

int main()
{
    int L;
    std::cin >> L;
    
    std::string str;
    std::cin >> str;

    std::cout << hashing(str, L) << std::endl;

    return 0;
}

/*
50
aaaaaaaaaabbbbbbbbbbddddddddddeeeeeeeeeeffffffffff
 */
