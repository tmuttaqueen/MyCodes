#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

int dp[20][20];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    dp[0][0] = 1;
    int n = 15;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= i; j++ )
        {
            dp[i][j] = 0;
            for( int k = 1; k <= i; k++ )
            {
                dp[i][j] += dp[i-k][j-1];
            }
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

