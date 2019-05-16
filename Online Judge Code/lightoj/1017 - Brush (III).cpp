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

int dp[105][105];
int ara[105];
int pre[105];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, w, k;
        scanf("%d %d %d", &n, &w, &k);
        //what_is(n);
        //what_is(w);
        int a, b;
        for( int i = 1; i <= n; i++ )
        {
            scanf("%d %d", &a, &b);
            ara[i] = b;
        }
        sort( ara+1, ara+n+1 );
        for( int i = 1; i <= n; i++ )
        {
            int temp = ara[i] - w, j;
            for(j = i; j >= 1; j-- )
            {
                if( ara[j] < temp )
                    break;
            }
            pre[i] = j;
        }
        for( int i = 1; i <= n; i++ )
        {
            dp[i][0] = 0;
            for( int j = 1; j <= k; j++ )
            {
                dp[i][j] = max( dp[i-1][j], min(dp[ pre[i] ][j-1] + i - pre[i], i) );
            }
        }
        printf("Case %d: %d\n", caseno++, dp[n][k]);
    }


    return 0;
}



