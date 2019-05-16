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

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl ara[200005], n;
intl dp[200005][2]; // 0-sub, 1-sum
intl vis[200005][2];

intl solve( intl u, intl sign )
{
    //what_is(u);
    if( u == 1 )
        return -1;
    if( u < 1 || u > n )
        return 0;
    if( dp[u][sign] != 0 )
        return dp[u][sign];
    if( vis[u][sign] == 1 )
        return -1;
    vis[u][sign] = 1;
    intl d = 0;
    if( sign == 0 )
        d = solve( u - ara[u], 1 );
    else
        d = solve( u + ara[u], 0 );
    //what_is(d);
    dp[u][sign] += ara[u] + d;
    if( d == -1 )
        dp[u][sign] = -1;
    return dp[u][sign];

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    cin >> n;
    for( int i = 2; i <= n; i++ ) cin >> ara[i];
    for( int i = 1; i < n; i++ )
    {
        if( dp[1+i][0] == 0 )
            solve( 1+i, 0 );
        if( dp[1+i][1] == 0 )
            solve( 1+i, 1 );
    }
    for( int i = 1; i < n; i++ )
    {
        if( dp[1+i][0] == -1 )
        {
            cout << -1 << endl;
            continue;
        }
        cout << i + dp[1+i][0] << endl;
    }


    return 0;
}




