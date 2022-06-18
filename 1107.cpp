#include <iostream>
// #include <string>

class Chenal
{
private:
    int init_chenal;
    int target_chenal;
    int min_count;
    bool num[10] = {false, };

public:
    Chenal(int init);
    void wanted(int want);
    void get_broken(int len);
    bool chek(std::string str);
    void min_cut();
    int min();
    ~Chenal();
};

Chenal::Chenal(int init){
    init_chenal = init;
}

void Chenal::wanted(int target){
    target_chenal = target;
}

void Chenal::get_broken(int len){
    int t;
    for (int i = 0; i < len; i++){
        std::cin >> t;
        num[t] = true;
    }    
}

bool Chenal::chek(std::string str){
    
    for (int i = 0; i < str.length(); i++)
        if(num[str[i] - '0'])
            return false;
    return true;
}

void Chenal::min_cut(){

    int len;
    std::string str;
    min_count = abs(init_chenal - target_chenal);

    if(min_count == 0)
        return ;

    for (int i = 0; i <= 1000000; i++){
        
        str = std::to_string(i);
        if(chek(str)){
            len = abs(target_chenal-i)+str.length();
            min_count = std::min(min_count, len);
        }
    }
}

int Chenal::min(){
    return min_count;
}

Chenal::~Chenal(){
}



int main(){

    int N, M;
    std::cin >> N >> M;

    Chenal chenal(100);
    chenal.wanted(N);
    chenal.get_broken(M);
    chenal.min_cut();
    std::cout << chenal.min() << std::endl;

    return 0;
}