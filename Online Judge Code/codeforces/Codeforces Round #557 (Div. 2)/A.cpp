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


int ara[100];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, h, m;
    cin >> n >> h >> m;
    for( int i = 1; i <= n; i++ ) ara[i] = h;
    for( int i = 0; i < m; i++ )
    {
        int l, r, x;
        cin >> l >> r >> x;
        for( int j = l; j <= r; j++ )
        {
            ara[j] = min( ara[j], x );
        }
    }
    int ans = 0;
    for( int i = 1; i <= n; i++ ) ans += ara[i]*ara[i];

    cout << ans << endl;

    return 0;
}

