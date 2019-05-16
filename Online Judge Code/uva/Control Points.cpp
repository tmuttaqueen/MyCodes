#include<bits/stdc++.h>

using namespace std;

double ara[123456];
int dp[123456];

int main()
{
    int n;
    while( cin >> n )
    {
        for( int i = 1; i <= n; i++ )
            cin >> ara[i];
        dp[n+1] = 0;
        ara[n+1] = 10000000000000.0;
        for( int i = n; i >= 1; i-- )
        {
            double left = ara[i] + 1;
            int l = i, r = n, ans = -1;
            while( l <= r )
            {
                int m = (l+r)/2;
                if( left > ara[m] )
                {
                    l = m + 1;
                    ans = m;
                }
                else
                {
                    r = m - 1;
                }
            }
            dp[i] = min( dp[i+1] + 1, dp[ans+1] + 1 );
            //cout << ans << " " << dp[i] << endl;
        }
        cout << dp[1] << endl;
    }
}
