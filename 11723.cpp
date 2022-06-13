#include <iostream>

class Set
{
private:
    int set;

public:
    Set() { set=0; };
    void add(int x);
    void remove(int x);
    int check(int x);
    void toggle(int x);
    void all();
    void empty();
    ~Set() {};
};

void Set::add(int x){
    set |= (1<<x);
}

void Set::remove(int x){
    set &= ~(1<<x);
}

int Set::check(int x){
    if((set & (1<<x)) >0)
        return 1;
    return 0;
}

void Set::toggle(int x){
    if(check(x))
        remove(x);
    else
        add(x);
}

void Set::all(){
    set = __INT_MAX__;
}

void Set::empty(){
    set = 0;
}



int main(){
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int M, x;
    std::string cmd;
    Set set;

    std::cin >> M;

    while(M--){
        std::cin >> cmd;

        if(!cmd.compare("add")){
            std::cin >> x;
            set.add(x);
        }else if(!cmd.compare("remove")){
            std::cin >> x;
            set.remove(x);
        }else if(!cmd.compare("check")){
            std::cin >> x;
            std::cout << set.check(x) << "\n";
        }else if(!cmd.compare("toggle")){
            std::cin >> x;
            set.toggle(x);
        }else if(!cmd.compare("all")){
            set.all();
        }else if(!cmd.compare("empty")){
            set.empty();
        }
    }

    return 0;
}