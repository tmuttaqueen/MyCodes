#include<bits/stdc++.h>

using namespace std;

#define intl long long

intl ara[300005];
intl sum[300005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    intl n, k, a;
    cin >> n >> k;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
    }


    sort( ara+1, ara+n+1 );
    reverse( ara+1, ara+n+1 );
    for( int i = 1; i <= n; i++ )
        sum[i] = sum[i-1] + ara[i];
    intl ans = 0, reduced = 0;
    intl hi = ara[1], lo = ara[n];
    while( hi > lo )
    {
        //cout << hi << " " << lo << endl;
        intl l = lo, h = hi, nxt = -1, ind = -1;
        while( l <= h )
        {
            intl m = (l+h)/2;
            int ll = 1, hh = n;
            while( ll <= hh )
            {
                int mm = (ll+hh)/2;
                int val = min(hi, ara[mm]);
                if( val >= m )
                {
                    ind = mm;
                    ll = mm+1;
                }
                else
                    hh = mm-1;
            }
            //cout << "ind " << ind << " m " << m << endl;
            if( sum[ind] - reduced - ind*m <= k )
            {
                //cout << sum[ind] << " " <<  sum[ind] - reduced - ind*m << endl;
                h = m-1;
                nxt = m;
            }
            else
                l =  m+1;
        }
        //cout << "nxt " << nxt << " ind " << ind << endl;
        hi = nxt;
        ans++;
        reduced += (sum[ind] - reduced - ind*nxt);
        //cin >> a;
    }

    cout << ans << endl;

    return 0;
}
