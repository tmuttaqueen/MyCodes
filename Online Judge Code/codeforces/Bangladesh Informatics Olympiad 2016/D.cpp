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

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int SZ = 1000005, mod = 1000000007;

pii ara[111111];
int sum[111111];
int dp[111111][55];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        intl n, r, k;
        cin >> n >> r >> k;
        for( int i = 1; i <= n; i++ )
        {
            cin >> ara[i].xx >> ara[i].yy;
        }
        sort( ara+1, ara+n+1 );
        for( int i  =1; i <= n; i++ )
        {
            sum[i] = sum[i-1] + ara[i].yy;
        }
        int l = 1;
        for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= k; j++ )
            {
                int x = ara[i].xx - 2*r;
                while( ara[l].xx < x )
                {
                    l++;
                }
                dp[i][j] = max( dp[i-1][j], dp[l-1][j-1] + sum[i] - sum[l-1] );
            }
        }
        cout << "Case "<< caseno++ << ": " <<  dp[n][k] << endl;
    }
    return 0;
}



