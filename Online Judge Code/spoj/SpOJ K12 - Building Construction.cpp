#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<intl, int>

bool comp( pii a, pii b )
{
    return a.xx < b.xx;
}


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        intl n, m, ans = 1e9;
        cin >> n;
        pii ara[n];
        intl temp[n], cost[10005];
        memset( cost, 0, sizeof(cost) );

        for( int i = 0; i < n; i++ ) cin >> ara[i].xx;
        for( int i = 0; i < n; i++ ) cin >> ara[i].yy;
        sort( ara, ara + n, comp );
        temp[0] = ara[0].yy;
        for( int i = 1; i < n; i++ ) temp[i] = temp[i-1] + ara[i].yy;
        for( int i = 1; i < n; i++ )
        {
            cost[0] += (ara[i].xx-ara[0].xx)*ara[i].yy;
        }
        ans = cost[0];
        int l = ara[n-1].xx - ara[0].xx;
        pii tt = ara[0];
        for( int i = 1; i <= l; i++ )
        {
            tt.xx++;
            auto p = lower_bound( ara, ara + n, tt, comp );
            int x = p - ara;
            cost[i] = ( cost[i-1] + temp[x-1] - temp[n-1] + temp[x-1] );
            ans = min( ans, cost[i] );
        }
        cout << ans << endl;
    }

    return 0;
}



