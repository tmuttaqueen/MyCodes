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

int val[MAXN];

int ans[MAXN];

pii all[MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int n, m;
    cin >> n >> m;
    for( int i = 0; i < m; i++ )
    {
        int x, y;
        cin >> x >> y;
        int d = ((x-y)%n + n)%n;
        if( d > n/2 ) d = n - d;
        int e = y - x;
        if( e < 0 ) e = n - x + y;
        if( e != d ) swap(x, y);
        all[i] = mp(x-1,y-1);
        val[d]++;
    }
    if(n == 2)
    {
        cout << "Yes" << endl;
        return 0;
    }
    int tot = 0;
    for( int i = 1; i < n; i++ )
    {
        if( val[i] > 0 && val[i] < n )
        {
            tot++;
            int g = n/__gcd(n, val[i]);
            for( int v = g; v < n; v += g )
            {
                ans[v]++;
            }
        }
    }

    for( int i = 1; i < n; i++ )
    {
        if( ans[i] == tot )
        {
            //cout << i << endl;
            int f = 1;
            set<pii>ss;
            for( int j = 0; j < m; j++ )
            {
                ss.insert( all[j] );
            }
            for( int j  = 0; j < m; j++ )
            {
                int x = (all[j].xx + i)%n, y = (all[j].yy + i)%n;
                if( ss.find( mp(x,y) ) != ss.end() )
                {
                    ss.erase( mp(x,y) );
                }
                else if( n%2 == 0 && ((x-y)%n+n)%n == n/2 && ss.find( mp(y,x) ) != ss.end() )
                {
                    ss.erase( mp(y,x) );
                }
                else
                {
                    f = 0;
                    break;
                }
            }
            if( f )
            {
                //cout << i << endl;
                cout << "Yes" << endl;
                return 0;
            }

        }
    }

    cout << "No" << endl;


    return 0;
}
