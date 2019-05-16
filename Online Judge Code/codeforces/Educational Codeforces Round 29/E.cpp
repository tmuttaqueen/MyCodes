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
const int M = 2423456;;

int tree[M], lazy[M];
pii ara[M];

void propagate( int cn, int s, int e )
{
    if( s != e )
    {
        lazy[2*cn] += lazy[cn];
        lazy[2*cn+1] += lazy[cn];
    }
    tree[cn] += lazy[cn] ;
    lazy[cn] = 0;
}

void update( int cn, int s, int e, int x, int y, int v )
{
    //cout << cn << " " << s << " " << e << endl;
    if( lazy[cn] != 0 )
    {
        propagate(cn, s, e);
    }
    if( e < x || s > y ) return;
    if( s >= x && e <= y )
    {
        //cout << s << " --- " << e << endl;
        lazy[cn]+=v;
        //what_is( lazy[cn] );
        propagate(cn,s,e);
        //what_is( tree[cn] );
        return;
    }
    int m = (s+e)/2;
    update( 2*cn, s, m, x, y, v );
    update( 2*cn+1, m+1, e, x, y, v );
    tree[cn] = min( tree[2*cn], tree[2*cn+1] );
    //cout << " ---    " << cn << " " << tree[cn] << endl;
}

int query( int cn, int s, int e, int x, int y )
{
    if( lazy[cn] != 0 )
        propagate(cn,s,e);
    if( e < x || s > y ) return 1234567;
    if( s >= x && e <= y )
        return tree[cn];
    int m = (s+e)/2;
    int a = 1234567, b = 1234567;
    //if( m >= x )
        a = query( 2*cn, s, m, x, y );
    //if( m+1 <= y )
        b =query( 2*cn+1, m+1, e, x, y );
    return min( a, b );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, a, b, ID = 1;
    cin >> n;
    for( int i = 0; i < n; i++  )
    {
        cin >> a >> b;
        ara[i]= mp( a,b );
        mm[a];
        mm[b];
        mm[b+1];
    }
    for( auto it = mm.begin(); it != mm.end(); it++ )
    {
        it->yy = ID++;
    }
    ID--;
    for( int i = 0; i < n; i++ )
    {
        ara[i].xx = mm[ ara[i].xx ];
        ara[i].yy = mm[ ara[i].yy ];
        update( 1, 1, ID, ara[i].xx, ara[i].yy, 1 );

    }
    //cout << tree[1] << endl;
    //for( int i  = 1; i < 5; i++ )
        //cout << query( 1,1 , ID, 1, 2) << endl;
    for( int i = 0; i < n; i++ )
    {
        //cout << ara[i].xx << " " << ara[i].yy << endl;
        update( 1 ,1, ID, ara[i].xx, ara[i].yy, -1 );
        int x = query( 1, 1, ID, ara[i].xx, ara[i].yy );
        //what_is(x);
        if( x != 0 )
        {
            cout << i+1 << endl;
            return 0;
        }
        update( 1 ,1, ID, ara[i].xx, ara[i].yy, 1 );
    }
    cout << -1 << endl;
    return 0;
}
