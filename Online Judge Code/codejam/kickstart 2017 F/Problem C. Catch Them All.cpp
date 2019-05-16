#include<bits/stdc++.h>

using namespace std;

const int M = 102, inf = 1e9;

int dp[M][M];

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, caseno = 1, a, b, w;
    cin >> t;

    while(t--)
    {
        int n, m, p;
        cin >> n >> m >> p;
        for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= n; j++ )
            {
                dp[i][j] = inf;
            }
            dp[i][i] = 0;
        }
        for( int i = 1; i <= m; i++ )
        {
            cin >> a >> b >> w;
            dp[a][b] = w;
            dp[b][a] = w;
        }

        for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= n; j++ )
            {
                for( int k = 1; k <= n; k++ )
                {
                    dp[j][k] = min( dp[j][k], dp[j][i] + dp[i][k] );
                }
            }
        }

        long double vx = 0, vy = 0, N = n, ans = 0.0, X = 1;

        for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= n; j++ )
            {
                //cout << dp[i][j] << " ";

                if( i == 1 ) vy += dp[i][j];
                else vx += dp[i][j];
            }
            //cout << endl;
        }
        //cout << vx << " " << vy << endl;
        if( n == 2 )
        {
            cout << "Case #" << caseno++ << ": " << setprecision(10) << fixed << (double)p*w << endl;
        }
        else
        {
            int sign = 1;
            for( int i = 1; i <= 20 && p > 0; i++ )
            {
                ans = ans + (vx+vy)/( N*(N-1) ) + sign*( vy - vx/(N-1) )/( N*X );
                X *= (N-1);
                sign *= (-1);
                p--;
            }
            ans = ans + p*(vx+vy)/( N*(N-1) );
            cout << "Case #" << caseno++ << ": " << setprecision(10) << fixed << ans << endl;
        }

    }

    return 0;
}
