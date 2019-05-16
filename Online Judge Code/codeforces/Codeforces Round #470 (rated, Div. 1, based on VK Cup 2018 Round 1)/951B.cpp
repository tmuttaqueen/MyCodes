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
const int M = 545678;

intl sum[M], mn[M], mx[M], lazy[M], reset[M];

intl ara[M], temp[M];

void init( int cn, int l, int r)
{
    if( l == r )
    {
        sum[cn] = mx[cn] = mn[cn] = ara[l];
        return;
    }
    int m = (l+r)/2, lf = cn*2;
    init( lf, l, m );
    init( lf+1, m+1, r );
    sum[cn] = sum[lf] + sum[lf+1];
    mn[cn] = min( mn[lf], mn[lf+1] );
    mx[cn] = max( mx[lf], mx[lf+1] );
}

void propagate( int cn, int l, int r )
{
    intl v = lazy[cn];
    lazy[cn] = 0;
    sum[cn] -= (r-l+1)*v;
    mn[cn] -= v;
    mx[cn] -= v;
    if( l != r )
    {
        lazy[cn*2] += v;
        lazy[cn*2+1] += v;
    }
    lazy[cn] = 0;
}

void makez( int cn, int l, int r )
{
    sum[cn] = 0;
    mn[cn] = 0;
    mx[cn] = 0;
    reset[cn] = 0;
    if( l != r )
    {
        reset[cn*2] = 1;
        reset[cn*2+1] = 1;
    }
}

intl update( int cn, int l, int r, int x, int y, intl v )
{
    //cout << l << ' ' << r << endl;
    if( reset[cn] )
    {
        makez(cn, l, r);
        return 0;
    }
    if( lazy[cn] > 0 )
    {
        propagate( cn, l, r );
    }
    if( mx[cn] == 0  )
        return 0;
    if( l > y || x > r )
        return 0;
    if( l >= x && r <= y && mn[cn] >= v )
    {
        //what_is(v);
        //what_is(l);
        //what_is(r);
        //cout << "mn" << endl;
        lazy[cn] += v;
        propagate(cn, l, r);
        intl d = v*(r-l+1);
        //what_is(d);
        return d;
    }
    if( l >= x && r <= y && mx[cn] <= v )
    {
        //cout << "mx" << endl;
        reset[cn] = 1;
        intl d = sum[cn];
        makez(cn, l, r);
        return d;
    }
    int m = (l+r)/2, lf = cn*2;
    intl a = update( lf, l, m, x, y, v );
    intl b = update( lf+1, m+1, r, x, y, v );
    sum[cn] = sum[lf] + sum[lf+1];
    mn[cn] = min( mn[lf], mn[lf+1] );
    mx[cn] = max( mx[lf], mx[lf+1] );
    return a+b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
    }
    init( 1, 1, n );
    for( int i = 1; i <= n; i++ )
        cin >> temp[i];
    intl ans;
    for( int i = 1; i <= n; i++ )
    {
        ans = update( 1, 1, n, 1, i, temp[i] );
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}
