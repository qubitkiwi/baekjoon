#include <iostream>

int main(void)
{
    int i, in, out, now=0, max=0;

    for(i=0; i<10; i++)
    {
        std::cin >> out >> in;
        now += in - out;
        if(max < now)
            max = now;
    }
    std::cout << max << std::endl;

    return 0;
}