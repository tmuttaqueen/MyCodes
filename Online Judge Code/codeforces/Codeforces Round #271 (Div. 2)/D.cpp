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

intl mod = 1e9+7;
intl dp[100005];
intl sum[100006];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, k;
    dp[0] = 1;
    cin >> t >> k;
    for( int i = 1; i <= 100000; i++ )
    {
        if( i - k >= 0 )
            dp[i] = (dp[i-1] + dp[i-k])%mod;
        else
            dp[i] = dp[i-1];
    }
    sum[1] = dp[1];
    for( int i = 2; i <= 100000; i++ )
        sum[i] = ( sum[i-1] + dp[i] )%mod;
    for( int i = 0; i < t; i++ )
    {
        int a, b;
        cin >> a >> b;
        cout << ((sum[b] - sum[a-1])%mod+mod)%mod << endl;
    }
    return 0;
}




