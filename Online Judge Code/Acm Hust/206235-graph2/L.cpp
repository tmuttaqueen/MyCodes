#include<bits/stdc++.h>

using namespace std;

int dp[255][255];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    while(cin >> n)
    {
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                cin >> dp[i][j];
            }
        }
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                for( int k = 0; k < n; k++ )
                {
                    dp[j][k] = min( dp[j][k], dp[j][i] + dp[i][k] );
                }
            }
        }
        int m;
        cin >> m;
        while(m--)
        {
            //cout << m << endl;
            int a, b, c;
            cin >> a >> b >> c;
            cout << dp[a][b] + dp[b][c] << " " << dp[a][b] + dp[b][c] - dp[a][c] << endl;
        }
    }

    return 0;
}
