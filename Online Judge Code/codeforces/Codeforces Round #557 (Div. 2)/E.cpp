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
    int n, one = 0;
    cin >> n ;

    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
        if( ara[i] == 1 ) one++;
    }

    if( (one >= 1 && one <= n/2) || (n == 2 && ara[1] != ara[2] && one == 0 ) )
    {
        cout << "Alice" << endl;
    }
    else
    {
        cout << "Bob" << endl;
    }

    return 0;
}

