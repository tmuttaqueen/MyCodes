#include <bits/stdc++.h>

using namespace std;

long long mx = 10001;
long long ara[20004], val[20004];


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    long long n, m, k, a, fl = 0;
    cin >> n >> m;
    for( int i = 0; i < m; i++ )
    {
        cin >> k;
        int f = 0, d, p;

        for( int j = 0; j < k; j++ )
        {
            cin >> a;

            if( a < 0 )
                d = abs(a) + mx;
            else
                d = a;
            if( ara[d] > 0 )
                continue;
            if( a > 0 )
                p = a + mx;
            else
                p = abs(a);
            if( ara[p] > 0 && f == 0 )
            {
                f = 1;
                fl++;
            }
            val[j] = d;
            ara[d]++;
        }
        for( int j = 0; j < k; j++ )
        {
            ara[ val[j]] = 0;
        }
    }
    if( fl == m )
        cout << "NO\n";
    else
        cout << "YES\n";
    return 0;
}




