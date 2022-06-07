#include <iostream>
// #include <string>
#include <vector>
#include <algorithm>

bool comp1(std::string s1, std::string s2)
{
    if(s1.length() == s2.length())
        return s1 < s2;
    return s1.length() < s2.length();
}

int main()
{
    int N;
    std::cin >> N;

    std::vector<std::string> str(N);
    for(auto &i: str)
        std::cin >> i;

    std::sort(str.begin(), str.end(), comp1);
    str.erase(std::unique(str.begin(), str.end()), str.end());

    for (const auto& i: str)
        std::cout << i << "\n";
    
    return 0;
}

// #include <iostream>
// #include <set>
// #include <string>

// struct comp1{
//     bool operator()(const std::string& s1, const std::string& s2) const
//     {
//         if(s1.length() == s2.length())
//             return s1.compare(s2) < 0;
//         return s1.length() < s2.length();
//     }
// };

// int main()
// {
//     int N;
//     std::string str;
//     std::set<std::string, comp1> s;

//     std::cin >> N;
//     while(N--)
//     {
//         std::cin >> str;
//         s.insert(str);
//     }

//     for(const auto& word: s)
//         std::cout << word << std::endl;

//     return 0;
// }

/* 
aaaaaaaaaaacaaaaaaaaaaaaaaaaaaaaaaaaaaabs */

//  g++ 1181.cpp -O2 -Wall -lm -static -std=gnu++17 -DONLINE_JUDGE -DBOJ


/* 

13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours

 */