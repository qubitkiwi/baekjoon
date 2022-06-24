#include <iostream>

bool chek(std::string str, std::string word, int start){
    for (int i = 0; i < word.length(); i++){
        if (str[start+i] != word[i])
            return false;
    }
    return true;
}

int main(){

    std::string str;
    std::string word;
    int same(0);

    getline(std::cin, str, '\n');
    getline(std::cin, word, '\n'); 

    for (int i = 0; i <= (int) str.length() - (int) word.length(); i++){
         if(chek(str, word, i)){
            same++;
            i += word.length()-1;
        }            
    }
    
    std::cout << same << std::endl;

    return 0;
}