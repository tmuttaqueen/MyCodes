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

string s[505];
int dp[505][505];
vector<int>ara[505];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m, k;
    cin >> n >> m >> k;
    for( int i = 0; i < n; i++ )
    {
        cin >> s[i];
        int c = 0;
        vector<int>vec;
        for( int j = 0; j < m; j++ )
        {
            if( s[i][j] == '1' )
            {
                c++;
                vec.pb(j);
            }
        }
        int tot;
        if( vec.size() == 0 ) tot = 0;
        else if( vec.size() == 1 ) tot = 1;
        else tot = vec[ vec.size()-1 ] - vec[0]+1;
        ara[i].pb( tot );
        for( int j = 1; j < c; j++ )
        {
            int s = 123456;
            for( int l = 0; l <= j; l++ )
            {
                s = min( s, vec[ vec.size()-1-j+l ] - vec[l] + 1 );
            }
            ara[i].pb(s);
        }
        ara[i].pb(0);


    }
    for( int i = 0; i < ara[0].size(); i++ ) dp[0][i] = ara[0][i];
    for( int i = 1; i < n; i++ )
    {
        for( int j = 0; j <= k; j++ )
        {
            dp[i][j] = 123456789;
            if( j > 0 ) dp[i][j] = dp[i][j-1];
            for( int l = 0; l < ara[i].size(); l++ )
            {
                if( j - l >= 0 )
                {
                    dp[i][j] = min( dp[i][j], dp[i-1][j-l] + ara[i][l] );
                }
                else
                    break;
            }
        }
    }
    cout << dp[n-1][k] << endl;

    return 0;
}
