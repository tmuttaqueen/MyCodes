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
int val[5555];
vector<int>ara[5555];
intl dp[5005][5005];
int pre[5005][5005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        for( int i = 1; i <= n; i++ )
        {
            cin >> val[i];
        }

        for( int i = 1; i <= n; i++ )
        {
            ara[i].clear();
        }

        for( int i = 1; i <= n; i++ )
        {
            int x = 0, p;
            for( int j  = i; j > 0; j-- )
            {
                p = x|val[j];

                if( x != p )
                {
                    //cout << j << " " << i << " " << x << " " << p << endl;
                    ara[i].pb(j);
                }
                x = pre[j][i] = p;
            }
            reverse( ara[i].begin(), ara[i].end() );
        }

        for( int i = 1; i <= n; i++ )
        {
            dp[i][1] = pre[1][i];
            int d = min(i,k);
            int x = ara[i].size()-1;
            //for( int j = 0; j <= x; j++ ) cout << ara[i][x] << " ";
            //cout << endl;
            //what_is(x);
            //cout << dp[i][1] << " ";
            for( int j=2; j <= d; j++ )
            {
                int x = ara[i].size()-1;
                dp[i][j] = 0;
                while( x >= 0 && ara[i][x] > j-1 )
                {
                    if( dp[i][j] < dp[ ara[i][x]-1 ][j-1] + pre[ ara[i][x] ][i] )
                    {
                        dp[i][j] = dp[ ara[i][x]-1 ][j-1] + pre[ ara[i][x] ][i];
                    }
                    x--;
                }
                //cout << dp[i][j] << " ";
            }
            //cout << endl;
        }
        cout << dp[n][k] << endl;

    }
    return 0;
}
