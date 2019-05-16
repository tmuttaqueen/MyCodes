#include <cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>

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

int dp[111][111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        memset( dp, 0, sizeof dp );
        int h,w;
        cin >> h >> w;
        for( int i = 1; i <= h; i++ )
        {
            for( int j = 1; j <= w; j++ )
            {
                cin >> dp[i][j];
            }
            if( i > 1 )
            {
                for( int j  =1; j <= w; j++ )
                {
                    dp[i][j] = dp[i][j] + max( dp[i-1][j-1], max( dp[i-1][j], dp[i-1][j+1] ) );
                }
            }
        }
        int ans = 0;
        for( int i = 1; i <= w; i++ )
        {
            ans = max( ans, dp[h][i] );
        }
        cout << ans << endl;
    }

    return 0;
}
