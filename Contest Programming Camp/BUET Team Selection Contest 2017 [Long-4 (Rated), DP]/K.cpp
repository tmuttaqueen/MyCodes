#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

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

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl dp[111111][2];
vector<int>edge[111111];
intl ara[111111];

void dfs( int u, int p )
{
    dp[u][0] = -1000000000;
    for( int v: edge[u] )
    {
        if( v != p )
        {
            dfs(v,u);
            dp[u][0] = max( max(dp[v][0], dp[v][1]), dp[u][0] );
        }
    }
    intl ans = ara[u];
    for( int v: edge[u] )
    {
        if( v != p && dp[v][1] > 0 )
        {
            ans += dp[v][1];
        }
    }
    dp[u][1] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int s;
    cin >> s;
    what_is(s);
    return 0;
}
