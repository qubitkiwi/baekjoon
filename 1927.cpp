#include <iostream>

class Min_heap
{
private:
    int N;
    int size;
    int *heap;    

public:
    Min_heap(int N);
    void update(int data);
    int pop();
    void print();
    ~Min_heap();
};

Min_heap::Min_heap(int N)
{
    this->N = N;
    size = 0;
    heap = new int[N];
    // for (int i = 0; i < N; i++)
    //     heap[i] = __INT_MAX__;
    
    
}

void Min_heap::update(int data)
{
    
    int node = ++size;

    while(node/2 > 0 && data < heap[node/2])
    {
        heap[node] = heap[node/2];
        node /= 2;
    }

    heap[node] = data;
}

int Min_heap::pop()
{
    if(size == 0)
        return 0;

    int node = 1;
    int result = heap[node];
    heap[node] = heap[size];
    // heap[size] = 0;
    size--;

    int next, t;
    while(node < size)
    {
        // next = (heap[2*node] < heap[2*node +1]) ? 2*node : 2*node +1;
        next = 2*node;
        if(next+1 <= size && heap[2*node] > heap[2*node +1])
            next++;


        if(next <= size && heap[node] > heap[next])
        {
            t = heap[node];
            heap[node] = heap[next];
            heap[next] = t;
        }
        else
            break;
        
        node = next;
        // printf("size : %d :", size);
        // print();
    }
    return result;
}

Min_heap::~Min_heap()
{
    delete[] heap;
}

void Min_heap::print()
{
    for (int i = 0; i < N; i++)
        std::cout << heap[i] << " ";
    std::cout << std::endl;
}


int main()
{
    int N, t;
    std::cin >> N;

    Min_heap heap(N);
    while(N--)
    {
        // std::cin >> t;
        scanf("%d", &t);
        if(t == 0)
            // std::cout << heap.pop() << std::endl;
            printf("%d\n", heap.pop());
        else
            heap.update(t);
        // heap.print();
    }
    
    return 0;
}