#include<bits/stdc++.h>

using namespace std;

#define intl long long
const int mx = 105, mod = 1e9+7;
int ara[mx];
intl dp[mx][mx];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) cin >> ara[i];
    intl ans = 0;
    for( int t = 1; t <= n; t++ )
    {
        for( int s = t; s > 0; s-- )
        {
            if( -ara[s] == ara[t] )
            {
                intl tot = 0;
                for( int k = s+1; k < t; k++ )
                {
                    tot += (dp[s+1][k]);
                    tot %= mod;
                }
                tot++;
                dp[s][t] = tot;
            }
            for( int k = s; k < t; k++ )
            {
                tot += ( dp[s][k] - dp[s+1][k] )*( dp[k+1][t] )
            }
            cout << s << " " << t << " " << dp[s][t] << " ";
            dp[s][t] += dp[s+1][t];
            cout << dp[s][t] << endl;
        }
        ans += dp[1][t];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
