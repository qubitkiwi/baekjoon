#include <iostream>
#include <vector>

class large_num
{
private:
    std::vector<long long int> number;

public:
    large_num() {};
    void fact(int N);
    int check_0();
    void print();
    ~large_num() {};
};

void large_num::fact(int N){

    int i, j, m;
    number.push_back(1);
    for (i = 1; i <= N; i++){
        
        for (j = 0; j < number.size(); j++){
            number[j] *= i;
        }     

        m = number.size();
        for (j = 0; j < m; j++){

            if(number[j]/1000000 > 0){
                if(j>= m-1)
                    number.push_back(number[j]/1000000);
                else
                    number[j+1] += number[j]/1000000;

                number[j] %= 1000000;
            }   
        }
    }   
}

int large_num::check_0(){

    int cnt(0), i;
    for (i = 0; i < number.size()-1; i++){
        for (int j = 0; j < 6; j++){
            if(number[i]%10 == 0)
                ++cnt;
            else
                return cnt;
            number[i] /= 10;
        }
    }

    while(number[i] > 0){
        if(number[i]%10 == 0)
            ++cnt;
        else
            return cnt;
        number[i] /= 10;
    }

    return cnt;
}

void large_num::print(){
    for (int i = 0; i < number.size(); i++)
        std::cout << number[i] << " ";
    std::cout << std::endl;
}

int main(){

    int N;
    std::cin >> N;

    large_num* num = new large_num;
    num->fact(N);
    // num->print();
    std::cout << num->check_0() << std::endl;
    delete num;
    
    return 0;
}