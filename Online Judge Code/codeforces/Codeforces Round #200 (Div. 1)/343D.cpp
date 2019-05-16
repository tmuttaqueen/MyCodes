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
const int M = 456789;

int tree[M*8], lazy[8*M];
int ind[M*2], sz[M*2], c = 1;
vector<int>edge[M*2];

void propagate( int cn, int s, int e )
{
    if( s!=e )
    {
        lazy[2*cn] = lazy[cn];
        lazy[2*cn+1] = lazy[cn];
    }
    tree[cn] = lazy[cn];
    lazy[cn] = -1;
}

void update( int cn, int s, int e, int x, int y, int v )
{
    if( lazy[cn] != -1 )
        propagate(cn, s, e);
    if( s > y || e < x ) return;
    if( s >= x && e <= y )
    {
        lazy[cn] = v;
        propagate(cn, s, e);
        return ;
    }
    int m = (s+e)/2;
    update( 2*cn, s, m, x, y, v );
    update( 2*cn+1, m+1, e, x, y, v );
    tree[cn] = min( tree[2*cn], tree[2*cn+1] );
    return;
}

int query( int cn, int s, int e, int x, int y )
{
    if( lazy[cn] != -1 )
        propagate(cn, s, e);
    if( s > y || e < x )
        return M*10;
    if( s >= x && e <= y )
    {
        return tree[cn];
    }
    int m = (s+e)/2;
    int a = query( 2*cn, s, m, x, y );
    int b = query( 2*cn+1, m+1, e, x, y );
    return min(a,b);
}

int dfs( int u, int p )
{
    //cout << c << " -- " << u << " " << endl;
    ind[u] = c++;
    sz[u] = 1;
    for( int v: edge[u] )
    {
        if( p != v )
        {
            sz[u] += dfs(v,u);
        }
    }

    //cout << u << " sz " << sz[u] << " ind " << ind[u] << endl;
    return sz[u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    filein;
    int n, a, b;
    cin >> n;
    for( int i = 1; i < n; i++ )
    {
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dfs(1,-1);
    memset( lazy, -1, sizeof lazy );
    int q;
    cin >> q;
    while(q--)
    {
        cin >> a >> b;
        if( a == 1 )
        {
            update( 1, 1, n, ind[b], ind[b] + sz[b]-1, 1 );
        }
        else if(a == 2)
        {
            update( 1, 1, n, ind[b], ind[b], 0 );
        }
        else
        {
            int s = query( 1, 1, n, ind[b], ind[b] + sz[b]-1 );
            //what_is(b);
            //what_is(s);
            cout << (s>0) << endl;
        }
    }
    return 0;
}
