#include <iostream>
#include <vector>
#include <algorithm>

void dfs(int M, int d, std::vector<int> input, std::vector<int> recode, std::vector<bool> visit)
{
    if(M == d)
    {
        for(auto elem: recode)
            // std::cout << elem << " ";
            printf("%d ", elem);
        // std::cout << std::endl;
        printf("\n");
        return ;
    }

    for(int i=0; i<input.size(); i++)
    {
        recode[d] = input[i];
        
        if(visit[i] == 1)
            continue;
        visit[i] = true;
        dfs(M, d+1, input, recode, visit);

        visit[i] = false;
    }
}

int main()
{
    int N, M;
    std::cin >> N >> M;

    std::vector<int> recode(M);
    std::vector<int> input(N);
    std::vector<bool> visit(N);
    for (auto &elem : input)
        std::cin >> elem;

    std::sort(input.begin(), input.end());


    dfs(M, 0, input, recode, visit);

    return 0;
}