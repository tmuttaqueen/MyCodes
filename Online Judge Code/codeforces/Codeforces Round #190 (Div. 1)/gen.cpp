#include<bits/stdc++.h>

using namespace std;

int val( int a, int b )
{

    int d = rand();
    d %= (b-a+1);
    d += a;
    return d;
}

int main()
{
    //freopen("out.txt", "w", stdout);
    srand(time(0));
    int mx = 50000;
    int n = val(2, mx);
    cout << n << endl;
    for( int i = 1; i < n; i++ )
    {
        int d = val(1, n);
        if( d == i )
    }
    return 0;
}
