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

map<int,int>mm;
int ara[111111], temp[111111], ind[111111], c = 1;
int tree[111111*100], ID = 1, L[111111*100], R[111111*100], root[111111];

void init( int cn, int s, int e )
{

    if( s==e )
    {
        tree[cn] = 0;
        return;
    }
    int m = (s+e)/2;
    L[cn] = ID++;
    R[cn] = ID++;
    init( L[cn], s, m );
    init( R[cn], m+1, e );
    tree[cn] = tree[ L[cn] ] + tree[ R[cn] ];
}

int update( int cn, int s, int e, int x )
{
    int id = ID++;
    if( s == e )
    {
        tree[id] = 1;
        return id;
    }
    int m = (s+e)/2;
    L[id] = L[cn];
    R[id] = R[cn];
    if( x <= m )
    {
        L[id] = update( L[id], s, m, x );
    }
    else
    {
        R[id] = update( R[id], m+1, e, x );
    }
    tree[id] = tree[ L[id] ] + tree[ R[id] ];
    return id;
}

int query( int cn, int s, int e, int x, int y )
{
    if( s > y || e < x ) return 0;
    if( s >= x && e <= y ) return tree[cn];
    int m = (s+e)/2;
    int a = query( L[cn], s, m, x, y );
    int b = query( R[cn], m+1, e, x, y );
    return a+b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m;
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
        temp[i] = ara[i];
        mm[ ara[i] ] = i;
    }
    sort( temp+1, temp+n+1 );
    for( int i = 1; i <= n; i++ )
    {
        ind[i] = mm[ temp[i] ];
    }
    root[0] = 0;
    init(0,1,n);
    for( int i = 1; i <= n; i++ )
    {
        root[i] = update( root[i-1],1, n, ind[i] );
    }
    int x, y, k;
    temp[0] = -1;
    while( m-- )
    {
        cin >> x >> y >> k;
        int l = 1, r = n, ans = 0;
        while( l <= r )
        {
            int m = (l+r)/2;
            int d = query( root[m], 1, n, x, y );
            //cout << "m " << m << "   d " << d << endl;
            if( d >= k )
            {
                ans = m;
                r = m-1;
            }
            else
                l = m+1;
        }
        cout << temp[ans] << endl;
    }
    return 0;
}
