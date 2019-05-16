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
const int SZ = 5000005, mod = 1000000007;

intl ara[SZ], dp[SZ], temp[SZ];

void sieve()
{
    for( intl i = 2; i <= 5000000; i++ )
    {
        intl c = 2;
        for( intl j = i+i; j <= 5000000; j+=i )
        {
            dp[j] = min( dp[j], dp[i] + i*temp[c] );
            c++;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl t, l, r;
    cin >> t >> l >> r;
    ara[0] = 1;
    for( int i = 1; i < SZ; i++ )
    {
        ara[i] = (ara[i-1]*t)%mod;
    }
    for( intl i = 1; i < SZ; i++ )
    {
        dp[i] = i*(i-1)/2;
        temp[i] = dp[i];
    }
    sieve();
    intl ans = 0;
    for( int i = 0; i <= r-l; i++ )
    {
        dp[l+i] %= mod;
        //what_is( dp[l+i] );
        ans = ans + ( ara[i]*dp[l+i] )%mod;
        ans%=mod;
    }
    cout << ans << endl;
    return 0;
}



