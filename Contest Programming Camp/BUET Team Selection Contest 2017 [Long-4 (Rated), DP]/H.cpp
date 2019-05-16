#include <cstdio>
#include<iostream>
#include<algorithm>

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

intl dp[555][555];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    for( int i = 0; i <= n; i++ ) dp[0][i] = 1;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            if( j > i )
            {
                dp[i][j] = dp[i][j-1];
                continue;
            }
            int l = min( i-j, j-1 );
            dp[i][j] = dp[i-j][l];
        }
        for( int j = 1; j <= n; j++ )
        {
            dp[i][j] += dp[i][j-1];
        }
    }
    cout << dp[n][n-1] << endl;
    return 0;
}
