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

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

const int SZ = 1000005, mod = 1000000007;

const int nver = 100005, factor = 20;
int par[nver], depth[nver], lca[factor][nver];
vector<int>edge[nver];
int subg[nver];

void create_lca( int lca[][nver], int par[], int v ) // v is vertex number
{
    lca[0][v] = par[v];
    for( int j = 1; j < factor; j++ )
    {
        if( lca[j-1][v] != -1 )
            lca[j][v] = lca[j-1][ lca[j-1][v] ];
        else
            break;
    }
}

int nthpar( int lca[][nver], int v, int n )
{
    for( int i = factor - 1; i >= 0 && n > 0; i-- )
    {
        if( (1<<i) <= n )
        {
            v = lca[i][v];
            n -= (1<<i);
        }
    }
    return v;
}

int find_lca( int lca[][nver], int depth[], int u, int v )
{
    if( depth[u] < depth[v] ) //after this u is deeper than v
    {
        swap(u,v);
    }
    int diff = depth[u] - depth[v];
    u = nthpar(lca, u, diff);
    if( u == v )
        return u;
    for( int i = factor-1; i >= 0; i--  )
    {
        if( lca[i][u] != lca[i][v] )
        {
            u = lca[i][u];
            v = lca[i][v];
        }
    }
    return lca[0][u];
}

void dfs( int u, int p )
{
    subg[u] = 1;
    for( int v: edge[u] )
    {
        if( v != p )
        {
            par[v] = u;
            depth[v] = depth[u] + 1;
            create_lca( lca, par, v );
            dfs(v,u);
            subg[u] += subg[v];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, u, v;
    cin >> n;
    for( int i = 1; i < n; i++ )
    {
        cin >> u >> v;
        edge[u].pb(v);
        edge[v].pb(u);
    }
    par[1] = -1;
    depth[1] = 0;
    dfs(1,-1);
    int q;
    cin >> q;
    while( q-- )
    {
        cin >> u >> v;
        int d =  find_lca( lca, depth, u, v );
        int diff1 = -depth[d] + depth[u], diff2 = -depth[d] + depth[v] ;
        if( (diff1+diff2)%2 )
        {
            cout << 0 << "\n";
            continue;
        }
        int l = (diff1+diff2)/2;
        if( diff1 == diff2 )
        {
            int d1 = nthpar( lca, u, diff1-1 ), d2 = nthpar( lca, v, diff2-1 );
            int ans = n - subg[d1] - subg[d2];
            cout << ans << "\n";
        }
        else if( diff1 > diff2 )
        {
            int d1 = nthpar( lca, u, l ), d2 = nthpar(lca, u, l-1);
            int ans = subg[d1] - subg[d2];
            cout << ans << "\n";
        }
        else
        {
            int d1 = nthpar( lca, v, l ), d2 = nthpar(lca, v, l-1);
            int ans = subg[d1] - subg[d2];
            cout << ans << "\n";
        }
    }
    return 0;
}



