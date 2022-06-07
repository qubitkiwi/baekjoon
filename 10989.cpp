#include <iostream>
#include <vector>

int main()
{
    int N, t;
    std::cin >> N;
    std::vector<int> arr(10001);

    for (int i = 0; i < N; i++)
    {
        // std::cin >> t;
        scanf("%d", &t);
        arr[t]++;
    }

    for (int i = 1; i < 10001; i++)
    {
        while(arr[i]>0)
        {
            // std::cout << i << "\n";
            printf("%d\n", i);
            arr[i]--;
        }
    }
    

    return 0;
}