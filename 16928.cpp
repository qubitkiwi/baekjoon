#include <iostream>
#include <queue>

int min_load(int *map){
    int visit[101] = {0, };
    std::queue<int> q;

    int x, nx;
    x = 1;
    q.push(x);
    visit[x] = 0;

    while(!q.empty()){
        x = q.front();
        q.pop();

        if (x == 100)
            break;        

        for (int i = 1; i <= 6; i++){
            nx = x + i;
            if (nx<=100){
                while (map[nx] != 0){
                    // visit[nx] = visit[x] + 1;
                    nx = map[nx];
                }
                if (visit[nx] == 0){
                    visit[nx] = visit[x] + 1;
                    q.push(nx);
                }
                // printf("%d %d %d\n", nx, visit[nx], map[nx]);
            }
        }
    }
    return visit[100];
}

int main(){

    int map[101] = {0, };
    int N, M, start, end, min;

    std::cin >> N >> M;
    while(N--){
        std::cin >> start >> end;
        map[start] = end;
    }

    while(M--){
        std::cin >> start >> end;
        map[start] = end;
    }

    min = min_load(map);
    std::cout << min << std::endl;

    return EXIT_SUCCESS;
}