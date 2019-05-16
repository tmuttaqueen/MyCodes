#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

intl d[MAXN], c[MAXN];
intl rmq[MAXN][20];
int two[MAXN];

void initRMQ( intl d[], int l, int r )
{
    for( int i = l; i <= r; i++ )
    {
        rmq[i][0] = d[i];
    }
    for( int i = 1; i < 20; i++ )
    {
        for( int j = l; j <= r; j++ )
        {
            if( j+(1<<(i-1)) <= r )
                rmq[j][i] = max( rmq[j][i-1], rmq[ j+(1<<(i-1)) ][i-1] );
            else
                rmq[j][i] = rmq[j][i-1];
        }
    }
}

intl query( int l, int r )
{
    int p = two[r-l+1];
    return max( rmq[l][p], rmq[ r-(1<<p)+1 ][p] );
}

struct Data
{
    intl lft, rgt, all, sum;
    Data()
    {
        all = rgt = sum = lft = 0;
    }
    Data operator+( const Data &d ) const
    {
        Data t;
        t.lft = max( sum + d.lft, lft );
        t.rgt = max( d.sum + rgt, d.rgt );
        t.sum = sum + d.sum;
        t.all = max( max( d.all, all ), max(max( t.lft, t.rgt ), rgt+d.lft ));
        return t;
    }
};

Data tree[4*MAXN], dummy;

void build( int cn, int l, int r )
{
    if( l==r )
    {
        tree[cn].all = c[l];
        tree[cn].lft = c[l];
        tree[cn].rgt = c[l];
        tree[cn].sum = c[l];
        //cout << l << " " << c[l] << endl;
        return ;
    }
    int m = (l+r)/2;
    build(cn<<1, l, m);
    build((cn<<1)+1, m+1, r);
    tree[cn] = tree[cn<<1] + tree[ (cn<<1)+1 ];
}

Data query( int cn, int l, int r, int x, int y )
{
    if( r < x || l > y )
        return dummy;
    if( l >= x && r <= y )
        return tree[cn];
    int m = (l+r)>>1, f = (cn<<1);
    Data a = query(f, l, m, x, y);
    Data b = query( f+1, m+1, r, x, y );
    return a+b;
}



int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    two[0] = -1;
    two[1] = 0;

    for( int i = 1; i < MAXN ; i++ )
    {
        if( (i&(i-1)) == 0 )
            two[i] = two[i-1] + 1;
        else
            two[i] = two[i-1];
    }
    int n, a;
    cin >> n >> a;
    intl ans = 0;
    for( int i = 1; i <= n; i++ )
    {
        cin >> d[i] >> c[i];
        c[i] = a - c[i];
        ans = max( ans, c[i] );
    }
    for( int i = n; i > 1; i-- )
    {
        d[i] = (d[i] - d[i-1])*(d[i] - d[i-1]);
    }
    //cout << "ok" << endl;
    initRMQ( d, 1, n );
    //cout << query(1, 3) << query(2, 2) << query( 2, 5) << query( 3 , 4 ) << endl;
    //cout << "ok" << endl;
    build( 1, 1, n );
    //cout << query(1,1,n, 2, 5).all << " " << query(1, 1, n, 3, 5).all << " " << query(1, 1, n, 1, 4).all << " " << query(1, 1, n, 2, 3).all << endl;
    //cout << "ok" << endl;
    for( int i = 2; i <= n; i++ )
    {
        int r1 = i, l2 = i, l1 = 1, r2 = n, l = i, r = i;
        intl mx = d[i];
        while( l1 <= r1 )
        {
            int m = (l1+r1)/2;
            if( query(m, i) <= mx )
            {
                l = m;
                r1 = m-1;
            }
            else
            {
                l1 = m+1;
            }
        }
        while( l2 <= r2 )
        {
            int m = (l2+r2)/2;
            if( query(i, m) <= mx )
            {
                r = m;
                l2 = m+1;
            }
            else
                r2 = m-1;
        }
        if(l>1)
            l--;
        //cout << i << " " << l << " " << r << endl;
        Data d1 = query(1, 1, n, l, i-1);
        Data d2 = query(1, 1, n, i, r);
        ///cout << d1.lft << " " << d1.rgt << " " << d1.all << endl;
        //cout << d2.lft << " " << d2.rgt << " " << d2.all << endl;
        //cout << d.all <<  endl;
        //cout << i << " " << l << " " << r << " " << d[i] << " " << dd.all << endl;
        intl p = c[i-1] + c[i] - d[i];
        if( p < d1.rgt+d2.lft-d[i] )
            p = d1.rgt+d2.lft-d[i];
        ans = max(ans, p );
        //cout << endl;
    }
    cout << ans << endl;
    return 0;
}
