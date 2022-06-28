#include <iostream>

int min_coin(int money){
    int cnt(0);

    while (money > 0){
        if(money%5 == 0){
            cnt += money/5;
            money %= 5;
        } else {
            money -= 2;
            cnt++;
        }
    }   
    
    if (money != 0)
        return -1;
    return cnt;
}

int main(){

    int money, min;
    std::cin >> money;
    
    min = min_coin(money);    
    std::cout << min << std::endl;

    return EXIT_SUCCESS;
}