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


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, m;
    cin >> n >> m;
    int ara[n][m];
    int dp[n][m];
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < m; j++ )
        {
            cin >> ara[i][j];
        }
    }
    for( int j = 0; j < m; j++ )
    {
        dp[n-1][j] = 1;
        for( int i = n-2; i>= 0; i-- )
        {
            if( ara[i][j] <= ara[i+1][j] )
            {
                dp[i][j] = dp[i+1][j] + 1;
            }
            else
                dp[i][j] = 1;
        }
    }
    int mx[n];
    for( int i = 0; i < n; i++ )
    {
        int mm = -1;
        for( int j = 0; j < m; j++ )
        {
            mm = max( mm, dp[i][j] );
        }
        mx[i] = mm;
    }
    int k ;
    cin >> k;
    for( int i = 0; i < k; i++ )
    {
        int l, r;
        cin >> l >> r;
        l--;
        int s = r-l;
        if( mx[l] >= s )
        {
            cout << "Yes\n";
        }
        else
            cout << "No\n";

    }

    return 0;
}



