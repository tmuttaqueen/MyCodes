/*
This too shall pass and
I will walk again,
All better and good*/

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

//find_by_order(intl) and order_of_key(intl)
//typedef tree < intll , null_type ,less<intll>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const intl M = 145678, logn = 19;

intl dist[logn][M], sz[M], par[M], vis[M], level[M], uu;
vector<intl>edge[M], cost[M], lvl[40];
vector<intl>ss[M];

void dfs( intl u, intl p )
{
    sz[u] = 1;
    for( intl v: edge[u] )
    {
        if( v !=p )
        {
            dfs(v,u);
            sz[u] += sz[v];
        }
    }
}

void dfsd( intl u, intl p, intl w )
{

    ss[uu].pb(w);
    for( intl i = 0; i < edge[u].size(); i++ )
    {
        intl v = edge[u][i], ww = cost[u][i];
        if( v != p && vis[v] == 0 )
        {
            dist[ level[v] - level[uu] ][v] = w+ww;
            dfsd( v, u, w+ww );
        }
    }
}


void centroid( intl u, intl p )
{
    intl mx =  0, ind = -1, usz = sz[u];
    for( intl v: edge[u] )
    {
        if( par[v] == 0 && sz[v] > mx )
        {
            mx = sz[v];
            ind = v;
        }
    }
    if( mx > usz/2 )
    {
        sz[u] = usz - sz[ind];
        sz[ind] = sz[ind] + sz[u];
        centroid( ind, p );
    }
    else
    {
        par[u] = p;
        if( p != -1 )
            level[u] = 1 + level[p];
        lvl[ level[u] ].pb(u);
        for( intl v: edge[u] )
        {
            if( par[v] == 0 )
            {
                centroid( v, u );
            }
        }
    }
}

intl query( intl u, intl w )
{
    intl p = u, ans = 0;
    for( int i = 0; i <= level[u]; i++ )
    {
        //what_is(ans);
        intl v  = p;
        intl d = w - dist[i][u];
        what_is(d);
        ans += upper_bound( ss[p].begin(), ss[p].end(), d ) - ss[p].begin() ;
        cout << "ans issss " << ans << endl;
        if( par[v] == -1 ) break;
        intl mn = 2876543219876543219LL;
        for( int j = 1; j <= level[v]; j++ )
        {
            //mn = min( mn, dist[j][v] );
            ans -= (upper_bound( ss[p].begin(), ss[p].end(), d - dist[j][v] ) - ss[p].begin());
            if( d - dist[j][v] >= 0 ) ans++;
        }
        //what_is(ans);
        //what_is(mn);
        //ans -= upper_bound( ss[p].begin(), ss[p].end(), d - 2*mn ) - ss[p].begin();
        //if( d - mn >= 0 ) ans++;
        p = par[p];
        what_is(ans);
    }
    what_is(ans);
    return ans;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl n, m, a, b, w;
    cin >> n >> m;
    for( int i = 1; i < n; i++ )
    {
        cin >> a >> b >> w;
        edge[a].pb(b);
        edge[b].pb(a);
        cost[a].pb(w);
        cost[b].pb(w);
    }
    dfs(1, -1);
    centroid( 1, -1 );
    intl mx = -1;
    for( int i = 1; i <= n; i++ ) mx = max(mx, level[i] );
    for( int i = 1; i <= n; i++ ) cout << i << " par: " << par[i] << endl;
    for( intl i = 0; i <= mx; i++ )
    {
        for( intl v: lvl[i] )
        {
            uu = v;
            dfsd(v, -1, 0);
            sort( ss[v].begin(), ss[v].end() );
            for( int x: ss[v] )
            {
                cout << x << " - ";
            }
            cout << endl;
            /*for( int i = 0; i <= level[v]; i++ )
            {
                cout << dist[i][v] << " -> ";
            }
            cout << endl;*/
            vis[v] = 1;
        }
    }
    while(m--)
    {
        intl u, w;
        cin >> u >> w;
        cout << query( u, w ) << endl;
    }
    return 0;
}
