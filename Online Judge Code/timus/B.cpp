#include<bits/stdc++.h>

using namespace std;

#define intl long long

int main()
{
    intl n, m, k;
    cin >> n >> m;
    intl mn = max( 0LL, n-m*2 );
    for( k = 0; k <= n; k++ )
    {
        if( k*(k-1)/2 >= m )
            break;
    }
    intl mx = max(0LL, n-k);
    cout << mn << " " << mx << endl;
}
