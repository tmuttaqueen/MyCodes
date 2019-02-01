#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const intl INF = -1;
const int MAXN = 105;
int gain[MAXN];
int Prev[MAXN];
int ager[MAXN];
string s;
intl dp[MAXN][MAXN][MAXN];

intl solve( int l, int r, int taken )
{

    if( l > r )
        return 0;
    if( l == r )
    {
        return gain[1+taken];
    }
    if( dp[l][r][taken] != INF )
    {
        return dp[l][r][taken];
    }
    //cout << l << " " << r << " " << taken << endl;
    int q = ager[r], p = max(Prev[r], l);
//    for( int i = 1; i <= taken; i++ )
//    {
//        dp[l][r][taken] = max( dp[l][r][taken], solve( l, r, taken-i ) + gain[i]);
//    }
    for( int i = p; i <= r; i++ )
    {
        dp[l][r][taken] = max( dp[l][r][taken], solve( l, i-1, 0 ) + gain[ r-i+1+taken ]);
    }
    for( int q = l; q < p; q++ )
    {
        if( s[q] == s[r] )
        {
            dp[l][r][taken] = max( dp[l][r][taken], solve( l, q, r-p+1+taken ) + solve( q+1,p-1, 0 ) );
        }
    }


    //dp[l][r][taken] = max( dp[l][r][taken], max(solve(l, q, r-p+1+taken) + solve(q+1, p-1, 0), solve(l, p-1, 0) + gain[r-p+1+taken] );
    //cout << l << " " << r << " " << taken << " --> " << dp[l][r][taken] << endl;
    return dp[l][r][taken];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    for( int i = 0; i <= 100; i++ )
    {
        for( int j = 0; j <= 100; j++ )
        {
            for( int k = 0; k <= 100; k++ )
            {
                dp[i][j][k] = INF;
            }
        }
    }
    int n;
    cin >> n;
    cin >> s;
    for( int i = 1; i <= n; i++ )
        cin >> gain[i];
    s = " "+ s;

    //cout << "ok" << endl;

    for( int i = n; i >= 1; i-- )
    {
        int t = i;
        for( int j = i; j >= 1; j-- )
        {
            if( s[j] == s[i] )
            {
                t = j;
            }
            else
                break;
        }
        Prev[i] = t;
        int tt = 0;
        for( int j = t-1; j >= 1; j-- )
        {
            if( s[j] == s[i] )
            {
                tt = j;
                break;
            }
        }
        ager[i] = tt;
        //cout << i  << " " << Prev[i] << " " << ager[i] << endl;
    }
    //cout << "ok" << endl;
    cout << solve( 1, n, 0 ) << endl;

    return 0;
}

