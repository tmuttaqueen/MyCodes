#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

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

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int SZ = 1000005, mod = 10007;

intl dp[2222][3333], sum[3333];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    intl n = 2000, k = 3000;
    for( int i = 1; i <= n; i++ )
    {
        dp[i][0] = 1;
        for( int j = 1; j <= k; j++ )
        {
            int mn = min(i-1,j);
            dp[i][j] = sum[j] - (j - mn-1 < 0? 0 : sum[j-mn-1]);
            dp[i][j] %= mod;
            //cout << i << " " <<j << " " << dp[i][j] << endl;
        }
        sum[0] = 1;
        for( int j = 1; j <= k; j++ )
        {
            sum[j] = ( sum[j-1] + dp[i][j] )%mod;
        }
    }
    while(t--)
    {
        intl n,k;
        cin >> n >> k;

        intl ans = 0, d = 1;
        for( int i =0; i < k; i++ )
        {
            ans = (ans+ dp[n][i] )%mod;
        }
        //what_is(ans);
        for( int i = 1; i <= n; i++ )
        {
            d = (d*i)%mod;
        }
        ans = ((d - ans)%mod+mod)%mod;
        cout << "Case " << caseno++ << ": " << ans << endl;
    }
    return 0;
}



