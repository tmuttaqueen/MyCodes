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
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

intl dp[102][102];
intl ara[102];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, m;
        memset( dp, 60, sizeof dp );
        cin >> n >> m;
        for( int i = 1; i <= n; i++ )
            cin >> ara[i];
        sort( ara+1, ara+n+1 );
        dp[0][0] = 0;
        for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= i && j <= m; j++ )
            {
                dp[i][j] = 1e12;
                for( int k = i; k >= j; k-- )
                {
                    dp[i][j] = min( dp[i][j], dp[k-1][j-1] + ara[i] - ara[k] );
                }
            }
        }
        cout << "Case #" << caseno++ << ": " << dp[n][m] << endl;

    }
    return 0;
}
