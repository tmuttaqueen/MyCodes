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

char str[100];
intl dp[65][65];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d\n", &t);
    while(t--)
    {
        gets(str);
        intl len = strlen(str), tt = 0;
        //memset( dp, 0, sizeof(dp) );
        for( int i = len - 1; i >= 0; i-- )
        {
            dp[i][i] = 1;
            for( int j = i+1; j < len; j++ )
            {
                intl total = dp[i][j-1]+1;
                for( int k = i; k < j; k++ )
                {
                    if( str[k] == str[j] )
                    {
                        total++;
                        if( (k+1) <= (j-1) )
                        {
                            total += dp[k+1][j-1];
                        }
                    }
                }
                dp[i][j] = total;
            }
        }
        printf("Case %d: %lld\n", caseno++, dp[0][len-1]);
    }

    return 0;
}



