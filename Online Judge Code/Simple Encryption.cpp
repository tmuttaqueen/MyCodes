#include<bits/stdc++.h>

using namespace std;

long long mod = 1e12;

set<long long>ss;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    long long d = 1;
    for( int i = 1; i <= 1000000; i++ )
    {
        d = d*n;
        d %= mod;
        if( ss.find(d) == ss.end() )
            ss.insert(d);
        else
            cout << "found ";
        cout << d << endl;
    }
    return 0;
}
