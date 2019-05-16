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

int ara[MAXN], lr[MAXN], rl[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    lr[0] = inf, rl[n+1] = inf;

    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
        lr[i] = min( lr[i-1], ara[i] );
    }
    for( int i = n; i >= 1; i-- )
    {
        rl[i] = min( rl[i+1], ara[i] );
    }
    int ans = 1e9;
    for( int i = 1; i < n; i++ )
    {
        int mn = min( lr[n-i], rl[i+1] );
        //cout << i << " " << mn << endl;
        ans = min( ans, mn/i );
    }

    cout << ans << endl;


    return 0;
}
