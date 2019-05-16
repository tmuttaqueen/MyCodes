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


int dp[(1<<16)+5];
int n;
int ara[17][17];

int sett( int nn, int p )
{
    return nn = nn|(1<<p);
}
int resett( int nn, int p )
{
    return nn = nn&(~(1<<p));
}
bool check( int nn, int p )
{
    return bool(nn&(1<<p));
}

int fun( int mask, int r )
{
    if( mask == (1<<n) - 1 )
        return 0;
    if( dp[mask] != -1 )
        return dp[mask];
    int ret = 0;
    for( int i = 0; i < n; i++ )
    {
        int ans = 0;
        if( check(mask, i) == 0 )
        {
            //what_is(i);
            ans = ara[r][i] + fun( sett(mask, i), r+1 );
        }
        ret = max(ret, ans);
    }
    return dp[mask] = ret;
}

int main()
{
    ios::sync_with_stdio(false);
    filein;
    int t, caseno = 1;
    cin >> t;
    while( t-- )
    {
        cin >> n;
        memset( dp, -1, sizeof(dp) );
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                cin >> ara[i][j] ;
                //what_is(ara[i][j]);
            }
        }
        cout << "Case " << caseno++ << ": " << fun(0,0) << '\n';

    }

    return 0;
}



