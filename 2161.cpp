#include <iostream>
#include <queue>

int main(void)
{
    std::queue<int> q;
    int N;
    std::cin >> N;

    for (int i = 1; i <= N; i++)
        q.push(i);

    while(!q.empty())
    {
        std::cout << q.front() << " ";
        q.pop();
        q.push(q.front());
        q.pop();
    }    
    std::cout << std::endl;

    return 0;
}