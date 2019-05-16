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

int dp[105][105];
int ara[105];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, tt = 0;
        scanf("%d", &n);
        for( int i = 1; i <= n; i++ )
        {
            scanf("%d", &ara[i]);
            tt += ara[i];
        }
        for( int i = n; i >= 1; i-- )
        {
            dp[i][i] = ara[i];
            int sum = ara[i];
            for( int j = i+1; j <= n; j++ )
            {
                sum += ara[j];
                //what_is(sum);
                int ans = -10000000, temp = 0;
                for( int k = i; k <= j; k++ )
                {
                    temp += ara[k];
                    ans = max( ans, sum - dp[k+1][j] );
                }
                temp = 0;
                for( int k = j; k >= i; k-- )
                {
                    temp += ara[k];
                    ans = max( ans, sum - dp[i][k-1] );
                }
                dp[i][j] = ans;
            }
        }

        int ans = dp[1][n] - (tt - dp[1][n]);
        printf("Case %d: %d\n", caseno++, ans);
    }

    return 0;
}



