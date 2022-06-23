#include <iostream>
#include <vector>
#include <cmath>

void serch(std::vector<int> tree, int N){

    int deep(0), start, idx, incres;
    start = tree.size();
    incres = tree.size()+1;

    while (deep < N){
        start /= 2;

        for (idx = start; idx < tree.size(); idx += incres){
            std::cout << tree[idx] << " ";            
        }
        std::cout << std::endl;
        deep++;
        incres /= 2;
    }
    return ;
}


int main(){

    int N;
    std::cin >> N;

    std::vector<int> tree(pow(2, N)-1);
    for (auto &elem : tree)
        std::cin >> elem;
    
    serch(tree, N);
    
    return 0;
}