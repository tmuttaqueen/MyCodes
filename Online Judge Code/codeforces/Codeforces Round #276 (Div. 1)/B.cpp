#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int flag[1000005];
int ara[1000005];
int dp[2000005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, a;
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> a;
        flag[a] = 1;
    }
    int c = 0;
    for( int i = 1; i <= 1000000; i++ )
    {
        if( flag[i] )
            ara[c++] = i;
    }
    n = c-1;
    for( int i = 2000000; i>= 1; i-- )
    {
        if( n > 0 && i < ara[n] )
        {
            n--;
        }
        dp[i] = ara[n];
    }
    int mx = ara[c-1];
    int ans = 0;
    for( int i = c-1; i >= 0; i-- )
    {
        a = ara[i];
        int v = a;
        while( v < mx )
        {
            int val = dp[v+a-1];
            ans = max( ans, val- v );
            v += a;
        }
    }
    cout << ans << endl;
    return 0;
}




