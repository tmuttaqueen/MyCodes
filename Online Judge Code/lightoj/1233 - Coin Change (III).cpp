#include<bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    int t, caseno = 1;
    scanf("%d", &t);
    while( t-- )
    {
        int k, n, ans = 0;
        scanf("%d %d", &k, &n);
        int coin[k], val[2][n+1], num[k], flag[n+1];
        for( int  i = 0; i < k; i++ )
            scanf("%d", &coin[i]);
        for( int  i = 0; i < k; i++ )
            scanf("%d", &num[i]);

        int h = coin[0]*(num[0]+1);
        memset( val, 0, sizeof(val) );

        for( int i = 0; i <= n; i += coin[0] )
        {
            if( i >= h )
                break;
            val[0][i] = 1;
            if( k == 1 )
                ans++;
        }

        for( int  i = 1; i < k; i++ )
        {
            for(int j = 0; j <= n; j++ )
            {
                if( (j - coin[i]) < 0 )
                {
                    val[i%2][j] = val[(i-1)%2][j];
                    flag[j] = 0;
                }
                else if( flag[j-coin[i]] < num[i] )
                {
                    val[i%2][j] = val[(i-1)%2][j] + val[i%2][j-coin[i]];
                    if( val[(i-1)%2][j] > 0 )
                        flag[j] = 0; //flag[j- coin[i]];
                    else
                        flag[j] = flag[j- coin[i]] + 1;
                }
                else
                {
                    val[i%2][j] = val[(i-1)%2][j];
                    flag[j] = 0;
                }
                val[i%2][j] %= 100000007;
                if( i == (k-1) && val[i%2][j] > 0 )
                    ans++;

            }
        }
        ans--;
        printf("Case %d: %d\n", caseno++, val[(k-1)%2][n]);
    }
    return 0;
}
