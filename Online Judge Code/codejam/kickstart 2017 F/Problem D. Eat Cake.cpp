#include<bits/stdc++.h>

using namespace std;
const int M = 10005;

int dp[M];

int main()
{
    //freopen("D-large.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset( dp, 125, sizeof dp );
    dp[0] = 0;
    for( int i = 1; i < M; i++ )
    {
        for( int j = 1; j*j <= i; j++ )
        {
            dp[i] = min( dp[i], dp[i-j*j] + 1 );
        }
    }
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << "Case #" << caseno++ << ": " << dp[n] << endl;
    }
}
