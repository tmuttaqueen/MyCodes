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

int x[100], y[100];
int pre[30][30];
int dp[1<<17];
int n;
int c = 0;

int area( int x1, int y1, int x2, int y2, int x3, int y3 )
{
    return (x1-x2)*(y2-y3) - (x2-x3)*(y1-y2);
}

int solve( int mask = 0 )
{
    //debug;
    //what_is(mask);
    //c++;
    if( mask == ((1<<n) - 1)  )
        return 0;
    if( dp[mask] != -1 )
        return dp[mask];
    if( __builtin_popcount(mask) >= n-2 )
        return dp[mask] = 1;
    int ans = 1<<20;
    int ret;
    for( int i = 0; i < n; i++ )
    {
        if( (mask&(1<<i)) == 0 )
        {
            for( int j = i + 1; j < n; j++ )
            {
                if( (mask&(1<<j)) == 0 )
                {
                    ret = 1+solve( mask|pre[i][j] );
                    ans = min( ret, ans );
                }
            }
            break;
        }
            //continue;
    }
    return dp[mask] = ans;
}

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        memset( dp, -1, sizeof dp );
        scanf("%d", &n);
        for( int i = 0; i < n; i++ )
        {
            scanf("%d %d", &x[i], &y[i]);
        }
        for( int i = 0; i < n; i++ )
        {
            for( int j = i + 1; j < n; j++ )
            {
                int flag = 0;
                flag |= (1<<i);
                flag |= (1<<j);
                for( int k = 0; k < n; k++ )
                {
                    if( k != i && k != j && area( x[i], y[i], x[j], y[j], x[k], y[k] ) == 0 )
                    {
                        flag |= (1<<k);
                    }
                }
                pre[i][j] = flag;
                //cout << "i " << i << " j " << j << " " << flag << endl;
            }
        }
        int ans = solve();
        printf("Case %d: %d\n", caseno++, ans);
        //what_is(c);
    }

    return 0;
}



