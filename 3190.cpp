#include <iostream>
#include <queue>

const int apple = -1;

class Dummy
{
private:
    std::vector<std::vector<int>> map;
    std::queue<std::pair<int, int>> position;
    bool life;
    int l_time;
    int dirction;
    const int d_cr[2][4] = {{-1, 0, 1, 0},
                            { 0, 1, 0, -1}};
    
public:
    Dummy(int N);
    void print();
    void append_apple(int c, int r);
    int life_time();
    int chek();
    void turn(char way);
    void run(int t);
    ~Dummy();
};

Dummy::Dummy(int N){
    l_time = 0;
    life = true;
    dirction = 1;

    map.resize(N);
    for (int i = 0; i < N; i++)
        map[i] = std::vector<int>(N);
    
    map[0][0] = 1;
    position.push({0, 0});
}

void Dummy::append_apple(int c, int r){
    map[c][r] = apple;
}

int Dummy::life_time(){
    return l_time;
}

int Dummy::chek(){

    int c, r, nc, nr;
    c = position.back().first;
    r = position.back().second;

    nc = c + d_cr[0][dirction];
    nr = r + d_cr[1][dirction];

    if (nc < 0 || map.size() <= nc || nr < 0 || map.size() <= nr)
        return 1; // 범위 초과 사망

    if (map[nc][nr] == 1)
        return 2; // 자신을 먹어 사망

    if (map[nc][nr] == apple)
        return 3; // 사과 획득
    
    return 4; // 전진
}

void Dummy::turn(char way){
    
    if(way == 'D'){ // right
        dirction = (dirction+1)%4;        
    } else if (way == 'L') { // lift
        dirction = (dirction-1) < 0 ? 3 : (dirction-1);
    }
}

void Dummy::run(int t){

    while (l_time < t){

        if(!life)
            return ;
        
        l_time++;

        int c, r, nc, nr;
        c = position.back().first;
        r = position.back().second;

        nc = c + d_cr[0][dirction];
        nr = r + d_cr[1][dirction];
        
        switch (chek())
        {
        case 1:
            life = false;
            break;
        case 2:
            life = false;
            break;
        case 3: // 사과 획득
            map[nc][nr] = 1;
            position.push({nc, nr});
            break;
        case 4:
            map[nc][nr] = 1;
            position.push({nc, nr});

            c = position.front().first;
            r = position.front().second;
            map[c][r] = 0;
            position.pop();
            break;
        }
    }
}

void Dummy::print(){
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map.size(); j++)
        {
            // std::cout << map[i][j] << " ";
            printf("%2d ", map[i][j]);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Dummy::~Dummy(){
}


int main(){

    int N, apple_len, c, r, cmd_len, t;
    char way;
    std::cin >> N;
    Dummy snake(N);

    std::cin >> apple_len;
    for (int i = 0; i < apple_len; i++){
        std::cin >> c >> r;
        snake.append_apple(c-1, r-1);
    }
    
    std::cin >> cmd_len;
    for (int i = 0; i < cmd_len; i++){
        std::cin >> t >> way;
        snake.run(t);
        snake.turn(way);
    }

    snake.run(snake.life_time() + N);
    std::cout << snake.life_time() << std::endl;
    
    return 0;
}