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

const intl mod = 100000007;

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        intl n, k, s;
        scanf("%lld %lld %lld", &n, &k, &s);
        intl dp[2][s+5];
        memset( dp, 0, sizeof(dp) );
        for( int i = 1; i <= k && i <= s; i++ )
            dp[1][i] = i;
        for( int i = 2; i <= n; i++ )
        {
            int p = (i-1)%2;
            int q = i%2;
            intl sum = 0, ds = 0;
            for( int j = 0; j <= s; j++ )
            {
                //ans[q][j] = sum;
                dp[q][j] = ds;
                sum = (sum+dp[p][j])%mod;
                if( j >= k )
                    sum = (sum - dp[p][j-k] + mod)%mod;
                ds = (ds+sum)%mod;
                if( j >= k )
                    ds = (ds - dp[p][j-k]*k+mod)%mod;
            }
        }
        /*for( int i = 1; i >= 0; i-- )
        {
            for( int j = 0; j <= s; j++ )
                cout << dp[i][j] << " ";
            cout << endl;
        }*/
        printf("Case %d: %lld\n", caseno++, (dp[n%2][s]%mod+mod)%mod );
    }

    return 0;
}




