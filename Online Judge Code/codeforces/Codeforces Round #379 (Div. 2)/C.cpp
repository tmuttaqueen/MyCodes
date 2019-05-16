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
#define pii         pair<intl, intl>
#define piii        pair<pii, int>
#define double      long double

intl b[200005], a[200005], d[200005], c[200005], mn[200005];
pii aa[200005];
int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n, m, k;
    cin >> n >> m >> k;
    intl x,  s;
    cin >> x >> s;
    intl ans = x*n;
    for( int i = 0; i < m; i++ )
    {
        cin >> a[i];
    }
    for( int i = 0; i < m; i++ ) cin >> b[i];
    for( int i = 0; i < k; i++ ) cin >> c[i];
    for( int i = 0; i < k; i++ ) cin >> d[i];
    for( int i = 0; i < m; i++ )
    {
        aa[i].xx = b[i];
        aa[i].yy = a[i];
    }
    sort( aa, aa + m );
    for( int i = 0; i < m; i++ )
    {
        b[i] = aa[i].xx;
        a[i] = aa[i].yy;
    }

    mn[0] = a[0];
    for( int i = 1; i < m; i++ )
        mn[i] = min( a[i], mn[i-1] );
    for( int  i=0; i < m; i++ )
    {
        if( b[i] <= s )
        {
            intl r = s - b[i];
            intl z = n;
            if( d[0] <= r )
            {
                intl *it = upper_bound( d, d+k, r );
                it--;
                intl ind = it - d;
                z = n - c[ind];
            }
            ans = min(ans, z*min(x,a[i]));
        }
    }

    for( int i = k-1; i >= 0; i-- )
    {
        intl f = x, z = n, r;
        if( s - d[i] >= 0 )
        {
            z -= c[i];
            if( z <= 0 ) ans = 0;
            r = s-d[i];
            if( b[0] <= r )
            {
                intl *it = upper_bound( b, b+m, r );
                it--;
                intl ind = it - b;
                f = min( x, mn[ind] );
            }
            ans = min(ans, f*z);
        }
    }
    cout << ans  << endl;
    return 0;
}



