#include<bits/stdc++.h>

using namespace std;

#define ld             long double
#define intl           long long
#define pii            pair<int,int>
#define piii           pair<pii,int>
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

int x[1005], y[1005];

pii all[1005*1005];

map<pii, int > mm;

int gcd( int a, int b )
{
    if(b == 0) return a;
    return gcd(b,a%b);
}

set<piii>ss;

pii fix( pii a )
{
    int g = gcd( abs(a.xx), abs(a.yy) );
    if( a.yy < 0 ) g = -g;
    if( a.yy == 0 )
    {
        return mp( 1, 0 );
    }
    if( a.xx == 0 )
    {
        return mp(0,1);
    }
    return mp( a.xx/g, a.yy/g );
}

piii line( int i, int j )
{
    pii p = fix( mp(y[i] - y[j], x[i] - x[j]) );
    int a = p.xx, b = -p.yy, c  = y[i]*p.yy - x[i]*p.xx;
    int g = gcd( abs(a),abs(b) );
    g = gcd( abs(c), g );
    a /= g;
    b /= g;
    c /= g;
    return mp( mp(a,b), c );
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n = 1000;
    cin >> n;
    for( int i = 1; i <= n; i ++ )
    {
        cin >> x[i] >> y[i];
    }
    intl tot = 0;
    int d = 0;
    for( int i = 2; i <= n; i++ )
    {
        for( int j = 1; j < i; j++ )
        {
            pii p = fix( mp(y[i] - y[j], x[i] - x[j]) );
            piii l = line(i, j);
            if( ss.find(l) == ss.end())
            {
                tot++;
                mm[p]++;
                ss.insert(l);
            }

        }
    }

    //cout << tot << " " << d << endl;

    intl ans = tot*(tot-1)/2;

    for( auto vec: mm )
    {
        int d = vec.yy;
        if(d > 1)
        {
            ans -= (d*(d-1)/2);
        }
    }
    cout << ans << endl;


    return 0;
}

