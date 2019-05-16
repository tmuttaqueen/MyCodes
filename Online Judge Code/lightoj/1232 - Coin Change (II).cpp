#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, caseno = 1;
    scanf("%d", &t);
    while( t-- )
    {
        int k, n;
        scanf("%d %d", &k, &n);
        int coin[k], val[k][n+1];
        for( int  i = 0; i < k; i++ )
            scanf("%d", &coin[i]);
        //for( int  i = 0; i < k; i++ )
            //printf("%d ",coin[k]);
        for( int  i = 0; i <= n; i++ )
            val[0][i] = 0;
        for( int i = 0; i <= n; i += coin[0] )
        {
            val[0][i] = 1;
        }
        for( int i = 1; i < k; i++ )
        {
            for( int  j = 0; j <= n; j++ )
            {
                int x = j - coin[i];
                if( j == 0 )
                {
                    val[i][j] = 1;
                }
                else if( x < 0 )
                {
                    val[i][j] = val[i-1][j];
                }
                else
                {
                    val[i][j] = (val[i-1][j] + val[i][x])%100000007;
                }
            }
        }
        printf("Case %d: %d\n", caseno++, val[k-1][n]);
    }
    return 0;
}
