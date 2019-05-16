#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

int mn[1005][1005];

intl mod = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    filein;
    int n;
    char str[1005];
    int val[1005];
    int ch[30];
    scanf("%d\n", &n);
    scanf("%s", str);

    for( int i = 0; i < 26; i++ ) scanf("%d", &ch[i]);
    for( int i = 0; i < n; i++ )
    {
        val[i] = ch[ str[i] -'a' ];
    }
    for( int i = 0; i < n; i++ )
    {
        for( int j = i; j < n; j++ )
        {
            if(i==j)
                mn[i][j] = val[i];
            else
                mn[i][j] = min( mn[i][j-1], val[j] );
        }
    }
    //0 = total
    //1 = longest
    //2 = minimum
    intl dp[1005][3];
    dp[0][0] = dp[0][1] = dp[0][2] = 1;
    for( int i = 1; i <= n; i++  )
    {
        int k = i-1;
        intl a = 0;
        for( int j = 1; i-j+1 >= 0 && j <= mn[i-j+1][i]; j++ )
        {
            if( i - j >= 0 )
                a += dp[i-j];
            else
                a++;
            a %= mod;

        }
    }

    return 0;
}




