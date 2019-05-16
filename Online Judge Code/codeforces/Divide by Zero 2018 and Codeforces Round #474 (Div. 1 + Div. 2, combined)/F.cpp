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
const int M = 100005;

map<int,int>mm[M];

vector<int>tree[M];
//vector<int>to[M], cost[M], from[M];

int aa[M], bb[M], ww[M], sz[M];

void update( int u, int cur, int s, int e, int x, int v )
{
    if( s == e )
    {
        //cout << "up " <<  u << " " << s << ' ' << v << endl;
        tree[u][cur] = max( tree[u][cur], v );
        return ;
    }
    int m = (s+e)/2, c = cur<<1;
    if( x <= m )
    {
        update( u, c, s, m, x, v );
    }
    else
    {
        update( u, c+1, m+1, e, x, v );
    }
    tree[u][cur] = max( tree[u][c], tree[u][c+1] );
}

int query( int u, int cur, int s, int e, int x, int y )
{
    if( e < x || s > y ) return 0;
    if( s >= x && e <= y )
    {
        return tree[u][cur];
    }
    int m = (s+e)/2, c = cur<<1;
    int a = query( u, c, s, m, x, y );
    int b = query( u, c+1, m+1, e, x, y );
    //cout << "u " << u << " " << a << ' ' << b << ' ' << x << ' ' << y << endl;
    return max( a, b );
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m, a, b, w;
    cin >> n >> m;
    for( int i = 0; i < m; i++ )
    {
        cin >> a >> b >> w;

        aa[i] = a;
        bb[i] = b;
        ww[i] = w;
        mm[b][w];
        mm[a][w];
    }

    for( int i = 1; i <= n; i++ )
    {
        int c = 1;
        for( auto &a: mm[i] )
        {
            //cout << a.xx << " " << a.yy << endl;
            a.yy = c++;
        }
        sz[i]= c-1;
        tree[i].resize( c*5, 0 );
    }
    int ans = 0;
    for( int i = 0; i < m; i++ )
    {
        int a = aa[i], b = bb[i], w = ww[i];
        int posa = mm[a][w], v;
        if( posa > 1 )
            v = query( a, 1, 1, sz[a], 1, posa-1 );
        else
            v = 0;
        int posb = mm[b][w];
        //cout << v << ' ' << posa << " " << posb << endl;
        update( b, 1, 1, sz[b], posb, v+1 );
        ans = max( ans, v+1 );
    }
    cout << ans << endl;

    return 0;
}
