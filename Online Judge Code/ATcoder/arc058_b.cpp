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
const intl mod = 1e9 + 7;

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 200008;

intl fact[M], inv[M];

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    fact[0] = 1;
    inv[0] = 1;
    for( int i = 1; i < M; i++ )
    {
        fact[i] = (fact[i-1]*i)%mod;
        inv[i] = exponentiation( fact[i], mod-2, mod );
    }
    intl n, m, a, b;
    cin >> n >> m >> a >> b;
    intl ans = (((fact[n+m-2]*inv[n-1])%mod)*inv[m-1])%mod;
    intl y = b;
    //what_is(ans);
    for( intl x = n-a+1; x <= n; x++ )
    {
        ans = (ans - (((((fact[x+y-2]*inv[x-1])%mod)*inv[y-1])%mod)*((((fact[m-y-1+n-x]*inv[m-y-1])%mod)*inv[n-x])%mod))%mod)%mod;
    }
    cout << (ans+mod)%mod << endl;
    return 0;
}
