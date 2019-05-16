#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

intl x[50005], y[50005], wx[50005], wy[50005];

int main()
{
    ios::sync_with_stdio(false);
    filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        memset( x, 0, sizeof x );
        memset( y, 0, sizeof y );
        memset( wx, 0, sizeof wx );
        memset( wy, 0, sizeof wy );
        int m, n, q, a, b, c;
        scanf("%d %d %d", &m, &n, &q);
        for( int i = 0; i < q; i++ )
        {
            scanf("%d %d %d", &a, &b, &c);
            x[a] = c*a;
            y[b] = c*b;
            wx[a] = c;
            wy[b] = c;
        }
        for( int i = 1; i <= 50000; i++ )
        {
            x[i] = x[i-1] + x[i];
            y[i] = y[i-1] + y[i];
            wx[i] = wx[i-1] + wx[i];
            wy[i] = wy[i-1] + wy[i];
        }
        /*for( int i = 1; i <= 5; i++ )
        {
            what_is(x[i]);
            what_is(y[i]);
            what_is(wx[i]);
            what_is(wy[i]);
            debug;
        }
        cout << "last\n\n";*/
        intl ansx = -1, ansy = -1, minx = 10000000000000000LL, miny = 10000000000000000LL;
        for( int i = 1; i <= 50000; i++  )
        {
            intl dist = i*wx[i-1] - x[i-1] + x[50000] - x[i] - i*(wx[50000] - wx[i]);
            if( dist < minx )
            {
                ansx = i;
                minx = dist;
            }
        }
        for( int i = 1; i <= 50000; i++  )
        {
            intl dist = i*wy[i-1] - y[i-1] + y[50000] - y[i] - i*(wy[50000] - wy[i]);
            if( dist < miny )
            {
                ansy = i;
                miny = dist;
            }
        }
        printf("Case %d: %lld %lld\n",caseno++, ansx, ansy );

    }

    return 0;
}



