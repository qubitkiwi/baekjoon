#include <iostream>
#include <algorithm>

struct mamber
{
    int age;
    std::string name;
};

int main()
{
    int N;
    std::cin >> N;
    mamber m[N];

    for (auto &i: m)
        std::cin >> i.age >> i.name;
    
    std::stable_sort(m, m+N, 
        [](mamber a, mamber b) -> bool { return (a.age < b.age); }
    );

    for(auto i: m)
        std::cout << i.age << " " <<i.name<< "\n";

    return 0;
}