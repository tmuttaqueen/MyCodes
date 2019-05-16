#include<bits/stdc++.h>

using namespace std;


knuth_b randRange(int a, int b)
{
    generator(std::chrono::system_clock::now().time_since_epoch().count());

    return generator;
}


int randomRange(int a, int b)
{

    uniform_int_distribution<int> distribution(a,b);
    //normal_distribution<double> distribution(5.0,2.0);
    return distribution(generator);
}

int main()
{
    for( int i = 0; i < 100; i++ )
    {
        for( int i = 0; i <= 10000; i++ );
        cout << randomRange(0, 10000000) << endl;
    }


    return 0;
}



