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

typedef tree < intl, null_type,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
intl mod = 1e8;
intl dp[105][105][3][105];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    for( int i = 1; i <= k1; i++ )
        dp[i][0][1][i] = 1;

    for( int i = 1; i <= k2; i++ )
        dp[0][i][2][i] = 1;
    for( int i = 0; i <= k2; i++ )
    {
        dp[0][i][1][0] = 1;

    }
    for( int i = 0; i <= k1; i++ )
    {
        dp[i][0][2][0] = 1;
    }
    for( int i = 1; i <= n2; i++ )
    {
        for( int j = 1; j <= n1; j++ )
        {
            for( int k = 1; k <= k1; k++ )
            {
                dp[j][i][1][k] = ( dp[j][i][1][k] + dp[j-1][i][1][k-1] )%mod;
                //printf("n1 %d n2 %d -1-L %d ans %lld\n", j,i,k, dp[j][i][1][k] );
            }
            for( int k = 1; k <= k2; k++ )
            {
                dp[j][i][2][k] = ( dp[j][i][2][k] + dp[j][i-1][2][k-1] )%mod;
                //printf("n1 %d n2 %d -2-L %d ans %lld\n", j,i,k, dp[j][i][2][k] );
            }
            for( int k = 1; k <= k2; k++ )
            {
                dp[j][i][1][0] = ( dp[j][i][1][0] + dp[j][i][2][k] )%mod;
            }
            for( int k = 1; k <= k1; k++ )
            {
                dp[j][i][2][0] = ( dp[j][i][2][0] + dp[j][i][1][k] )%mod;
            }
            //printf("n1 %d n2 %d -1-L %d ans %lld\n", j,i,0, dp[j][i][1][0] );
            //printf("n1 %d n2 %d -2-L %d ans %lld\n", j,i,0, dp[j][i][2][0] );
        }
    }
    intl ans = 0;
    for( int k = 0; k <= k1; k++ )
        ans = ( ans + dp[n1][n2][1][k] )%mod;
    //what_is(ans);
    //for( int k = 0; k <= k2; k++ )
    //ans = ( ans + dp[n1][n2][2][k] )%mod;
    cout << ans << endl;
    return 0;
}




