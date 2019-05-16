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
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double
typedef struct touple
{
    int xx,yy,zz;
    touple( int x = 0, int y = 0, int z = 0 ){xx=x; yy=y; zz=z;}
    bool operator<(const touple &a )
    {
        if( xx == a.xx )
		{
            if( yy == a.yy )
                return zz < a.zz;
            return yy < a.yy;
        }
        return xx<a.xx;
    }

} tii;
//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;


// x = i, ~x = n+i //n is number of variable
vector<int>edge[22222], transEdge[22222];
int scc[22222], topsort[22222], vis[22222], c, sccNo, ans[22222], top[22222];


void dfs1( int u )
{
    vis[u]= 1;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( !vis[v] )
        {
            dfs1(v);
        }
    }
    top[c++] = u;
}

void dfs2( int u )
{
    vis[u]= 1;
    for( int i = 0; i < transEdge[u].size(); i++ )
    {
        int v = transEdge[u][i];
        if( !vis[v] )
        {
            dfs2(v);
        }
    }
    scc[u] = sccNo;
    topsort[c++] = u;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        c = 1;
        sccNo = 1;
        memset(vis, 0, sizeof vis);
        memset( scc,0 , sizeof scc );
        memset( ans, -1, sizeof ans );
        int m, n, a, b, f = 1;
        cin >> m >> n;
        for( int i = 1; i <= 2*n; i++ )
        {
            edge[i].clear();
            transEdge[i].clear();
        }
        for( int i = 0; i < m; i++ )
        {
            cin >> a >> b;
            if( a > 0 && b > 0  )
            {
                edge[n+a].pb(b);
                edge[n+b].pb(a);
                transEdge[a].pb(n+b);
                transEdge[b].pb(n+a);
            }
            else if( a > 0 && b < 0 )
            {
                b = -b;
                edge[b].pb(a);
                edge[n+a].pb(n+b);
                transEdge[a].pb(b);
                transEdge[n+b].pb(a+n);
            }
            else if( a < 0 && b > 0 )
            {
                a = -a;
                edge[n+b].pb(n+a);
                edge[a].pb(b);
                transEdge[n+a].pb(n+b);
                transEdge[b].pb(a);
            }
            else
            {
                a = -a;
                b = -b;
                edge[a].pb(n+b);
                edge[b].pb(n+a);
                transEdge[n+b].pb(a);
                transEdge[n+a].pb(b);
            }
        }
        for( int i = 1; i <= 2*n; i++ )
        {
            if( !vis[i] )
            {
                //what_is(i);
                dfs1(i);
            }
        }
        //what_is(c);
        /*for( int i = 1; i <= 2*n; i++ )
        {
            cout << topsort[i] << endl;
        }*/
        memset( vis, 0, sizeof vis );
        c = 0;
        for( int i = 2*n; i >= 1; i-- )
        {
            //what_is( top[i] );
            if( !vis[top[i]])
            {
                //what_is(topsort[i]);
                dfs2( top[i] );
                sccNo++;
            }
        }

        for( int i = 0; i < c; i++ )
        {
            //what_is(topsort[i]);
            if( topsort[i] <= n && scc[ topsort[i] ] == scc[ topsort[i]+n ] )
            {
                f = 0;
            }
            else if( topsort[i] > n && ans[ topsort[i] ] == -1 )
            {
                //what_is( topsort[i] );
                ans[ topsort[i] ] = 0;
                ans[ topsort[i]-n ] = 1;
            }
            else if ( topsort[i] <= n && ans[ topsort[i] ] == -1 )
            {
                //cout << topsort[i] << "   tttt " << endl;
                ans[ topsort[i] ] = 0;
                ans[ topsort[i]+n ] = 1;
            }
        }
        c = 0;
        for( int i = 1; i <= n; i++ )
        {
            c += ans[i];
        }

        if( f == 0 )
        {
            cout << "Case " << caseno++ << ": No" << endl;
        }
        else
        {
            cout << "Case " << caseno++ << ": Yes" << endl;
            cout << c;
            for( int i = 1; i <= n; i++ )
            {
                if( ans[i] )
                    cout << " " << i;
            }
            cout << endl;
        }

    }
    return 0;
}
