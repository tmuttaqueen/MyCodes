#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, a;
    scanf("%d", &t);
    while(t--)
    {
        intl dp[50][50], k, ara[50], n;
        scanf("%lld %lld", &n, &k);
        memset( dp, 0, sizeof(dp) );
        memset( ara, 0, sizeof(ara) );
        for( int i = 0; i < k; i++ )
        {
            scanf("%d", &a);
            ara[a] = 1;
        }

        dp[1][1] = 1;
        for( int i = 2; i <= (2*n); i++ )
        {
            if( ara[i] == 0 )
                dp[i][0] = dp[i-1][1];
            else
                dp[i][0] = 0;
            for( int j = 1; j <= i; j++ )
            {
                if( ara[i] == 0 )
                    dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
                else
                    dp[i][j] = dp[i-1][j-1];
            }
        }
        printf("%lld\n", dp[2*n][0]);
    }

    return 0;
}



