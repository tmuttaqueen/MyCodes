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

intl ara[1000];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n, k, ans = 0;
    cin >> n >> k;
    for( int i = 0; i < n; i++ ) cin >> ara[i];
    for( int i = 1; i < n; i++ )
    {
        if( ara[i-1] + ara[i] < k )
        {
            ans += ( k - ara[i-1] - ara[i] );
            ara[i] += ( k - ara[i-1] - ara[i] );
        }
    }
    cout << ans << endl;
    cout << ara[0];
    for( int i = 1; i < n; i++ )
    {
        cout << " " << ara[i];
    }
    cout << endl;
    return 0;
}



