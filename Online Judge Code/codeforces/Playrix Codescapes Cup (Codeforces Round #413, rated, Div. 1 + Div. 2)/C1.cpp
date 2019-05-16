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
#define pii         pair<intl, intl>
#define piii        pair<pii, int>

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

pii tree[1000000];
intl c[300000], d[300000],c1, c2, cc[400000], cd[400000];

void update( int cn, int s, int e, intl x, intl v )
{
    if ( s > x || e < x ) return;
    if( s == x && e == x )
    {
        tree[cn] = mp(v,x);
        return;
    }
    int m = (s+e)/2;
    update( cn*2, s, m, x, v );
    update( cn*2+1,m+1,e,x,v );
    tree[cn] = max( tree[cn*2], tree[cn*2+1] );
    return;
}

pii query( int cn, int s, int e, int x, int y )
{
    if( x > e || y < s )
        return mp(0LL,0LL);
    if( s >= x && e <= y )
        return tree[cn];
    int m = (s+e)/2;
    pii a = query( cn*2, s, m, x,y);
    pii b = query( cn*2+1, m+1, e, x,y );
    return max( a,b );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl n,x,y, b, p;
    char ch;
    cin >> n>> x>>y;
    for( int i= 0; i < n; i++ )
    {
        cin >> b >> p >> ch;
        if( ch == 'C' )
        {
            if( b >= c[p] )
            {
                cc[p] = c[p];
                c[p] = b;
            }
            else
                cc[p] = max( cc[p], b );
        }
        else
        {
            if( b >= d[p] )
            {
                cd[p] = d[p];
                d[p] = b;
            }
            else
                cd[p] = max( cd[p], b );
        }
    }

    intl ans = 0, cn = 200000;
    for( int i = 1; i <= cn; i++ )
        update( 1,1,cn, i, c[i] );

    for( int i = 1; i < x; i++ )
    {
        pii q = query( 1, 1, cn, 1, i );
        intl t = q.xx;
        if( t == 0 ) continue;
        intl temp = q.yy;
        update( 1,1,cn, q.yy, cc[ temp ] );
        q = query( 1, 1, cn, 1, x-i );
        update( 1,1,cn, temp, t );
        if( q.xx == 0 ) continue;
        t += q.xx;

        ans = max(ans, t);
    }

    intl t1 = query( 1, 1, cn, 1, x ).xx;

    for( int i = 1; i <= 1000000; i++ )
        tree[i] = mp(0LL,0LL);

    for( int i = 1; i <= cn; i++ )
        update( 1,1,cn, i, d[i] );

    for( int i = 1; i < y; i++ )
    {
        pii q = query( 1, 1, cn, 1, i );
        intl t = q.xx;
        if( t == 0 ) continue;
        intl temp = q.yy;
        update( 1,1,cn,q.yy, cd[ temp ] );
        q = query( 1, 1, cn, 1, y-i );
        update( 1,1,cn, temp, t );
        if( q.xx == 0 ) continue;
        t += q.xx;
        ans = max(ans, t);
    }

    intl t2 = query( 1, 1, cn, 1, y ).xx;
    if( t1 != 0 && t2 != 0 )
        ans = max( ans, t1+t2 );

    cout << ans << endl;

    return 0;
}




