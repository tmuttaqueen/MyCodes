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

intl a[100005], p[100005], invp[100005], b[100005], c[100005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n, l, r;
    cin >> n >> l >> r;
    for( int i = 0; i < n; i++ )
    {
        cin >> a[i];
    }
    for( int i = 0; i < n; i++ )
    {
        cin >> p[i];
        p[i]--;
        invp[ p[i] ] = i;
    }
    b[ invp[n-1] ] = r;
    c[ invp[n-1] ] = b[ invp[n-1] ] - a[ invp[n-1] ];
    intl mn = c[ invp[n-1] ];
    for( int i = n-2; i >= 0; i-- )
    {
        intl x = mn + a[ invp[i] ];
        x--;
        if( x < l )
        {
            cout << -1 << endl;
            return 0;
        }
        x = min( x, r );
        b[ invp[i] ] = x;
        c[ invp[i] ] = b[ invp[i] ] - a[ invp[i] ];
        mn = min( mn, c[invp[i]] );
    }
    for( int i = 0; i < n; i++ )
        cout << b[i] << " ";
    cout << endl;

    return 0;
}




