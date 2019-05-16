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

int ara[222222];
int dp[222222];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, k, q;
    cin >> n >> k >> q;
    for( int i = 0; i < n; i++ )
    {
        int l, r;
        cin >> l >> r;
        ara[l]++;
        ara[r+1]--;
    }
    for( int i = 1; i <= 200000; i++ )
    {
        ara[i] = ara[i] + ara[i-1];
    }
    for( int i = 1; i <= 200000; i++ )
    {
        if( ara[i] >= k )
            dp[i] = 1;
    }

    for( int i =1; i <= 200000; i++ )
        dp[i] = dp[i-1] + dp[i];

    for( int i = 0; i < q; i++ )
    {
        int l,r;
        cin >> l >> r;
        cout << dp[r] - dp[l-1] << endl;
    }

    return 0;
}



