#include<bits/stdc++.h>

using namespace std;

#define intl long long
//#define __int128 long long

intl cnt[100], ara[100];

__int128 expo( intl a, int b )
{
    __int128 ans = 1;
    for( int i = 0; i < b; i++ ) ans *= a;
    return ans;
}

void process( intl n, intl ara[] )
{
    __int128 up = n;
    for( int i = 60; i >= 2; i-- )
    {
        double u = pow( double(n), 1.0/i );
        intl hi = u+1, lo = 2, sol = 0;
        while( lo <= hi )
        {
            intl m = (lo+hi)/2;
            __int128 v = expo(m, i);
            if( v <= up )
            {
                sol = m;
                lo = m+1;
            }
            else
                hi = m-1;
        }
        ara[i] = max(0LL,sol-1);
        for( int j = i+i; j <= 60; j+=i )
        {
            ara[i] -= ara[j];
        }
    }
    ara[1] = n-1;
    for( int i = 2; i <= 60; i++ ) ara[1] -= ara[i];
    //for( int i = 1; i <= 4; i++ ) cout << i << " i: " << ara[i] << endl;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    intl mx = 1e18;
    process(mx, cnt);
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        intl n;
        cin >> n;
        if( n == mx )
        {
            cout << 1 << endl;
            continue;
        }
        int p = 1;
        for( int i = 1; i <= 60; i++ )
        {
            if( n - cnt[i] > 0 )
            {
                n -= cnt[i];
            }
            else{
                p = i;
                break;
            }
        }
        //cout << "p: " << p << endl;
        intl lo = 2, hi = mx;
        intl ans = 1;
        while( lo <= hi )
        {
            intl m = (lo+hi)/2;
            process(m, ara);
            //cout << m << " " << ara[p] << endl;
            if( ara[p] >= n )
            {
                ans = m;
                hi = m- 1;
            }
            else
                lo = m+1;
        }
        cout << ans << endl;
    }

    return 0;
}
