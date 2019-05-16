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
#define piii        pair<pii, int>
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl p[1111][11];
int f[1111];
intl dp[1111][1111];

intl dist( int a, int b )
{
    intl ans = 0;
    for( int i = 0; i < 5; i++ )
        ans += (p[a][i]-p[b][i])*(p[a][i]-p[b][i]);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl n;
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        cin >> p[i][0] >> p[i][1] >> p[i][2] >> p[i][3] >> p[i][4];
    }
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            dp[i][j] = dist( i, j );
        }
    }
    for( int i = 1; i <= n; i++ )
    {
        if( f[i] == 1 )
            continue;
        for( int j = 1; j <= n && f[i] == 0 ; j++ )
        {
            for( int k = 1; k <= n && f[i] == 0; k++ )
            {
                if( i != j && j != k && i!= k )
                {
                    if( dp[j][k] < dp[i][j] + dp[i][k] )
                    {
                        f[i] =1 ;
                    }
                    else
                    {
                        f[j] = 1;
                        f[k] = 1;
                    }
                }
            }
        }
        //what_is( i );
        //what_is(f[i]);
    }
    int ans = n;
    for( int i = 1; i <= n; i++ ) ans -= f[i];
    cout << ans << endl;
    for( int i = 1; i <= n; i++ )
    {
        if( f[i] == 0 )
        {
            cout << i << endl;
        }
    }

    return 0;
}
