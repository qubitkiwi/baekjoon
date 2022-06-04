#include <iostream>
#include <vector>
#include <algorithm>

bool comp1(const std::vector<int> num1, const std::vector<int> num2)
{
    if(num1[1] < num2[1])
        return true;
    if(num1[1] == num2[1])
        return num1[0] < num2[0];
    return false;
}

int main()
{
    int N;
    std::cin >> N;

    std::vector<std::vector<int>> num(N, std::vector<int>(2));
    for(auto &i: num)
        for (int &j: i)
            scanf("%d", &j);
            // std::cin >> j;
    

    std::sort(num.begin(), num.end(), comp1);

    for(auto i: num)
    {
        for(auto j: i)
            // std::cout << j << " ";
            printf("%d ", j);
        // std::cout << std::endl;
        printf("\n");
    }    

    return 0;
}