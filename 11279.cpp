#include <iostream>

class Max_heap
{
private:
    int max;
    int size;
    int *heap;


public:
    Max_heap(int N);
    void push(int data);
    int pop();
    ~Max_heap();
    void print();
};

Max_heap::Max_heap(int N)
{
    max = N+1;
    heap = new int[max];
    size = 0;
}

void Max_heap::push(int data)
{
    int node = ++size;

    while(node/2 > 0 && data > heap[node/2])
    {
        heap[node] = heap[node/2];
        node /= 2;
    }
    heap[node] = data;
}

int Max_heap::pop()
{
    if(size==0)
        return 0;

    int result = heap[1];
    heap[1] = heap[size];
    size--;
    int node = 1;
    int next, t;

    while(node <= size)
    {
        next = 2*node;
        if(next+1 <= size && heap[next] < heap[next+1])
            next++;
        
        if(next <= size && heap[node] < heap[next])
        {
            t = heap[node];
            heap[node] = heap[next];
            heap[next] = t;
        }
        else
            break;
        
        node = next;
    }

    return result;
}

Max_heap::~Max_heap()
{
    delete[] heap;
}

void Max_heap::print()
{
    for (int i = 0; i < max; i++)
        std::cout << heap[i] << " ";
    std::cout << std::endl;
    
}

int main()
{
    int N, t;
    std::cin >> N;

    Max_heap max(N);
    
    while(N--)
    {
        // std::cin >> t;
        scanf("%d", &t);
        if(t == 0)
            // std::cout << max.pop() <<std::endl;
            printf("%d\n", max.pop());
        else
            max.push(t);

        // max.print();
    }

    return 0;
}