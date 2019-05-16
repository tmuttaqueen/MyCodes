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

char str[1005];
bool isp[1005][1005];
int dp[1005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d\n", &t);
    while(t--)
    {
        gets(str);
        int l = strlen(str);
        for( int i = l-1; i >= 0; i-- )
        {
            isp[i][i] = 1;
            if( i < (l-1) && str[i] == str[i+1] )
                isp[i][i+1] = 1;
            else
                isp[i][i+1] = 0;
            for( int j = i+2; j < l; j++ )
            {
                if( str[i] == str[j] && isp[i+1][j-1] == 1 )
                    isp[i][j] = 1;
                else
                    isp[i][j] = 0;
            }
        }

        dp[0] = 1;
        if( isp[0][1] ) dp[1] = 1;
        else dp[1] = 2;

        for( int i = 2; i < l; i++ )
        {
            int ans = dp[i-1] + 1;
            if( str[i] == str[i-1] )
                ans = min(ans, dp[i-2] + 1);

            for( int j = i-2; j >= 0; j-- )
            {
                if( str[i] == str[j] && isp[j+1][i-1] )
                    ans = min(ans, dp[j-1]+1 );
            }
            dp[i] = ans;
        }

        printf("Case %d: %d\n", caseno++, dp[l-1]);
    }

    return 0;
}



