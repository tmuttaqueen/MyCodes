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

vector<int> divi[2005];
intl mod = 1e9+7;
intl dp[2005][2005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, k;
    cin >> n >> k;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= i; j++ )
        {
            if( i%j == 0 )
                divi[i].pb(j);
        }
    }
    for( int i = 1; i <= n; i++) dp[i][1] = 1;
    for( int i = 2; i <= k; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            intl ans = 0;
            for( int p = 0; p < divi[j].size(); p++ )
            {
                ans = (ans+ dp[j/divi[j][p]][i-1] )%mod;
            }
            dp[j][i] = ans;
        }
    }
    intl ans = 0;
    for( int i = 1; i <= n; i++ ) ans = (ans+ dp[i][k] )%mod;
    cout << ans << endl;
    return 0;
}




