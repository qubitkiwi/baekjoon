#include <iostream>

class Chess
{
private:
    int N, M;
    char ***map;
    int ***cnt;

public:
    Chess(int N, int M);
    void get_data();
    void chek();
    void count();
    int min();
    ~Chess();

    void print();
};

void Chess::print()
{
    std::cout << std::endl;
    for (int i = 0; i < 2; i++)
    {
        for (int c = 0; c < N; c++)
        {
            for (int r = 0; r < M; r++)
            {
                std::cout << (int) map[i][c][r];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    for (int i = 0; i < 2; i++)
    {
        for (int c = 0; c < N-7; c++)
        {
            for (int r = 0; r < M-7; r++)
            {
                std::cout << cnt[i][c][r] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }    
}


Chess::Chess(int N, int M)
{       
    this->N = N;
    this->M = M;

    map = new char**[2];
    for (int i = 0; i < N; i++)
    {
        map[i] = new char*[N];
        for (int j = 0; j < N; j++)
        {
            map[i][j] = new char[M];
        }
    }

    cnt = new int**[2];
    for (int i = 0; i < 2; i++)
    {
        cnt[i] = new int*[N-7];
        for (int j = 0; j < N-7; j++)
        {
            cnt[i][j] = new int[M-7];
        }
   }

}

void Chess::get_data()
{
    for (int i = 0; i < N; i++)
        std::cin >> map[0][i];
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            map[1][i][j] = map[0][i][j];
        }
    }
}

void Chess::chek()
{
    char board;

    for (int i = 0; i < 2; i++)
    {
        for (int c = 0; c < N; c++)
        {
            board = ((i+c)%2 == 0) ? 'W' : 'B';
            for (int r = 0; r < M; r++)
            {
                map[i][c][r] = (map[i][c][r] == board) ? 0 : 1;
                board = (board == 'B') ? 'W' : 'B';
            }
        }
    }
}


void Chess::count()
{
    int sum(0);

    for (int i = 0; i < 2; i++)
    {
        sum = 0;
        for (int c = 0; c < 8; c++)
        {
            for (int r = 0; r < 8; r++)
            {
                sum += map[i][c][r];
            }
        }
        cnt[i][0][0] = sum; // 가장 처음 구간

        
        for (int k = 1; k < M-7; k++) // 가로 한줄
        {
            cnt[i][0][k] = cnt[i][0][k-1];

            for (int c = 0; c < 8; c++)
            {
                cnt[i][0][k] -= map[i][c][k-1];
                cnt[i][0][k] += map[i][c][k+7];
            }
        }
            
        for (int j = 1; j < N-7; j++) //나머지 모두
        {
            for (int k = 0; k < M-7; k++)
            {
                cnt[i][j][k] = cnt[i][j-1][k];

                for (int r = k; r < k+8; r++)
                {
                    cnt[i][j][k] -= map[i][j-1][r];
                    cnt[i][j][k] += map[i][j+7][r];
                }
            }
        } 
    }
    
}


int Chess::min()
{
    int min = cnt[0][0][0];

    for (int i = 0; i < 2; i++)
    {
        for (int c = 0; c < N-7; c++)
        {
            for (int r = 0; r < M-7; r++)
            {
                if(min > cnt[i][c][r])
                {
                    min = cnt[i][c][r];
                }
            }
        }
    }

    return min;
}

Chess::~Chess()
{
    for (int i = 0; i < 2; i++)
    {
        for (int c = 0; c < N-7; c++)
            delete[] cnt[i][c];
        delete[] cnt[i];
    }
   delete[] cnt;

//     for (int i = 0; i < 2; i++)
//     {
//         for (int c = 0; c < N-7; c++)
//             delete[] map[i][c];
//         delete[] map[i];
//     }
//    delete[] map;

}




int main()
{    
    int N, M, min;
    std::cin >> N >> M;

    Chess chess(N, M);
    chess.get_data();
    chess.chek();
    chess.count();
    // chess.print();

    std::cout << chess.min() << std::endl;

    return 0;
}

/* #include <iostream>

class Chess
{
private:
    int N, M;
    char **map;
    char ***diff;
    int ***cnt;

public:
    Chess(int N, int M);
    void get_data();
    void chek();
    void count();
    int min();
    ~Chess();

    void print();
};

void Chess::print()
{
    std::cout << std::endl;
    for (int i = 0; i < 2; i++)
    {
        for (int c = 0; c < N; c++)
        {
            for (int r = 0; r < M; r++)
            {
                std::cout << (int) diff[i][c][r];
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    for (int i = 0; i < 2; i++)
    {
        for (int c = 0; c < N-7; c++)
        {
            for (int r = 0; r < M-7; r++)
            {
                std::cout << cnt[i][c][r] << " ";
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }    
}


Chess::Chess(int N, int M)
{       
    this->N = N;
    this->M = M;
    
    map = new char*[N];
    for (int i = 0; i < N; i++)
        map[i] = new char[M];

    diff = new char**[2];
    for (int i = 0; i < N; i++)
    {
        diff[i] = new char*[N];
        for (int j = 0; j < N; j++)
        {
            diff[i][j] = new char[M];
        }
    }

    cnt = new int**[2];
    for (int i = 0; i < 2; i++)
    {
        cnt[i] = new int*[N-7];
        for (int j = 0; j < N-7; j++)
        {
            cnt[i][j] = new int[M-7];
        }
   }

}

void Chess::get_data()
{
    for (int i = 0; i < N; i++)
        std::cin >> map[i];
}

void Chess::chek()
{
    char board;

    for (int i = 0; i < 2; i++)
    {
        for (int c = 0; c < N; c++)
        {
            board = ((i+c)%2 == 0) ? 'W' : 'B';
            for (int r = 0; r < M; r++)
            {
                diff[i][c][r] = (map[c][r] == board) ? 0 : 1;
                board = (board == 'B') ? 'W' : 'B';
            }
        }
    }
}


void Chess::count()
{
    int sum(0);

    for (int i = 0; i < 2; i++)
    {
        sum = 0;
        for (int c = 0; c < 8; c++)
        {
            for (int r = 0; r < 8; r++)
            {
                sum += diff[i][c][r];
            }
        }
        cnt[i][0][0] = sum; // 가장 처음 구간

        
        for (int k = 1; k < M-7; k++) // 가로 한줄
        {
            cnt[i][0][k] = cnt[i][0][k-1];

            for (int c = 0; c < 8; c++)
            {
                cnt[i][0][k] -= diff[i][c][k-1];
                cnt[i][0][k] += diff[i][c][k+7];
            }
        }
            
        for (int j = 1; j < N-7; j++) //나머지 모두
        {
            for (int k = 0; k < M-7; k++)
            {
                cnt[i][j][k] = cnt[i][j-1][k];

                for (int r = k; r < k+8; r++)
                {
                    cnt[i][j][k] -= diff[i][j-1][r];
                    cnt[i][j][k] += diff[i][j+7][r];
                }
            }
        } 
    }
    
}


int Chess::min()
{
    int min = cnt[0][0][0];

    for (int i = 0; i < 2; i++)
    {
        for (int c = 0; c < N-7; c++)
        {
            for (int r = 0; r < M-7; r++)
            {
                if(min > cnt[i][c][r])
                {
                    min = cnt[i][c][r];
                }
            }
        }
    }

    return min;
}

Chess::~Chess()
{
    for (int i = 0; i < N; i++)
        delete[] map[i];
    delete[] map;

    for (int i = 0; i < 2; i++)
    {
        for (int c = 0; c < N-7; c++)
            delete[] cnt[i][c];
        delete[] cnt[i];
    }
   delete[] cnt;

//     for (int i = 0; i < 2; i++)
//     {
//         for (int c = 0; c < N-7; c++)
//             delete[] diff[i][c];
//         delete[] diff[i];
//     }
//    delete[] diff;

}




int main()
{    
    int N, M, min;
    std::cin >> N >> M;

    Chess chess(N, M);
    chess.get_data();
    chess.chek();
    chess.count();
    // chess.print();

    std::cout << chess.min() << std::endl;

    return 0;
} */

/* 
10 13
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
WWWWWWWWWWBWB
WWWWWWWWWWBWB

 */




