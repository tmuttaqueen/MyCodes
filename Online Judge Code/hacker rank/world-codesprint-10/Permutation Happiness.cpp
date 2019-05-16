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

intl dp[3005][3005];
intl mod = 1e9+7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[2][1] = 2;
    intl n = 3000;
    for( intl i = 3; i <= n; i++ )
    {
        for( intl j = 1; j < i; j++ )
        {
            dp[i][j] = ((min( (i-j)*2, i)*dp[i-1][j-1])%mod + (max(0LL, i - (i-j-1)*2 )*dp[i-1][j])%mod)%mod;
            //cout << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    for( int i = 0; i <= n; i++ )
    {
        for( int j = i; j >= 0; j-- )
        {
            dp[i][j] = (dp[i][j]+dp[i][j+1])%mod;
        }
    }
    int q;
    cin >> q;
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        cout << dp[a][b] << endl;
    }
    return 0;
}




