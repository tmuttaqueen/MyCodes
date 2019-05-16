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

int cnt[111111];
intl val[111111];
intl poww[111111], ara[111111], ans, n;

void sieve()
{
    for( int i = 100000; i >= 2; i-- )
    {
        intl d = 0, t = 0;
        for( int j = i; j <= 100000; j+=i )
        {
            d += cnt[j];
            t += val[j];
        }
        val[i] = (( poww[d]-t-d-1 )%mod+mod)%mod;
        ans = (ans-val[i])%mod;

    }
    ans -= n;
    ans += cnt[1];
    ans = (ans+mod)%mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    poww[0] = 1;
    for( int i = 1; i <= 100000; i++ )
    {
        poww[i] = (poww[i-1]*2)%mod;
    }
    cin >> n;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
        cnt[ ara[i] ]++;
    }
    ans = poww[n];
    sieve();
    ans--;
    ans = (ans+mod)%mod;
    cout << ans << endl;
    return 0;
}




