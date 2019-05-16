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
const int mx = 100005, logn = 60;
const int MX = 1e9+1;
int tree[mx*logn], lft[mx*logn], rgt[mx*logn], ID = 2, head = 1;

void update( int cn, int s, int e, int x, int y, int v )
{
    if( tree[cn] == e-s+1 )
        return;
    if( s >= x && e <= y )
    {
        tree[cn] = e-s+1;
        return;
    }
    int m = (s+e)/2;
    if( m >= x )
    {
        if( lft[cn] == 0 ) lft[cn] = ID++;
        update( lft[cn], s, m, x, y, v );
    }
    if( m+1 <= y )
    {
        if( rgt[cn] == 0 ) rgt[cn] = ID++;
        update( rgt[cn], m+1, e, x, y, v );
    }
    tree[cn] = min( e-s+1, max( tree[cn],  tree[ lft[cn] ]+ tree[ rgt[cn] ] ));
}

int query( int cn, int s, int e, int x, int y )
{
    if( cn == 0 ) return 0;
    if( tree[cn] == e-s+1 )
    {
        return min( e,y )-max(s,x)+1;
    }
    if( s >= x && e <= y )
    {
        return tree[cn];
    }
    int m = (s+e)/2;
    int a = 0, b = 0;
    if( m >= x )
        a = query( lft[cn] , s, m, x, y );
    if( m+1 <= y )
        b = query( rgt[cn] , m+1, e, x, y );
    return a+b;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int m, c = 0;
    cin >> m;
    while(m--)
    {
        int a, x, y;
        cin >> a >> x >> y;
        if( a == 1 )
        {
            c = query( head, 1, MX,  x+c, y+c );
            cout << c << endl;
        }
        else
        {
            update( head, 1, MX, x+c, y+c, 1 );
            //what_is( tree[1] );
        }
    }
    return 0;
}
