#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

typedef tree < intl, null_type,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl cost[505][505], dp[505][505];
vector<intl>cur, ans, omit;
const intl inf = 111111111111111LL;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    ans.pb(0);
    int n, a;
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            if( i != j )
                dp[i][j] = inf;
            cin >> cost[i][j];

        }
    }
    for( int i = 1; i <= n; i++ )
    {
        cin >> a;
        omit.pb(a);
    }
    if( n == 1 )
    {
        cout << 0 << endl;
        return 0;
    }
    cur.pb( omit[n-1] );
    cur.pb(omit[n-2]);
    dp[ cur[0] ][ cur[1] ] = cost[ cur[0] ][ cur[1] ];
    dp[ cur[1] ][ cur[0] ] = cost[ cur[1] ][ cur[0] ];
    ans.pb( dp[ cur[0] ][ cur[1] ] + dp[ cur[1] ][ cur[0] ] );
    for( int i = n-3; i >= 0; i-- )
    {
        cur.pb( omit[i] );
        int v = cur[n-i-1];
        int sz = n-i-1;

        for( int k = 0; k <= sz; k++ )
        {
            dp[v][cur[k]] = cost[v][ cur[k] ];
            dp[cur[k] ][v] = cost[ cur[k] ][v];
        }

        for( int j = 0; j <= sz; j++ )
        {
            for( int k = 0; k <= sz; k++ )
            {
                //printf("j = %lld k = %lld\n", cur[j], cur[k] );
                dp[v][cur[k]] = min( dp[v][cur[k]], dp[v][cur[j]]+ dp[cur[j]][cur[k]] );
                dp[cur[k]][v] = min( dp[cur[k]][v], dp[cur[j]][v]+ dp[cur[k]][cur[j]] );
            }
        }
        for( int j = 0; j <= sz; j++ )
        {
            for( int k = 0; k <= sz; k++ )
            {
                dp[cur[j]][cur[k]] = min( dp[cur[j]][cur[k]], dp[cur[j]][v] + dp[v][cur[k]] );
                dp[cur[k]][cur[j]] = min( dp[cur[k]][cur[j]], dp[cur[k]][v] + dp[v][cur[j]] );
            }
        }
        for( int j = 0; j <= sz; j++ )
        {
            for( int k = 0; k <= sz; k++ )
            {
                dp[cur[j]][cur[k]] = min( dp[cur[j]][cur[k]], dp[cur[j]][v] + dp[v][cur[k]] );
            }
        }
        intl sum = 0;
        for( int j = 0; j <= sz; j++ )
        {
            for( int k = 0; k <= sz; k++ )
            {
                sum += dp[cur[j]][cur[k]]; //= min( dp[cur[j]][cur[k]], dp[cur[j]][v] + dp[v][cur[k]]);
                //sum += dp[cur[k]][cur[j]];
            }
        }
        ans.pb(sum);
    }
    for( int i = n-1; i >= 0; i-- )
    {
        cout << ans[i] << " ";
    }
    return 0;
}




