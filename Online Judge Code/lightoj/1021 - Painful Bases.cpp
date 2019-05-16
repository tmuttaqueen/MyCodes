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

char str[] = "0123456789ABCDEF";
intl ara[130], dp[1<<17][20];
char w[20];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    for( int i = 0; i < 16; i++ ) ara[(int)str[i]] = i;
    int t, caseno = 1;
    scanf("%d", &t);
    while( t-- )
    {
        intl b, h, len = 0, a = 1, c = 1, num;
        scanf("%lld %lld\n", &b, &num);
        gets(w);
        len = strlen(w);
        h = 1<<len;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        int ss = 0;
        for( int i = 1; i < h; i++ )
        {
            a = i;
            for( int j = 0; j < len ; j++ )
            {
                int x = 1<<j;
                if( x&a )
                {
                    intl temp = a - x, val = ara[ w[j] ];
                    for( int k = 0; k < num; k++ )
                    {
                        dp[a][ (k*b+val)%num ] += dp[temp][k];
                    }
                }
            }
        }

        printf("Case %d: %lld\n", caseno++, dp[h-1][0] );
    }

    return 0;
}



