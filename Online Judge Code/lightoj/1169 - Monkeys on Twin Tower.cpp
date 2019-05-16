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

intl eat[1005][2], jump[1005][2], dp[1005][2];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        memset( dp, 0, sizeof dp );
        int n;
        scanf("%d", &n);
        for( int i = 0; i < n; i++ )
        {
            scanf("%d", &eat[i][0]);
        }
        for( int i = 0; i < n; i++ )
        {
            scanf("%d", &eat[i][1]);
        }
        for( int i = 0; i < n-1; i++ )
        {
            scanf("%d", &jump[i][1]);
        }
        for( int i = 0; i < n-1; i++ )
        {
            scanf("%d", &jump[i][0]);
        }
        dp[0][0] = eat[0][0];
        dp[0][1] = eat[0][1];
        for( int i = 1; i < n; i++ )
        {
            dp[i][0] = min( dp[i-1][0], dp[i-1][1] + jump[i-1][0] );
            dp[i][0] += eat[i][0];
            dp[i][1] = min( dp[i-1][1], dp[i-1][0] + jump[i-1][1] );
            dp[i][1] += eat[i][1];
        }
        printf("Case %d: %lld\n", caseno++, min( dp[n-1][0], dp[n-1][1] ) );
    }
    return 0;
}




