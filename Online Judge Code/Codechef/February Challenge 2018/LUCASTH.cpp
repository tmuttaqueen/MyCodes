#include<bits/stdc++.h>

using namespace std;

#define intl long long

intl dp[20][20];


int main()
{
    dp[0][0] = 1;
    for( intl i = 1; i <= 10; i++ )
    {
        for( intl j = 0; j <= i; j++ )
        {
            if( j == 0 )
                dp[i][j] = 1;
            else if( j == i )
                dp[i][j] = dp[i-1][i-1]*i;
            else
                dp[i][j] = dp[i-1][j] + i*dp[i-1][j-1];
            cout << dp[i][j] << ' ';
        }
        cout <<  endl;
    }
    return 0;
}







