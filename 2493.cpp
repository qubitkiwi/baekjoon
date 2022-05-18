#include <iostream>
#include <stack>

class Top
{
private:
    int *top;
    int *receive;
    int N;
    std::stack<std::pair<int, int>> s;

public:
    Top(int N);
    ~Top();

    void get_input(int *top_len);
    void chek();
    void print();
};

Top::Top(int N)
{
    this->receive = new int[N];
    this->N = N;
}

Top::~Top()
{
    delete[] top;
    delete[] receive;
    while(!s.empty()) s.pop();
}

void Top::get_input(int *top_len)
{
    this->top = top_len;
}

void Top::chek()
{
    s.push({__INT32_MAX__, 0});

    for (int i = 0; i < N; i++)
    {
        while(s.top().first < top[i])
            s.pop();
        receive[i] = s.top().second;
        s.push({top[i], i+1});
    }
}

void Top::print()
{
    for (int i = 0; i < N; i++)
        std::cout << receive[i] << " ";
    std::cout << std::endl;
}

int main()
{
    int N;
    std::cin >> N;

    int *top_len = new int[N];
    for (int i = 0; i < N; i++)
        std::cin >> top_len[i];

    Top top(N);
    top.get_input(top_len);
    top.chek();
    top.print();

    return 0;
}

// int main()
// {
//     int N;
//     std::stack<std::pair<int, int>> s;
//     std::cin >> N;

//     int *top = new int[N];
//     int *receive = new int[N];

//     for (int i = 0; i < N; i++)
//         std::cin >> top[i];
    

//     s.push({__INT32_MAX__, 0});

//     for (int i = 0; i < N; i++)
//     {
//         while(s.top().first < top[i])
//             s.pop();
//         receive[i] = s.top().second;
//         s.push({top[i], i+1});
//     }


//     for (int i = 0; i < N; i++)
//     {
//         std::cout << receive[i] << " ";
//     }
//     std::cout << std::endl;

//     delete[] top;
//     delete[] receive;
//     return 0;
// }

/*
5
6 9 5 7 4
0 0 2 2 4

 <- l
    l
    l <---- l
l   l       l
l   l <-l   l
l   l   l   l < l
l   l   l   l   l   
l   l   l   l   l
l   l   l   l   l





5
1 2 3 4 5
0 0 0 0 0
                l
            l   l
        l   l   l
    l   l   l   l
l   l   l   l   l


5
5 4 3 2 1
0 1 2 3 4

l
l < l
l   l < l
l   l   l < l
l   l   l   l < l


5
5 1 4 2 3
0 1 1 3 3

l
l  <-   l
l       l  <--  l
l       l < l   l
l < l   l   l   l


  */