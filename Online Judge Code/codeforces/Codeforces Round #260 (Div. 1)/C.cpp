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

int dia[M], vis[M], dp1[M], dp2[M], par[M];
vector<int>edge[M];
vector<int>v;


void dfs( int u, int p )
{
    vis[u] = 1;
    v.pb(u);
    int f = 0;
    for( int v: edge[u] )
    {
        if( v == p ) continue;
        dfs(v, u);
        f++;
    }
    int mx1 = 0, mx2 = 0;
    for( int v: edge[u] )
    {
        if( v == p ) continue;
        if( dp2[v] >= mx1 )
        {
            mx2 = mx1;
            mx1 = dp2[v];
        }
        else if( dp2[v] >= mx2 )
        {
            mx2 = dp2[v];
        }
    }
    if( f >= 2)
    {
        dp1[u] = mx1+mx2 + 2;
        dp2[u] = mx1+1;
    }
    else if( f > 0 )
    {
        dp2[u] = mx1+1;
    }
}

int find_par( int u )
{
    if( par[u] == u ) return u;
    return par[u] = find_par( par[u] );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m, q, a, b;
    cin >> n >> m >> q;
    for( int i = 0; i < m; i++ )
    {
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    for( int i = 1; i <= n; i++ )
    {
        if( vis[i] == 0 )
        {
            v.clear();
            dfs(i, -1);
            int mx = 0;
            for( int u: v )
            {
                par[u] = i;
                mx = max(mx, max( dp1[u], dp2[u]) );
            }
            dia[i] = mx;
        }
    }
    while(q--)
    {
        int x, u, v;
        cin >> x;
        if( x == 1 )
        {
            cin >> u;
            cout << dia[ find_par(u) ] << endl;
        }
        else
        {
            cin >> u >> v;
            int pu = find_par(u), pv = find_par(v);
            if( pu != pv )
            {
                par[pu] = pv;
                dia[pv] = max( ( dia[pu] +1 )/2 + (dia[pv] + 1)/2 + 1, max( dia[pu], dia[pv] ) );
            }
        }
    }
    return 0;
}
