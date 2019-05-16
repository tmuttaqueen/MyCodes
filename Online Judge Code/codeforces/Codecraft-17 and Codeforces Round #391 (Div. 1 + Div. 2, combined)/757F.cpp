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
#define pii         pair<intl, intl>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 245678, LOG = 20;
vector<pii>edge[M];
vector<int>tree[M];
int lca[M][LOG];
int id[M], par[M], depth[M];
intl dist[M];
int c, flag[M];
int subtreeSize[M];

void dijkstra( int s )
{
    priority_queue<pii>pq;
    memset( dist, 120, sizeof dist );
    pq.push( mp(0, s) );
    dist[s] = 0;
    while( !pq.empty() )
    {
        int u = pq.top().yy;
        pq.pop();
        if( flag[u] == 0 )
        {
            flag[u] = 1;
            id[c++] = u;
        }
        for( int i = 0; i < edge[u].size(); i++ )
        {
            int v = edge[u][i].xx, w =  edge[u][i].yy;
            if( dist[u] + w < dist[v] )
            {
                par[v] = u;
                dist[v] =  dist[u] + w;
                pq.push( mp(-dist[v], v) );
            }
        }
    }
}

void addVertex( int u, int p )
{
    lca[u][0] = p;
    for( int i = 1; i < LOG; i++ )
    {
        if( lca[u][i-1] == -1 )
            lca[u][i] = -1;
        else
            lca[u][i] = lca[ lca[u][i-1] ][i-1];
    }
}

int query( int x, int y )
{
    if( depth[x] < depth[y] ) swap(x, y);
    int d = depth[x] - depth[y];
    for( int i = LOG-1; i >= 0; i-- )
    {
        if( d >=  ( 1<<i ) )
        {
            x = lca[x][i];
            d -= (1<<i);
        }
    }
    if( x == y ) return x;
    for( int i = LOG-1; i>= 0; i-- )
    {
        if( lca[x][i] != lca[y][i] )
        {
            x = lca[x][i];
            y = lca[y][i];
        }
    }
    return lca[x][0];
}

void dfs( int u, int p )
{
    subtreeSize[u] = 1;
    for( int i = 0; i < tree[u].size(); i++ )
    {
        int v = tree[u][i];
        if( v != p )
        {
            dfs(v, u);
            subtreeSize[u] += subtreeSize[v];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m, s, a, b, w;
    cin >> n >> m >> s;
    for( int i = 0; i < m; i++ )
    {
        cin >> a >> b >> w;
        edge[a].pb( mp(b,w) );
        edge[b].pb( mp(a,w) );
    }
    dijkstra(s);
    addVertex(s, -1);
    depth[s] = 0;
    for( int i = 1; i < c; i++ )
    {
        int u = id[i], p = -1;
        //what_is(u);
        for( int i = 0; i < edge[u].size(); i++ )
        {
            int v = edge[u][i].xx, w = edge[u][i].yy;
            if( dist[v]+w == dist[u] )
            {
                if( p == -1 )
                {
                    p = v;
                    continue;
                }
                //cout << v << endl;
                p = query( p, v );
            }
        }
        //cout << u << " " << p << endl;
        addVertex( u, p );
        depth[u] = depth[p] + 1;
        tree[u].pb(p);
        tree[p].pb(u);
    }
    int ans = 0;
    dfs( s, -1 );
    for( int i = 1; i < c; i++ )
    {
        ans = max( ans, subtreeSize[ id[i] ] );
    }
    cout << ans << endl;
    return 0;
}
