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

int dam[20], ara[20][20], dp[1<<17];
int n;

int solve( int mask = 0 )
{
    //what_is(mask);
    if( mask == ((1<<n)-1) )
        return 0;
    if( dp[mask] != -1 )
        return dp[mask];
    int ans = 1<<25;
    for( int i = 0; i < n; i++ )
    {
        if( (mask&(1<<i)) == 0 )
        {
            int power = 1;
            for( int j = 0; j < n; j++ )
            {
                if( (mask&(1<<j)) )
                    power = max( power, ara[j][i] );
            }
            int ret = ceil((double)dam[i]/power) + solve( mask|(1<<i) );
            ans = min( ans, ret );
        }
    }
    return dp[mask] = ans;
}

int main()
{
    ios::sync_with_stdio(false);
    filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        //int n;
        memset( dp, -1, sizeof dp );
        char str[15];
        scanf("%d", &n);
        for( int i = 0; i < n; i++ )
        {
            scanf("%d", &dam[i]);
        }
        getchar();
        for( int i = 0; i < n; i++ )
        {
            scanf("%s", str);
            for( int j = 0; j < n; j++ )
            {
                ara[i][j] = str[j] - '0';
                //cout << ara[i][j] << " ";
            }
            //cout << endl;
        }
        //what_is(n);
        int ans = solve();
        printf("Case %d: %d\n", caseno++, ans );
    }

    return 0;
}




