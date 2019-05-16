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

int ara[MAXN];

vector<int> v1, v2;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, z;
    cin >> n >> z;
    for( int i = 0; i < n; i++ ) cin >> ara[i];
    sort( ara, ara+n );
    for( int i = 0; i < n/2; i++ )
    {
        v1.push_back( ara[i] );
    }
    for( int i = n/2; i < n; i++ )
    {
        v2.push_back(ara[i]);
    }
    int ans = 0, cur = 0;
    for( int i = 0; i < v1.size(); i++ )
    {
        while( cur < v2.size() && v2[cur] - v1[i] < z )
        {
            cur++;
        }
        if( cur < v2.size() )
        {
            ans++;
            cur++;
        }
        else
            break;
    }

    cout << ans << endl;

    return 0;
}
