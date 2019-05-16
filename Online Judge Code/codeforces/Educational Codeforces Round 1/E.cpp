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

intl inf = 10000000000000000LL;
int n,m,k;
intl dp[35][35][60];

int main()
{
    ios::sync_with_stdio(false);
    filein;
    for( int i = 0; i <= 30; i++ )
        for( int j = 0; j <= 30; j++ )
            for( int k = 0; k <= 50; k++ )
                dp[i][j][k] = inf;

    for( int i = 0; i <= 30; i++ )
        for( int j = 0; j <= 30; j++ )
            dp[i][j][0] = 0;
    for( int i = 1; i <= 30; i++ )
    {
        for( k = 1; k < i; k++ )
            dp[i][1][k] = dp[1][i][k] = 1;
        dp[i][1][i] = dp[1][i][i] = 0;
    }

    for( int i = 2; i<= 3; i++ )
    {
        for( int j = 2; j <= 3; j++ )
        {
            for( int k = 1; k <= 9; k++ )
            {
                if( k == i*j )
                {
                    dp[i][j][k] = 0;
                    break;
                }
                intl ans = inf;
                for( int p = 1; p < i; p++ )
                {
                    ans = min(ans, j*j+min( dp[p][j][k], dp[i-p][j][k] ) );
                    if( p*j <= k )
                        ans = min( ans, j*j+ min( dp[i-p][j][k-p*j], dp[i-p][j][k] ) );
                }
                //cout << i << " " << j << " " << ' ' << k << " " << ans << endl;

                for( int p = 1; p < j; p++ )
                {
                    ans = min(ans, i*i+min( dp[i][p][k], dp[i][j-p][k] ) );
                    if( p*i <= k )
                        ans = min( ans, i*i+ min( dp[i][j-p][k-p*i], dp[i][j-p][k] ) );
                    //if( i == 2 && j == 3 && k == 3 )
                        //what_is(ans);
                }
                //cout << ans << " ";
                dp[i][j][k] = ans;
            }
            //cout << endl;
        }
    }
    int x;
    cin >> x;
    while(x--)
    {
        cin >> n >> m >>k;
        cout << dp[n][m][k] << "\n";
    }

    return 0;
}



