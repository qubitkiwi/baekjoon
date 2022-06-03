#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N, M, min, anw, t, tmp;
    std::cin >> N >> M;

    std::vector<int> number(N);
    for (auto &i : number)
        std::cin >> i;

    std::sort(number.begin(), number.end());

    anw = number[0] + number[1] + number[2];
    min = abs(anw - M);

    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            for (int k = j+1; k < N; k++)
            {
                tmp = number[i] + number[j] + number[k];
                t = abs(tmp - M);

                if(tmp > M)
                    break;

                if(min > t)
                {
                    min = t;
                    anw = tmp;
                }
                
                if(min == 0)
                {
                    std::cout << anw << std::endl;
                    return 0;
                }

            }
        }
    }
    
    std::cout << anw << std::endl;
    return 0;
}