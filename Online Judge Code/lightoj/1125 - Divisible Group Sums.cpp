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

typedef tree < intl, null_type,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl dp[205][30][30]; //n,m,d
int ara[205];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n,q;
        memset( dp, 0, sizeof dp );
        dp[0][0][0] = 1;
        scanf("%d %d", &n, &q);
        for( int i = 1; i <= n; i++ )
            scanf("%d", &ara[i] );
        printf("Case %d:\n", caseno++);

        while(q--)
        {
            memset( dp, 0, sizeof dp );
            for( int i = 0; i <= n; i++ ) dp[i][0][0] = 1;
            //for(  )
            //dp[0][0][0] = 1;
            int m,d;
            scanf("%d %d", &d, &m );
            for( int i = 1; i <= n; i++ )
            {
                for( int j = 1; j <= m; j++ )
                {
                    for( int k = 0; k < d; k++ )
                    {
                        dp[i][j][k] += dp[i-1][j][k];
                        int rem = (( k - ara[i] )%d+d)%d;
                        dp[i][j][k] += dp[i-1][j-1][rem];
                    }
                }
            }
            /*for( int j = 0; j < m; j++ )
            {
                for( int k = 0; k < d; k++ )
                {
                    cout << dp[n][j][k] << " ";
                }
                cout << endl;
            }*/

            printf("%lld\n", dp[n][m][0] );
        }


    }
    return 0;
}




