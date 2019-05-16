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
#define filein      freopen("atlarge.in", "r", stdin)
#define fileout     freopen("atlarge.out", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 145678;

vector<int>edge[M];
int isleaf[M];
int ans = 0;
int par[M];
int rootdist[M], leafdist[M];

void dfs( int u, int p )
{
    par[u] = p;
    if( edge[u].size() == 1 )
        leafdist[u] = 0;
    else
        leafdist[u] = 12345678;
    for( int v: edge[u] )
    {
        if( v != p )
        {
            rootdist[v] = rootdist[u] + 1;
            dfs(v, u);
            leafdist[u] = min( 1 + leafdist[v], leafdist[u] );
        }
    }
}

void dfs1( int u, int p )
{
    if( isleaf[u] == 1 )
    {
        ans++;
        return;
    }
    for( int v: edge[u] )
    {
        if( v != p )
        {
            dfs1(v, u);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    filein;
    fileout;
    int n, k, a, b;
    cin >> n >> k;
    for( int i = 1; i < n; i++  )
    {
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    if( edge[k].size() == 1 )
    {
        cout << 1 << endl;
        return 0;
    }
    rootdist[k] = 0;
    dfs(k, -1);
    for( int i = 1; i <= n; i++ )
    {
        //cout << leafdist[i] << "; " << rootdist[i] << endl;
        if( leafdist[i] <= rootdist[i] )
            isleaf[i] = 1;
    }
    dfs1(k, -1);
    cout << ans << endl;
    return 0;
}
