#include<bits/stdc++.h>

using namespace std;

int main()
{
    random_device rd;
    mt19937 gen{rd()};
    bernoulli_distribution dis{.9}; //P(1) = 90%, P(0) = 10%
    int N = 10;
    for (auto i = 0; i < N; ++i)
    {
        cout << (dis(gen) ? "head" : "tail") << endl;
    }

    return 0;
}

