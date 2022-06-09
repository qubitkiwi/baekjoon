#include <iostream>
#include <stack>
#include <vector>

class Stack_sequence
{
private:
    std::vector<int> input;
    std::stack<int> s;
    std::string str;
public:
    Stack_sequence(int N);
    ~Stack_sequence();

    void get_input();
    bool chek();
    void print();
};

Stack_sequence::Stack_sequence(int N){\
    input.resize(N);
}

Stack_sequence::~Stack_sequence(){
    while(!s.empty()) s.pop();
}

void Stack_sequence::get_input(){
    for (auto &elem: input)
        std::cin >> elem;    
}

bool Stack_sequence::chek(){
    
    int idx(0), seq(1);

    while(idx < input.size()) {

        if(seq <= input[idx]) {
            s.push(seq++);
            str.append("+");
        } else if(s.top() == input[idx]) {
            str.append("-");
            s.pop();
            idx++;
        } else if(s.top() > input[idx] && seq >= input[idx])
            return false;
    }
    return true;
}

void Stack_sequence::print(){
    for(const auto elem: str)
        std::cout << elem << "\n";
}

int main(){

    int N;
    std::cin >> N;

    Stack_sequence s(N);
    s.get_input();
    
    if(s.chek())
        s.print();
    else
        std::cout << "NO" << std::endl;

    return 0;
}


/* 
8

4
3
6
8
7
5
2
1


+
+
+
+
-
-
+
+
-
+
+
-
-
-
-
-

4, 3, 6, 8, 7, 5, 2. 1

+ + + + - - + + - + + - - - - 
                   `8
     `4      `6   7 7`7
    3 3`3   5 5 5 5 5 5`5
  2 2 2 2 2 2 2 2 2 2 2 2`2
1 1 1 1 1 1 1 1 1 1 1 1 1 1`1

 
5
1, 2, 5, 3, 4

+ - + - + + + -
            5
          4 4 4
1   2   3 3 3 3 


 */