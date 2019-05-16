#include <bits/stdc++.h>

using namespace std;

int dp[55][1005], pai[55], lim[55], used[55];

int n, k;

int call( int coin,int num, int val )
{
    if( coin < 0 )
        return 0;
    if( num < 0 )
        return 0;
    if( val <= 0 )
    {
        if( val == 0 )
            dp[coin][val] = 1;
        return 1;
    }
    if( dp[coin][val] != -1 )
        return dp[coin][val];
    int p1 = call( coin, num-1, val - pai[coin] );
    int p2 = call( coin - 1, lim[coin-1], val );
    dp[coin][val] = p1+p2;
    return dp[coin][val];
}

int main()
{
    freopen("input.txt", "r", stdin);
    int t, c = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf( "%d %d", &n, &k );
        memset( dp, -1, sizeof(dp) );
        memset( used, 0, sizeof(used) );
        for( int i = 0; i < n; i++ )
        {
            scanf("%d", &pai[i]);
        }
        for( int i = 0; i < n; i++ )
        {
            scanf("%d", &lim[i]);
        }

        printf("%d\n", call(n-1,lim[n-1], k));
    }
    return 0;
}
