#include<bits/stdc++.h>

using namespace std;

long double dp[101][101*101], eps = 1e-12, p, prob[101];
int val[101];


int main()
{
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        dp[0][0] = 0;
        int n, s = 0;
        //scanf("%f %d", &p, &n);
        cin >> p >> n;
        for( int i = 1; i <= n; i++ )
        {
            //scanf("%d %f", &val[i], &prob[i] );
            cin >> val[i] >> prob[i];
            s += val[i];
            dp[i][0] = 0;
            //cout << val[i] << ' ' << prob[i] << endl;
        }
        int ans = 0;
        for( int i = 1; i <= s; i++ ) dp[0][i] = 1;
        for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= s; j++ )
            {
                dp[i][j] = 1;
                dp[i][j] = min( dp[i-1][j] , 1 - ( 1 - dp[i-1][j-val[i] ] )*( 1 - prob[i] ) );
                //cout << i << " " << j << " " << dp[i][j] << endl;
                if( dp[i][j] < eps ) dp[i][j] = 0;
                if( j > ans && dp[i][j] <= p )
                {
                    ans = j;
                }
            }
        }
        printf("Case %d: %d\n", caseno++, ans);
    }
    return 0;
}
