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
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl tree[1111111], lazy[1111111];
intl lt[111111], rt[111111], val[111111];

void propagate( int cn, int s, int e )
{
    if( lazy[cn] == 0 ) return;
    if( s == e )
    {
        tree[cn] += lazy[cn];
    }
    else
    {
        lazy[cn*2] += lazy[cn];
        lazy[cn*2+1] += lazy[cn];
        tree[cn] += lazy[cn];
    }

    lazy[cn] = 0;
}

void update( int cn, int s, int e, int x, int y, int v )
{
    propagate(cn,s,e);
    if( s > y || e < x ) return;
    if( s >= x && e <= y )
    {
        lazy[cn] += v;
        propagate(cn,s,e);
        return;
    }
    int m = (s+e)/2;
    update( cn*2, s, m, x, y, v );
    update( cn*2+1, m+1, e, x, y, v );
    tree[cn] = max( tree[cn*2], tree[cn*2+1] );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, q;
    cin >> n >> q;
    for( int i = 0; i < q; i++ )
    {
        int l,r, x;
        cin >> l >> r >> x;
        lt[i] = l;
        rt[i] = r;
        val[i] = x;
        update( 1, 1, n, l, r, x );
    }
    intl ans = 2000000000;
    for( int i = 0; i < q; i++ )
    {
        update( 1,1,n, lt[i], rt[i], -val[i] );
        ans = min( ans, tree[1] );
        update( 1,1,n, lt[i], rt[i], val[i] );
    }
    cout << ans << endl;
    return 0;
}
