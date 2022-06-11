#include <iostream>
#include <array>
#include <deque>
#include <algorithm>

class print_q
{
private:
    int N;
    std::array<int, 10> imp;
    std::deque<std::pair<int, int>> input;

public:
    print_q(int N);
    void get_input();
    int process(int M);
    ~print_q();
};

print_q::print_q(int N){
    this->N = N;
    input.resize(N);
}

void print_q::get_input(){
    int t;
    for(int i=0; i<N; ++i){
        std::cin >> t;
        input.push_back({t, i});
        imp[t]++;
    }
        
}

int print_q::process(int M){
        
    int seq(0);

    while(1){
        if(std::any_of(imp.begin()+input.front().first+1, imp.end(),
            [](int i){ return i; }))
        {
            input.push_back(input.front());
            input.pop_front();
        }
        else
        {
            seq++;
            if(input.front().second == M)
                return seq;
            imp[input.front().first]--;
            input.pop_front();
        }
    }
}

print_q::~print_q(){
    while(!input.empty())
        input.pop_back();
    for(auto &elem: imp)
        elem = 0;
}


int main(){

    int tc, N, M;
    std::cin >> tc;

    while(tc--){
        std::cin >> N >> M;
        print_q *document = new print_q(N);
        document->get_input();
        std::cout << document->process(M) << "\n";
        delete document;
    }

    return 0;
}

/* 

1 0
5

4 2
1 2 3 4

1 2 3`4 1 2`3 1`2`1
2 3 4 1 2 3 1 2 1
3 4 1 2 3 1 2
4 1 2 3 

6 0
1 1 9 1 1 1

!1 1`9`1`1`1!1`1
 1 9 1 1 1!1 1
 9 1 1 1!1 1
 1 1 1!1 1 
 1 1!1 1
 1!1 1



 */