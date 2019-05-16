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
int n, m;
    cin >> n >> m;
    if(m==n)
    {
        cout << 0 << endl;
        return 0;
    }
    for( int i = 0; i < n; i++ ) ara[i] = 1;
    for( int i = 0; i < n; i += 2 )
    {
        if(m == 0) break;
        m--;
        ara[i] = 0;
    }
    for( int i = n - (n%2==0?1:2); i >= 1; i-=2 )
    {
        if(m == 0) break;
        m--;
        ara[i] = 0;
    }

    int cnt = 0;

    for( int i = 0; i < n; i++ )
    {
        if( ara[i] == 1 && ( i == 0 || ara[i-1] == 0) )
        {
            cnt++;
        }
    }


    if( ara[n-1] == 1 && ara[0] == 1 ) cnt--;
    cnt = max(cnt, 1);

    cout << cnt << endl;


    return 0;
}
