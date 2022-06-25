#include <iostream>
#include <vector>
#include <algorithm>

bool compar(std::pair<int, int> s1, std::pair<int, int> s2){
    return s1.second > s2.second;
}

void word_weight(std::string word, std::vector<std::pair<int, int>> &weight){
    int a = 1;
    for (int i=word.length()-1; i>=0; i--){
        weight[word[i] - 'A'].second += a;
        a*=10;
    }
}

int word_math(std::vector<std::pair<int, int>> &weight){
    int max(0), a(9);

    std::sort(weight.begin(), weight.end(), compar);
    for (int i = 0; i < 10; i++){
        max += weight[i].second*a;
        a--;
    }
    return max;
}

int main(void){

    std::vector<std::pair<int, int>> weight(26);
    for (int i = 0; i < 26; i++){
        weight[i].first = i;
    }
    

    int N;
    std::string word;

    std::cin >> N;
    for (int i = 0; i < N; i++){
        std::cin >> word;
        word_weight(word, weight);
    }           

    std::cout << word_math(weight) << std::endl;

    return EXIT_SUCCESS;
}