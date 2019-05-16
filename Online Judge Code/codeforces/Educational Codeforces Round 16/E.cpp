//only if you would take some time to know me !!! don't i love you ???
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

intl dp[10000005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n, x, y;
    cin >> n >> x >> y;
    dp[0] = 0;
    dp[1] = x;
    for( int i = 2; i <= n+2; i++ )
    {
        if(i&1) dp[i] = dp[i-1] + x;
        else dp[i] = min(dp[i/2] + y, dp[i-1] + x);
        dp[i-1] = min( dp[i-1], dp[i] + x );
    }
    //for( int i = 1; i <= n; i++ )
    cout << dp[n] << endl;
    return 0;
}




