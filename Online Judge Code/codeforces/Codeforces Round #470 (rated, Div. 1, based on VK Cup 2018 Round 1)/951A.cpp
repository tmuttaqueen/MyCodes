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
const int M = 1456780;

vector<int>pr[M];
int isc[M];
void sieve()
{
    int n = 1e6+5;
    for( int i = 2; i <= n; i++ )
    {
        if( isc[i] == 0 )
        {
            for( int j = i+i; j <= n; j += i )
            {
                isc[j] = 1;
                pr[j].pb(i);
            }
        }
    }
}

int dp[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    sieve();
    int n = 1e6+5;
    for( int i = 3; i <= n; i++ )
    {
        dp[i] = 1e7;
        if( isc[i] == 0 ) continue;
        for( int x: pr[i] )
        {
            dp[i] = min( dp[i], i - x + 1 );
        }
    }
    //for( int i = 1; i <= 20; i++ ) cout << dp[i] << " ";
    //cout << endl;
    int x;
    cin >> x;
    int ans = 1e7;
    for( int p: pr[x] )
    {
        for( int i = x - p + 1; i <= x; i++ )
        {
            ans = min( ans, dp[i] );
        }
    }
    cout << ans << endl;
    return 0;
}
