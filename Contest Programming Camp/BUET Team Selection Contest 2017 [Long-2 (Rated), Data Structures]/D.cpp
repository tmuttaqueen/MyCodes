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

pii tree[1111111];
int lazy[1111111];

void propagate(int cn, int s, int e)
{
    if( lazy[cn] == -1 )
        return;
    if( s != e )
    {
        lazy[cn*2] = lazy[cn*2+1] = lazy[cn];
    }
    tree[cn].xx = tree[cn].yy = lazy[cn];
    lazy[cn] = -1;
}


intl update( int cn, int s, int e, int x, int y, int val )
{
    propagate( cn, s, e );
    if( s > y || e < x )
    {
        return 0;
    }
    if( s >= x && e <= y && tree[cn].yy > val )
    {
        return 0;
    }
    if( s >= x && e <= y && tree[cn].xx <= val )
    {
        //tree[cn].xx = tree[cn].yy = val;
        lazy[cn] = val;
        propagate(cn, s, e);
        return e-s+1;
    }
    int m = (s+e)/2;
    intl a = update( cn*2, s, m, x, y, val );
    intl b = update( cn*2+1, m+1, e, x, y, val );
    tree[cn].xx = max( tree[cn*2].xx, tree[cn*2+1].xx );
    tree[cn].yy = min( tree[cn*2].yy, tree[cn*2+1].yy );
    return a+b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, mx = 100001;
    cin >> t;
    while(t--)
    {
        memset(tree, 0, sizeof tree);
        memset(lazy, -1, sizeof lazy);
        int n, a, b, c;
        cin >> n;
        intl ans = 0;
        for( int i = 0; i < n; i++ )
        {
            cin >> a >> b >> c;
            a++;
            intl d = update(1,1,mx, a, b, c);
            //what_is(d);
            ans += d;
        }
        cout << ans << endl;
    }
    cin >> t;
    return 0;
}
