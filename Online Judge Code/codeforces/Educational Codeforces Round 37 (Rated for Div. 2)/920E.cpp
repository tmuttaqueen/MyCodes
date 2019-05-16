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
#define filein      freopen("out.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 1445678;

intl sum[M], mx[M], mn[M];
intl divi[M];
intl lazy[M];
intl ara[M];

void sieve()
{
    int n = 1000000;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = i; j <= n; j += i )
        {
            divi[j]++;
        }
    }
}

void propagate( int cn, int l, int r )
{
    int n = cn*2;
    if( l != r )
    {
        lazy[n] = lazy[cn];
        lazy[n+1] = lazy[cn];
    }
    intl d = lazy[cn];
    lazy[cn] = 0;
    sum[cn] = (r-l+1)*d;
    mx[cn]= d;
    mn[cn] = d;
    return;
}

void init( int cn, int l, int r )
{
    if( l == r )
    {
        sum[cn] =mx[cn] = mn[cn] = ara[l];
        return ;
    }
    int m = (l+r)/2;
    int n = cn*2;
    init( n, l, m );
    init( n+1, m+1, r );
    sum[cn] = sum[n] + sum[n+1];
    mx[cn] = max( mx[n], mx[n+1] );
    mn[cn] = min( mn[n], mn[n+1] );
}

void update( int cn, int l, int r, int x, int y )
{
    if( lazy[cn] > 0 )
        propagate( cn, l, r );
    if( r < x || l > y || mx[cn] <= 2 )
        return;
    if( l >= x && r <= y && mx[cn] == mn[cn] )
    {
        lazy[cn] = divi[mx[cn]];
        propagate(cn, l, r);
        return;
    }
    int m = (l+r)/2;
    int n = cn*2;
    update( n, l, m, x, y );
    update( n+1, m+1, r, x, y );
    sum[cn] = sum[n] + sum[n+1];
    mx[cn] = max( mx[n], mx[n+1] );
    mn[cn] = min( mn[n], mn[n+1] );
}

intl query( int cn, int l, int r, int x, int y )
{
    if( lazy[cn] > 0 )
        propagate(cn, l, r);
    if( r < x || l > y )
        return 0;
    if( l >= x && r <= y )
    {
        return sum[cn];
    }
    int m = (l+r)/2;
    int n = cn*2;
    intl a = query( n, l, m, x, y );
    intl b = query( n+1, m+1, r, x, y );
    return a+b;
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    sieve();
    int n, q;
    cin >> n >> q;
    for( int i = 1; i <= n; i++ ) cin >> ara[i];
    init(1, 1, n);
    while(q--)
    {
        int a, l, r;
        cin >> a >> l >> r;
        if(a==1)
        {
            update( 1, 1, n, l, r );
        }
        else
        {
            intl d = query( 1, 1, n, l, r );
            cout << d << "\n";
        }
    }
     return 0;
}
