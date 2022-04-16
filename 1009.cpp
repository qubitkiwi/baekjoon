#include <iostream>

int main(void)
{
    int a, b, i, T, anw;
    std::cin >> T;
    
    while(T--)
    {
        std::cin >> a >> b;

        anw = 1;
        for(i=0; i<b; i++)
            anw = (anw*a)%10;
        
        if(anw == 0) anw = 10;
        std::cout << anw << std::endl;
    }

    return 0;
}