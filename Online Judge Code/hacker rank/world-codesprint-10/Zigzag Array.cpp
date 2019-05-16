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

int ara[1005];
int dp[1005][2]; // 0- large, 1 = small;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, ans =0;
    int c = 0;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[c++];
    }
    for( int i = 1; i < n; i++ )
    {
        dp[i][0] = dp[i][1] = 1000;
        for( int j = i - 1; j >= 0; j-- )
        {
            if( ara[j] < ara[i] )
                dp[i][1] = min(dp[i][1], dp[j][0] + i - j - 1);
        }
        //cout << dp[i][1] << " ";
        for( int j = i - 1; j >= 0; j-- )
        {
            if( ara[j] > ara[i] )
                dp[i][0] = min(dp[i][0], dp[j][1] + i - j - 1);
        }
        //cout << dp[i][0] << "\n";
    }
    ans = 1000;
    for( int i = 0; i < n; i++ )
    {
        //cout << dp[i] << endl;
        ans= min( ans, min(  dp[i][0] + n - i - 1, dp[i][1] + n - i - 1 ));
    }
    cout << ans << endl;
    return 0;
}




