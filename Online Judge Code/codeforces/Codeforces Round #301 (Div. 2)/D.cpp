//For a long time i thought i didn't have any feelings, then you came and numbed me

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

struct node
{
    double r, s, p;
};

node dp[105][105][105];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int r, s, p;
    cin >> r >> s >> p;
    for( int i = 0; i <= r; i++ )
    {
        for( int j = 0; j <= s; j++ )
        {
            dp[i][j][0].r = 1;
            dp[i][j][0].s = dp[i][j][0].p = 0;
        }
    }
    for( int i = 0; i <= s; i++ )
    {
        for( int j = 0; j <= p; j++ )
        {
            dp[0][i][j].s = 1;
            dp[0][i][j].r = dp[0][i][j].p = 0;
        }
    }
    for( int i = 0; i <= r; i++ )
    {
        for( int j = 0; j <= p; j++ )
        {
            dp[i][0][j].p = 1;
            dp[i][0][j].s = dp[i][0][j].r = 0;
        }
    }

    for( int i = 1; i <= r; i++ )
    {
        for( int j = 1; j <= s; j++ )
        {
            for( int k = 1; k <= p; k++ )
            {
                double d1 = (double)i*(double)j/(i*j+j*k+k*i), d2 = (double)k*(double)j/(i*j+j*k+k*i), d3 = (double)i*(double)k/(i*j+j*k+k*i);
                dp[i][j][k].r = d1*dp[i][j-1][k].r + d2*dp[i][j][k-1].r + d3*dp[i-1][j][k].r;
                dp[i][j][k].s = d1*dp[i][j-1][k].s + d2*dp[i][j][k-1].s + d3*dp[i-1][j][k].s;
                dp[i][j][k].p = d1*dp[i][j-1][k].p + d2*dp[i][j][k-1].p + d3*dp[i-1][j][k].p;
            }
        }
    }

    cout << setprecision(15) << fixed << dp[r][s][p].r << " " << dp[r][s][p].s << " " << dp[r][s][p].p << endl;

    return 0;
}




