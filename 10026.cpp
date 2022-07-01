#include <iostream>
#include <vector>
#include <queue>

int bfs(std::vector<std::string> map){
    std::vector<std::vector<int>> visit(map.size(), std::vector<int>(map.size(), 0));
    std::queue<std::pair<int, int>> q;
    int cnt(0);
    int next[2][4] = {{0, 1, 0, -1},
                      {1, 0, -1, 0}};
    int x, y, nx, ny, i(0), j(0), chek;

    while (true){
        chek = 0;
        for (; i < visit.size(); i++){
            for (; j < visit.size(); j++){
                if (visit[i][j] == 0){
                    y = i;
                    x = j;
                    chek = 1;
                    break;
                    
                }
            }
            j = 0;
            if (chek == 1) break;
        }

        if (chek == 0)
            break;

        visit[y][x] = ++cnt;
        q.push({y, x});

        while (!q.empty()){

            y = q.front().first;
            x = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++){
                ny = y + next[0][k];
                nx = x + next[1][k];

                if (0<= nx && nx < map.size() && 0<= ny && ny < map.size()){
                    if (map[ny][nx] == map[y][x] && visit[ny][nx] == 0){
                        visit[ny][nx] = visit[y][x];
                        q.push({ny, nx});
                    }
                }
            }   
        }
    }
    
    return cnt;
}

int main(){

    int N, nomal, weak;
    std::cin >> N;

    std::vector<std::string> map(N);
    for (auto &line : map)
        std::cin >> line;
    
    nomal = bfs(map);

    for (auto &col : map){
        for (auto &elem : col){
            if (elem == 'R'){
                elem = 'G';
            }
        }        
    }
    weak = bfs(map);

    std::cout << nomal << " " << weak << std::endl;

    return EXIT_SUCCESS;
}


/* 
5
RRRBB
GGBBB
BBBRR
BBRRR
RRRRR
 */