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

int dp[1005][1005][11];
int pre[1005][1005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n,m, k;
    cin >> n >> m >> k;
    string s, t;
    cin.ignore();
    cin >> s >> t;
    //what_is(s);
    //what_is(t);
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            if( s[i-1] == t[j-1] )
            {
                pre[i][j] = 1+pre[i-1][j-1];
                dp[i][j][1] = max( pre[i][j], max(dp[i][j-1][1], dp[i-1][j][1]) );
            }
            else
            {
                pre[i][j] = 0;
                dp[i][j][1] = max(dp[i][j-1][1], dp[i-1][j][1]);
            }
            //cout << pre[i][j] << " ";
        }
        //cout << endl;
    }
    /*debug;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            cout << dp[i][j][1] << " ";
        }
        cout << endl;
    }*/
    for( int l = 2; l <= k; l++ )
    {
        for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= m; j++ )
            {
                int x = pre[i][j];
                if( x != 0 )
                    dp[i][j][l] = max(x+dp[i-x][j-x][l-1] ,max(dp[i][j-1][l], dp[i-1][j][l]));
                else
                    dp[i][j][l] = max(dp[i][j-1][l], dp[i-1][j][l]);
            }
        }
    }
    cout << dp[n][m][k] << endl;
    return 0;
}



