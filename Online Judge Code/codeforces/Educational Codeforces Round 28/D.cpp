#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

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
#define piii        pair<int, pii>
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int ara[505][505], dp[505][505];
int n, m, k, q;
piii tt[511111];
int x[511111], y[511111], t[511111];


bool solve(int ind)
{
    memset(ara, 0, sizeof ara);
    //memset(dp, 0, sizeof dp );
    for( int i = 0; i <= ind; i++ )
    {
        ara[ x[i] ][ y[i] ] = 1;
    }
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1] + ara[i][j] - dp[i-1][j-1];
        }
    }
    /*for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/
    int d = k*k;
    for( int i = 0; i <= n-k; i++ )
    {
        for( int j = 0; j <= m-k; j++ )
        {
            int s = dp[i+k][j+k] - dp[i][j+k] - dp[i+k][j] + dp[i][j];
            if( s == d )
                return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    cin >> n >> m >> k >> q;
    for( int i = 0; i < q; i++ )
    {
        cin >> tt[i].yy.xx >> tt[i].yy.yy >> tt[i].xx;
    }
    sort( tt, tt+q );
    for( int i = 0; i < q; i++ )
    {
        x[i] = tt[i].yy.xx;
        y[i] = tt[i].yy.yy;
        t[i] = tt[i].xx;
    }
    int l = 0, h = q-1, ans=-1;
    while( l <= h )
    {
        int m = (l+h)/2;
        //what_is(m);
        if( solve(m) )
        {
            h = m-1;
            ans = t[m];
        }
        else
        {
            l = m+1;
        }
    }
    cout << ans << endl;
    return 0;
}
