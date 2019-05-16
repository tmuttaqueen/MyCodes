#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<intl,intl>
#define piii pair<int, pii>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 200005;

piii tree[4*MAXN]; pii lazy[4*MAXN];
int n, Time;

intl a[MAXN], b[MAXN];

piii minn( piii &a, piii &b )
{
    if( a.yy.xx*b.yy.yy > a.yy.yy*b.yy.xx ) return b;
    return a;
}

pii add( pii a, pii b )
{
    //cout << "add " << a.xx << "/" << a.yy << " " << b.xx << "/" << b.yy << endl;
    if( a.yy == b.yy )
        return mp( a.xx+b.xx, a.yy );
    if( b.yy == 1 )
    {
        return mp( a.xx + b.xx*a.yy, a.yy );
    }
}

void propagate( int cn, int s, int e )
{
    tree[cn].yy = add( tree[cn].yy, lazy[cn] );
    if( s != e )
    {
        lazy[cn*2] = add( lazy[cn*2], lazy[cn] );
        lazy[cn*2+1] = add( lazy[cn*2+1], lazy[cn] );
    }
    lazy[cn].xx = 0;
    lazy[cn].xx = 1;
    return ;

}

void build( int cn, int s, int e )
{
    lazy[cn].xx = 0; lazy[cn].yy = 1;
    if( s == e )
    {
        tree[cn] = mp( s, mp( a[s], b[s] ));
        return ;
    }
    int l = cn*2, m = (s+e)/2;
    build( l, s, m );
    build( l+1, m+1, e );
    tree[cn] = minn( tree[l], tree[l+1] );
}

void update( int cn, int s, int e, int x, int y, pii v )
{
    if( lazy[cn].xx )
    {
        //cout << "in " << cn << endl;
        propagate( cn, s, e );
    }
    if( s > y || e < x ) return ;
    if( s >= x && e <= y )
    {
        if( s == e )
        {
            tree[cn].yy = add( tree[cn].yy, v );
            return ;
        }
        //cout << s << " oo " << lazy[cn].yy << endl;
        lazy[cn] = add( v, lazy[cn] );
        //cout << lazy[cn].xx << " " << lazy[cn].yy << endl;
        propagate(cn, s ,e);
        //cout << "upd " << tree[cn].yy.xx << " " << tree[cn].yy.yy << endl;
        return ;
    }
    int l = cn*2, m = (s+e)/2;
    update( l, s, m, x, y, v );
    update( l+1, m+1,e, x, y, v  );
    tree[cn] = minn( tree[l], tree[l+1] );

}

piii query()
{
    if( lazy[1].xx ) propagate(1, 1, n);
    return tree[1];
}

piii query( int cn, int s, int e, int v )
{
    if( lazy[cn].xx )
        propagate( cn, s, e );
    if( s == e ) return tree[cn];
    int l = cn*2, m = (s+e)/2;
    if( v <= m )
        return query( l, s, m, v );
    else
        return query( l+1, m+1, e, v );
}

bool solve( intl x )
{
    build( 1, 1, n );
    int cnt = 0;
    for( int i = 1; i < Time; i++ )
    {
        piii q = query();
        //cout << q.xx << " " << q.yy.xx << " " << q.yy.yy << endl;
        if( q.yy.xx < 0 ) return 0;
        update( 1, 1, n, q.xx, q.xx, mp( x - b[q.xx], b[q.xx] ) );
        if( q.xx -1 >= 1 )
            update( 1, 1, n, 1, q.xx - 1, mp(-1LL, 1LL) );
        if( q.xx + 1 <= n )
            update( 1, 1, n, q.xx+1, n, mp(-1LL, 1LL) );
    }
    for( int i = 1; i <= n; i++ )
    {
        piii p = query( 1, 1, n, i );
        //cout << p.yy.xx << " " << p.yy.yy << endl;
        if( p.yy.xx < 0 ) return 0;

    }
    return 1;

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> Time;
    for( int i = 1; i <= n; i++ ) cin >> a[i];
    for( int i = 1; i <= n; i++ ) cin >> b[i];

    intl l = 0, h = 1.01e12, x = -1;
    //intl l = 0, h = 12, x = 0;
    while( l <= h )
    {
        intl m = (l+h)/2;
        //if( m < 10 ) cout << m << endl;
        //cout << "-- ----- - " << m << endl;
        if( solve(m) )
        {
            x = m;
            h = m - 1;
        }
        else
            l = m + 1;
    }

    cout << x << endl;

    return 0;
}

