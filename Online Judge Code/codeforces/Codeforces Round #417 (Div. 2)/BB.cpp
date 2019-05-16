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
const int SZ = 1000005, mod = 1000000007;

string s[20];
int dp[20][20];

int pre[20][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m;
    cin >> n >> m;
    for( int i = n; i > 0; i-- ) cin >> s[i];
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 0; j < m+2; j++ )
        {
            if( s[i][j] == '1' )
            {
                pre[i][0] = j;
                break;
            }

        }
        for( int j = m+1; j > 0 ; j-- )
        {
            if( s[i][j] == '1' )
            {
                pre[i][1] = j;
                break;
            }
        }
        //cout << pre[i][0] << " " << pre[i][1] << endl;
    }
    for( int i = n; i > 0; i-- )
    {
        if( pre[i][1] == 0 ) n--;
        else break;
    }
    //what_is(n);
    if( n != 1 )
    {
        dp[1][0] = pre[1][1]*2+1;
        dp[1][1] = m+2;
    }
    else
    {
        dp[1][0] = pre[1][1];
        dp[1][1] = pre[1][1];
    }

    //cout << dp[1][0] << " " << dp[1][1] << endl;
    for( int i = 2; i <= n; i++ )
    {
        if( i == n )
        {
            dp[i][0] = dp[i-1][0] + pre[i][1];
            dp[i][1] = dp[i-1][1] + (m + 1 - pre[i][0]);
            //cout << dp[i][0] << " " << dp[i][1] << endl;
            break;
        }
        dp[i][0] = min( dp[i-1][0] + pre[i][1]*2+1, dp[i-1][1] + m+2 );
        dp[i][1] = min( dp[i-1][0] + m+2, dp[i-1][1] + (pre[i][0] == 0? 0:(m + 1 - pre[i][0])*2) + 1 );
        //cout << dp[i][0] << ' ' << dp[i][1] << endl;
    }
    int ans = dp[n][0];
    for( int i  = 0; i < 2; i++ ) ans = min( ans, dp[n][i] );
    cout << ans << endl;

    return 0;
}




