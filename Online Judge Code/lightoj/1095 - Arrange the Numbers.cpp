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

const int mx = 1001;
const int mod = 1000000007;
intl ncr[mx][mx];
intl dp[mx][mx];


void prepro()
{
    for( int i = 0; i < mx; i++ )
    {
        for( int j = 0; j < mx; j++ )
        {
            if( j > i ) break;
            else if( j == i || j == 0 ) ncr[i][j] = 1;
            else ncr[i][j] = (ncr[i-1][j] + ncr[i-1][j-1])%mod;
        }
    }
    dp[0][0] = 1;
    for( int i = 1; i < mx; i++ ) dp[0][i] = (dp[0][i-1]*i)%mod;
    for( int i = 1; i < mx; i++ )
        for( int j = i; j < mx; j++ )
            dp[i][j] = ((dp[i-1][j] - dp[i-1][j-1])%mod + mod)%mod;
}

int main()
{
    ios::sync_with_stdio(false);
    filein;
    prepro();
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, m, k;
        intl ans;
        scanf("%d %d %d", &n, &m, &k);
        ans = ncr[m][k];
        ans = ans*dp[m-k][n-k];
        ans %= mod;
        printf("Case %d: %lld\n", caseno++, ans);
    }
    return 0;
}



