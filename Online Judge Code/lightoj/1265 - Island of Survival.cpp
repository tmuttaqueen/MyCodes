#include<bits/stdc++.h>

using namespace std;

long double dp[1001][1001]; //t, d

int main()
{
    for( int i = 0; i<= 1000; i++ ) dp[0][i] = 1;
    for( int i = 0; i <= 1000; i++ ) dp[1][i] = 0;
    for( int i = 2; i <= 1000; i++ )
    {
        if( i % 2 == 1 ) dp[i][0] = 0;
        else dp[i][0] = 1.0/(i+1);
        for( int j = 1; j <= 1000; j++ )
        {
            if( i%2 )
            {
                dp[i][j] = 0;
                continue;
            }
            long double x, t = i, d = j, y, tot = ( (t+d+1)*(t+d) - d*(d-1) )/2.0;
            x = 0.5*t*(t-1)/tot*dp[i-2][j] + (t+1)*d/tot*dp[i][j-1];
            tot = ( (t+d+1)*(t+d) - d*(d+1) )/2.0;
            y = 0.5*t*(t-1)/tot*dp[i-2][j] + t*d/tot*dp[i][j-1];
            dp[i][j] = max( x, y );
        }
    }
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int t, d;
        scanf("%d %d", &t, &d);
        printf("Case %d: %.10Lf\n", caseno++, dp[t][d]);
    }

    return 0;
}
