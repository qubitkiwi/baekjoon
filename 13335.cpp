#include <iostream>
#include <queue>

class Truck
{
private:
    int *truck;
    int truck_N;
    int bridge_len;
    int bridge_max;
    int time;
    int now_wight;
    std::queue<int> q;

public:
    Truck(int N, int W, int L);
    ~Truck();

    void get_wight(int *track_wight);
    void chek_time();
    int get_time();

};

Truck::Truck(int N, int W, int L)
    : truck_N(N), bridge_len(W), bridge_max(L), time(0), now_wight(0)
{
    for (int i = 0; i < W; i++)
        q.push(0);
}

Truck::~Truck()
{
    delete[] truck;
    while (!q.empty()) q.pop();
}

void Truck::get_wight(int *track_wight)
{
    truck = track_wight;
}

void Truck::chek_time()
{
    int i=0;
    
    while (i < truck_N)
    {
        now_wight -= q.front();
        q.pop();

        if (bridge_max < now_wight + truck[i])
        {
            q.push(0);
        }
        else
        {
            q.push(truck[i]);
            now_wight += truck[i];
            i++;
        }
        time++;
    }
    time += q.size();    
}

int Truck::get_time()
{
    return this->time;
}

int main()
{
    int N, W, L, time;
    std::cin >> N >> W >> L;

    int *truck_wight = new int[N];
    for (int i = 0; i < N; i++)
        std::cin >> truck_wight[i];
    
    Truck truck(N, W, L);
    truck.get_wight(truck_wight);
    truck.chek_time();
    time = truck.get_time();

    std::cout << time << std::endl;
    return 0;
}

/* 
4 2 10
7 4 5 6

1, 0 7
2, 7 0 
3, 0 4
4, 4 5
5, 5 0
6, 0 6
7, 6 0
8, 0 0

1 100 100
10

0 0 0 0 0 0 ~ 0 0 10


10 100 100
10 10 10 10 10 10 10 10 10 10

0 0 



 */