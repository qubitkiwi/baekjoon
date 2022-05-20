#include <iostream>
#include <deque>

int main()
{
    std::deque<std::pair<int, int>> dq;
    
    int N, idx, next;
    std::cin >> N;

    int *seq = new int[N];
    for (int i = 1; i <= N; i++)
    {
        std::cin >> next;
        dq.push_back({i, next});
    }
    
    for (int i = 0; i < N; i++)
    {
        idx = dq.front().first;
        next = dq.front().second;
        dq.pop_front();
        
        seq[i] = idx;
        
        if(0 < next)
        {
            next--;
            while(next--)
            {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else
        {
            while(next++)
            {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }
    }

    for (int i = 0; i < N; i++)
        std::cout << seq[i] << " ";    
    std::cout << std::endl;
    
    delete[] seq;
    return 0;
}