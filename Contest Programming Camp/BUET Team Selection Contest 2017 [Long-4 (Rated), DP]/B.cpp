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
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl dp[111][111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;

    int n, k;
    cin >> n >> k;
    for( int i = 1; i < k; i++ ) dp[1][i] = 1;
    for( int i = 0; i < k; i++ ) dp[2][i] = k-1;
    for(  int i = 3; i <= n; i++ )
    {
        for( int j = 0; j < k; j++ )
        {
            intl ans = 0;
            for( int x = 0; x < k; x++ ) ans += dp[i-1][x];
            if(j==0) ans -= dp[i-1][0];
            dp[i][j] = ans;
        }
    }
    intl ans = 0;
    for( int i = 0; i < k; i++ ) ans += dp[n][i];
    cout << ans << endl;
    return 0;
}
