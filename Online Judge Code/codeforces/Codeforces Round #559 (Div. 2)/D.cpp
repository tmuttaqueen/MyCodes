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
    string s;
    cin >> n >> s;
    int lo = 1e9, cur = 0;
    for( int i = 0; i < s.length(); i++ )
    {
        if( s[i] == '-' )
        {
            cur--;
        }
        else
        {
            cur++;
        }
        lo = min( cur, lo );
    }

    if( lo > 0 ) lo = 0;
    lo = -lo;
    cout << lo + cur << endl;

    return 0;
}
