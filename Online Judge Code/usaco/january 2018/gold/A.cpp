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
#define filein      freopen("mootube.in", "r", stdin)
#define fileout     freopen("mootube.out", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>
#define piii        pair<int,pii>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 145678;

piii edge[M];
int ans[M];
int sz[M];
vector<piii>qu;
int par[M];

int findpar( int u )
{
    if( par[u] == u )
        return u;
    return par[u] = findpar( par[u] );
}

void add( int u, int v )
{

    int pu = findpar(u), pv = findpar(v);
    //cout << u << ' ' << pu << " - " << v << " " << pv << endl;
    if( pu != pv )
    {
        if( sz[pu] < sz[pv] )
        {
            par[pu] = pv;
            sz[pv] += sz[pu];
        }
        else
        {
            par[pv] = pu;
            sz[pu] += sz[pv];
        }
    }
}

int findSZ( int u )
{
    int p = findpar(u);
    return sz[p];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    filein;
    fileout;
    int n, q, a, b, c;
    cin >> n >> q;
    for( int i = 1; i < n; i++ )
    {
        cin >> edge[i].yy.xx >> edge[i].yy.yy >> edge[i].xx;
    }
    for( int i = 1; i <= n; i++ )
    {
        par[i] = i;
        sz[i] = 1;
    }
    for( int i = 1; i <= q; i++ )
    {
        cin >> a >> b;
        qu.pb( mp(a, mp(b, i)) );
    }
    sort( edge+1, edge + n  );
    reverse( edge+1, edge + n );
    sort( qu.begin(), qu.end() );
    reverse( qu.begin(), qu.end() );
    int lim = edge[1].xx;
    int qc = 0;
    while( qc < q && qu[qc].xx > lim )
    {
        ans[ qu[qc].yy.yy ] = 1;
        qc++;
    }
    for( int i = 1; i < n; i++ )
    {
        int hi = edge[i].xx;
        int lo = -1;
        if( i < n-1 )
            lo = edge[i+1].xx;
        add( edge[i].yy.xx, edge[i].yy.yy );
        while( qc < q && qu[qc].xx > lo && qu[qc].xx <= hi )
        {
            ans[ qu[qc].yy.yy ] = findSZ( qu[qc].yy.xx );
            qc++;
        }
    }
    for( int i = 1; i <= q; i++ )
    {
        cout << ans[i]-1 << "\n";
    }

    return 0;
}
