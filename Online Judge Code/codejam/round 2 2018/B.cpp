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
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

vector<pii>vec;
int dp[55*55+5][55][55];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno  =1;
    cin >> t;
    while(t--)
    {
        vec.clear();
        int R, B;
        cin >> R >> B;
        for( int i = 0; i <= R; i++ )
        {
            for( int j = 0; j <= B; j++ )
            {
                vec.push_back( mp(i,j) );
                //vec.push_back( mp() )
            }
        }
        int n = vec.size();
        //what_is(n);
        memset( dp, 0, sizeof dp );
        dp[0][0][0] = 0;
        for( int i = 1; i < n; i++ )
        {
            for( int r = 0; r <= R; r++ )
            {
                for( int b = 0; b <= B; b++ )
                {
                    if( vec[i].xx <= r && vec[i].yy <= b )
                    {
                        dp[i][r][b] = max( dp[i-1][r][b], dp[i-1][ r - vec[i].xx ][ b - vec[i].yy ] + 1 );
                    }
                    else
                        dp[i][r][b] = dp[i-1][r][b];
                }

            }
        }
        cout << "Case #" << caseno++ << ": " <<  dp[n-1][R][B] << endl;
    }
    return 0;
}
