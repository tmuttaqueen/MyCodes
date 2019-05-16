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

intl ara[1000005];
pii seg[1000005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n, l, r, c = 0;
    cin >> n >> l >> r;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
    }
    sort( ara, ara + n );
    //debug;
    for( int i = 1; i < n; i++ )
    {
        intl a = abs(ara[i] - ara[i-1]) + 1;
        intl b = ara[i] + ara[i-1] - 1;
        if( a <= r && b >= l )
        {
            seg[c].xx = max( a, l );
            seg[c].yy = min( b, r );
            //cout << seg[c].xx << " " << seg[c].yy << endl;
            c++;
        }
    }
    if( c == 0 )
    {
        cout << 0 << endl;
        return 0;
    }
    sort( seg, seg+c );
    intl ans = 0;
    intl low = seg[0].xx, high = seg[0].yy;
    for( int i = 0; i < c; i++ )
    {
        while(i < c && seg[i].xx <= high )
        {
            high = max( high, seg[i].yy );
            i++;
        }
        ans += (high - low + 1);
        if( i >= c )
            break;
        low = seg[i].xx;
        high = seg[i].yy;
        i--;
    }
    cout << ans << endl;
    return 0;
}




