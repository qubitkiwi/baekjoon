#include <iostream>
#include <vector>
#include <algorithm>

void dfs(int start, int M, int d, std::vector<int> input, std::vector<int> recode){
    if(M == d){
        for(const auto elem: recode)
            std::cout << elem << " ";
        std::cout << "\n";
        return ;
    }
    
    for (size_t i = start; i < input.size(); i++){
        recode[d] = input[i];
        dfs(i, M, d+1, input, recode);
    }
    
}


int main(){

    int N, M;
    std::cin >> N >> M;

    std::vector<int> recode(M);
    std::vector<int> input(N);
    for(auto &elem: input)
        std::cin >> elem;
    
    std::sort(input.begin(), input.end());

    dfs(0, M, 0, input, recode);

    return 0;
}