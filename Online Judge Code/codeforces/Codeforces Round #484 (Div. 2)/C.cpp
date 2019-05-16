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
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;
int dp[M];
vector<int>edge[M];
int sz[M];

void dfssz( int u, int p )
{
    sz[u] = 1;
    for( int v: edge[u] )
    {
        if(v==p) continue;
        dfssz(v, u);
        sz[u] += sz[v];
    }
}

void dfs( int u, int p )
{
    for( int v: edge[u] )
    {
        if( v == p ) continue;
        dfs(v, u);
        if( sz[v] %2 == 0 )
            dp[u] += 1 + dp[v];
        else
            dp[u] += dp[v];
    }
    //cout << u << " " << sz[u] << " " << dp[u] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    if(n%2)
    {
        cout << -1 << endl;
        return 0;
    }
    for( int i = 1; i < n; i++ )
    {
        int a, b;
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dfssz(1, -1);
    //debug;
    dfs(1,-1);
    cout << dp[1] << endl;
    return 0;
}
