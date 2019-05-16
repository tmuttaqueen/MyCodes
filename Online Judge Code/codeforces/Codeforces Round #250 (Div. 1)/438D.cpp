#include<bits/stdc++.h>

using namespace std;

#define int long long

struct node
{
    int mx, sum;
};

node tree[423456];

void update1( int cn, int l, int r, int ll, int rr, int mod )
{
    if( r < ll || l > rr || tree[cn].mx < mod ) return;
    if( l == r )
    {
        tree[cn].sum %= mod;
        tree[cn].mx = tree[cn].sum;
        return ;
    }
    int m = (l+r)/2, n = cn*2;
    update1( n, l, m, ll, rr, mod );
    update1( n+1, m+1, r, ll, rr, mod );
    tree[cn].mx = max( tree[n].mx, tree[n+1].mx );
    tree[cn].sum = tree[n].sum + tree[n+1].sum;
    return;
}

void update2( int cn, int l, int r, int ll, int rr, int val )
{
    if( r < ll || l > rr ) return;
    if( l == r )
    {
        tree[cn].sum = val;
        tree[cn].mx = tree[cn].sum;
        return ;
    }
    int m = (l+r)/2, n = cn*2;
    if( m >= ll )
        update2( n, l, m, ll, rr, val );
    else
        update2( n+1, m+1, r, ll, rr, val );
    tree[cn].mx = max( tree[n].mx, tree[n+1].mx );
    tree[cn].sum = tree[n].sum + tree[n+1].sum;
    return;
}

int query( int cn, int l, int r, int ll, int rr )
{
    if( r < ll || l > rr ) return 0;
    if( l >= ll && r <= rr )
    {
        return tree[cn].sum;
    }
    int m = (l+r)/2, n = cn*2;
    int a = query( n, l, m, ll, rr );
    int b = query( n+1, m+1, r, ll, rr );
    return a+b;
}

main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, q, a;
    cin >> n >> q;
    for( int i = 1; i <= n; i++ )
    {
        cin >> a;
        update2( 1, 1, n, i, i, a );
    }
    while(q--)
    {
        int t, a, b, x;
        cin >> t;
        if( t == 1 )
        {
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << "\n";
        }
        else if( t == 2 )
        {
            cin >> a >> b >> x;
            update1( 1, 1, n, a, b, x );
        }
        else
        {
            cin >> a >> b;
            update2( 1, 1, n, a, a, b );
        }
    }
    return 0;
}

