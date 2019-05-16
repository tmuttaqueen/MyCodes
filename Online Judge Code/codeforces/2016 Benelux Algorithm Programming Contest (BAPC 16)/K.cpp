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
const int M = 3456789;

intl dp[M][2];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl n , k;
    cin >> n >> k;
    dp[0][0] = dp[1][1] = 1;
    for( int i = 2; i <= n; i++ )
    {
        dp[i][1] = (i-k-1<0)?dp[i-1][1]
    }
    intl ans;
    if( k==n ) ans = dp[n];
    else ans = dp[n] - dp[n-k-1];
    cout << (ans%123456789+123456789)%123456789 << endl;
    return 0;
}
