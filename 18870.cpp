#include <iostream>
#include <algorithm>
#include <map>

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);

    std::map<long long int, int> map;
    int N;
    std::cin >> N;

    long long int data[N];
    long long int data2[N];
    
    for (auto &elem: data)
        std::cin >> elem;

    for (int i = 0; i < N; i++)
        data2[i] = data[i];
    

    std::sort(data, data+N);
    
    long long int t = data[0];
    int idx = 1;
    map[data[0]] = 0;
    for (int i = 1; i < N; i++){
        if(t == data[i])
            continue;
        map[data[i]] = idx++;
        t = data[i];
    }
    
    for (auto elem: data2){
        std::cout << map[elem] << "\n";
    }
    

    return 0;
}