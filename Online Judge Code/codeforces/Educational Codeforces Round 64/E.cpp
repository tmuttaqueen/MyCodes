#include<bits/stdc++.h>

using namespace std;

#define ld             long double
#define intl           long long
#define pii            pair<int,int>
#define xx             first
#define yy             second
#define mp             make_pair
#define pb             push_back
#define SZ(x)          (int)(x).size()
#define ALL(x)         begin(x), end(x)
#define REP(i, n)      for (int i = 0; i < n; ++i)
#define FOR(i, a, b)   for (int i = a; i <= b; ++i)
#define RFOR(i, a, b)  for (int i = a; i >= b; --i)

const int MAXN = 300005, inf = 1e9+5;
const intl INF = 1e18+5;
const ld eps = 1e-9;

int ara[MAXN], pos[MAXN], tree[MAXN*4];
int n;

void update(int cn, int l, int r, int pos, int val)
{
    if( pos < l || pos > r ) return;
    if(l == r)
    {
        tree[cn] = pos;
        return ;
    }
    int m = (l+r)/2;
    update( cn*2, l, m, pos, val );
    update( cn*2+1, m+1, r, pos, val );
    if( ara[ tree[cn*2] ] > ara[ tree[cn*2+1] ] )
    {
        tree[cn] = tree[cn*2];
    }
    else
        tree[cn] = tree[cn*2+1];

}

int query( int cn, int l, int r, int x, int y )
{
    if( y < l || x > r )
        return 0;
    if( l >= x && r <= y ) return tree[cn];
    int m = (l+r)/2, ll = cn*2;
    int a = query( ll, l, m, x, y );
    int b = query( ll+1, m+1, r, x, y );
    if( ara[a] > ara[b] ) return a;
    else return b;
}

intl tot;

intl solve( int l, int r )
{
    if( r - l <= 1 ) return 0;
    assert(l <= r);
    cout << "in " << l << " " << r << "\n";
    int ind = query( 1, 1, n, l, r );
    cout << "out " << "\n";

    assert( ind >= l && ind <= r );
    int ans = 0;
    if( r - ind < ind - l )
    {
        for( int j = ind + 1; j <= r; j++ )
        {
            tot++;
            assert( ara[ind] - ara[j] >= 0 );

            int d = pos[ ara[ind] - ara[j] ];
            if( d >= l && d <= ind )
            {
                ans++;
            }
        }
    }
    else
    {
        for( int j = l; j < ind; j++ )
        {
            tot++;
            assert( ara[ind] - ara[j] >= 0 );
            int d = pos[ ara[ind] - ara[j] ];
            if( d >= ind && d <= r )
            {
                ans++;
            }
        }
    }
    cout << "out" << endl;
    //cout << l << " " << r << " " << ind << " " << ans << endl;
    return ans + solve( l, ind - 1 ) + solve( ind+1, r );
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    n = 100000;
    for( int i = 1; i <= n; i++ )
    {
        //cin >> ara[i];
        ara[i] = n - i + 1;
        update( 1, 1, n, i, ara[i] );
        pos[ara[i]] = i;
    }

    intl ans = solve(1, n);
    cout << ans << " " << tot << endl;
    return 0;
}

