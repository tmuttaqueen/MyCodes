#include<bits/stdc++.h>

using namespace std;

int main()
{
    std::random_device rd;
    std::mt19937 gen{rd()};
    std::uniform_int_distribution<> dis{0, 1000000};
    int N = 10;
    int s = 0;
    for (auto i = 0; i < N; ++i)
    {
        //s += dis(gen);
        cout << dis(gen) << endl;
    }

    cout << s/double(N) << endl;


    return 0;
}
