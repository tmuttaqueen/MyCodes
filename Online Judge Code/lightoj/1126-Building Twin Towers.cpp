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

int ara[104];
int dp[2][500005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, sum = 0;
        scanf("%d", &n);
        for( int i = 1; i <= n; i++ )
        {
            scanf("%d", &ara[i]);
            sum += ara[i];
        }
        int now = 0, prev = 1, flag = 0;
        memset( dp, -1, sizeof dp );
        dp[0][0] = 0;
        dp[1][0] = 0;
        dp[1][ ara[1] ] = ara[1];
        //debug;
        for( int i = 2; i <= n; i++ )
        {
            for( int j = 0; j <= sum; j++ )
            {
                if( dp[prev][j] != -1 )
                {
                    dp[now][j] = max( dp[now][j], dp[prev][j] );
                    int d1 = abs( j - ara[i] ), d2 = abs(j+ara[i]);
                    //what_is(d1);
                    //what_is(d2);
                    if( d1 == 0 || d2 == 0 ) flag = 1;
                    dp[now][d1] = max( dp[now][d1], max( dp[prev][d1], dp[prev][j] + ara[i] ) );
                    dp[now][d2] = max( dp[now][d2], max( dp[prev][d2], dp[prev][j] + ara[i] ) );
                    //cout << endl;
                }
            }
            swap(now,prev);
        }

        if( !flag )
            printf("Case %d: impossible\n", caseno++);
        else
            printf("Case %d: %d\n", caseno++, max(dp[now][0], dp[prev][0])/2 );



    }
    return 0;
}




