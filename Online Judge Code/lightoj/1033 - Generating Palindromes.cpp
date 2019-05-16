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

char str1[105], str2[105];
int dp[105][105];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d\n", &t);
    while(t--)
    {
        gets(str1);
        int l = strlen(str1);
        for( int i = l-1; i >= 0; i-- )
        {
            str2[l-i-1] = str1[i];
        }
        str2[l] = '\0';
        //what_is(str1);
        //what_is(str2);
        for( int i = 0; i <= l; i++ )
            dp[i][0] = dp[0][i] = 0;
        for( int i = 1; i <= l; i++ )
        {
            for( int j = 1; j <= l; j++ )
            {
                if( str1[i-1] == str2[j-1] )
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max( dp[i-1][j], dp[i][j-1] );
            }
        }

        printf("Case %d: %d\n", caseno++, l - dp[l][l] );

    }

    return 0;
}



