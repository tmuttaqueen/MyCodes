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



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int ara[105];
    for( int i = 0; i < n; i++ ) cin >> ara[i];
    FOR(i, 1, n-1)
    {
        if( (ara[i] == 2 && ara[i-1] == 3) || (ara[i] == 3 && ara[i-1] == 2) )
        {
            cout << "Infinite" << endl;
            return 0;
        }
    }
    int ans = 0;
    FOR(i, 1, n-1)
    {
        if( max( ara[i], ara[i-1] ) == 2 )
        {
            ans += 3;
        }
        else
        {
            ans += 4;
        }
    }
    for( int i = 2; i < n; i++ )
    {
        if( ara[i-2] == 3 && ara[i-1] == 1 && ara[i] == 2  )
            ans--;
    }
    cout << "Finite" << endl;
    cout << ans << endl;

    return 0;
}

