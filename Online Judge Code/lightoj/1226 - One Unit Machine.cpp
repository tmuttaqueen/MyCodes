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

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

const intl mod = 1e9 + 7;

long long exponentiation( long long a, long long b, long long mod )
{
    long long ans = 1;
    while( b > 0 )
    {
        if( b&1 )
            ans = (a*ans)%mod;
        a = (a*a)%mod;
        b /= 2;
    }
    return ans;
}

intl fact[1000005], inv[1000005], ara[1005], dp[1005];

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    fact[0] = 1;
    inv[0] = 1;
    for( int i = 1; i <= 1000000; i++ )
    {
        fact[i] = (fact[i-1]*i)%mod;
        inv[i] = exponentiation( fact[i], mod-2, mod );
    }
    //cout << fact[1] << " " << fact[2] << endl;
    int t, caseno = 1;
    scanf("%d", &t);
    while( t--)
    {
        int n;
        scanf("%d", &n);
        for( int i = 0; i < n; i++ ) scanf("%d", &ara[i]);
        dp[0] = 1;
        intl sum = ara[0];
        for( int i = 1; i < n; i++ )
        {
            dp[i] = ((((( dp[i-1]*fact[sum+ara[i]-1 ])%mod)*inv[sum])%mod)*inv[ ara[i]-1 ])%mod;
            sum += ara[i];
        }
        printf("Case %d: %lld\n", caseno++, dp[n-1] );
    }
    return 0;
}




