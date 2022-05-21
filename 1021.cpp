#include <iostream>
#include <deque>

int main()
{
    std::deque<int> dq;

    int N, K, cnt=0;
    int revese, fword;
    std::cin >> N >> K;

    int *arr = new int[K];
    for (int i = 0; i < K; i++)
        std::cin >> arr[i];
    
    for (int i = 1; i <= N; i++)
        dq.push_back(i);
    
    int i=0;
    revese = fword = 0;
    while(i<K)
    {
        if(dq.front() == arr[i])
        {
            dq.pop_front();
            revese = dq.size() - fword+1;
            cnt = (revese < fword) ? cnt+revese : cnt+fword;
            revese = fword = 0;
            i++;
        }
        else
        {
            dq.push_back(dq.front());
            dq.pop_front();
            fword++;
        }
    }
    
    std::cout << cnt <<std::endl;
    delete[] arr;
    return 0;
}