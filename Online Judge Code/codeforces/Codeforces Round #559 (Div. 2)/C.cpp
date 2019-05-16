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

int mn[MAXN], mx[MAXN], sec[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int beshi = 0;
    intl ans = 0;
    for( int i = 0; i < n; i++ )
    {
        cin >> mn[i];
        ans += 1LL*m*mn[i];
        beshi = max( beshi, mn[i] );
    }
    int kom = inf;
    for( int i = 0; i < m; i++ )
    {
        cin >> mx[i];
        kom = min( kom, mx[i] );
    }
    if( kom < beshi )
    {
        cout << -1 << endl;
        return 0;
    }

    sort( mn, mn+n );
    reverse( mn, mn + n );
    sort( mx, mx+m );
    reverse(mx, mx+m);
    int cur = 0;
    int v = mn[0];
    for( int j = 0; j < m-1; j++ )
    {
        sec[cur++] = v;
    }

    if( mx[m-1] == v )
    {
        sec[cur++] = v;
    }
    else
    {
        sec[cur++] = mn[1];
    }

    for( int i = 0; i < m; i++ )
    {
        ans += mx[i] - sec[i];
    }

        cout << ans << endl;




    return 0;
}
