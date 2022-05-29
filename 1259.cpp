#include <iostream>

int main()
{
    std::string number;
    int f, r, chek;
    
    while(1)
    {
        std::cin >> number;
        if(!number.compare("0"))
            break;
        
        chek = 0;
        f=0;
        r = number.length()-1;
        for (int i = 0; i < number.length()/2; i++)
        {
            if(number[f] != number[r])
            {
                chek = 1;
                break;
            }
            f++;
            r--;
        }

        if(chek == 0)
            std::cout << "yes\n";
        else
            std::cout << "no\n";
    }

    return 0;
}