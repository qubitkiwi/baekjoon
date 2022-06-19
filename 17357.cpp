#include <iostream>

int main(){

    float avg, V, max, max_idx;
    int N;
    std::cin >> N;

    int num[N];
    for (auto &elem: num)
        std::cin >> elem;

    std::cout << "1\n";

    for (int k = 2; k <= N; k++){
        max = -1;
        for (int i = 0; i < N-k+1; i++){

            avg = 0;
            V = 0;

            for (int j = i; j < i+k; j++)
                avg += num[j];
            avg /= k;

            for (int j = i; j < i+k; j++)
                V += (num[j] - avg)*(num[j] - avg);
            V /= k;

            if(max < V){
                max = V;
                max_idx = i+1;
            }

        }
        std::cout << max_idx << "\n";
    }
    
    return 0;
}