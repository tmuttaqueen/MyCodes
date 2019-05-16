#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int dp[10005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m;
    cin >> n >> m;
    double x;
    int ara[10005];
    for( int i = 0; i < n; i++ ) cin >> ara[i] >> x;
    dp[0] = 1;
    for( int i = 1; i < n; i++ )
    {
        dp[i] = 1;
        for( int j = 0; j < i; j++ )
        {
            if( ara[j] <= ara[i] )
                dp[i] = max( dp[i], 1 + dp[j] );
        }
        //cout << dp[i] << endl;
    }
    int mx = -1;
    for( int i = 0; i < n; i++ ) mx = max(mx, dp[i]);
    cout << n - mx << endl;
    //cin >> x;
    return 0;
}




