#include <iostream>
#include <queue>

int bfs(int A, int B){

    long long int x, nx;
    int cnt;
    
    std::queue<std::pair<long long int, int>> q;
    q.push({A, 1});

    while(!q.empty()){
        
        x = q.front().first;
        cnt = q.front().second;
        q.pop();
        
        if(x == B)
            return cnt;
        
        nx = 2*x;
        if(nx <= B && 0 < nx){
            q.push({nx, cnt+1});
        }

        nx = x*10+1;
        if(nx <= B && 0 < nx){
            q.push({nx, cnt+1});
        }
    }        

    return -1;
}

int main(){

    int A, B;
    std::cin >> A >> B;
    std::cout << bfs(A, B) << std::endl;

    return 0;
}