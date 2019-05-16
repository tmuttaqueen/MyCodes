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

vector<int>fact;
intl mod = 1e9+7;
intl f[1234567], invf[1234567], two[1234567];

void factorize( int n )
{
    for( int i = 2; i*i <= n; i++ )
    {
        if( n%i == 0 )
        {
            int c = 0;
            while( n%i == 0 )
            {
                c++;
                n /= i;
            }
            fact.pb( c );
        }
    }
    if( n > 1 ) fact.pb(1);
}

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
    cout.tie(0);
    //filein;
    int t;
    cin >> t;
    f[0] = 1;
    invf[0] = 1;
    two[0] = 1;
    for( intl i = 1; i <= 1000022; i++ )
    {
        f[i] = f[i-1]*i%mod;
        two[i] = two[i-1]*2%mod;
    }
    invf[1000022] = exponentiation( f[1000022], mod-2, mod );
    for( intl i = 1000021; i >= 1; i-- )
    {
        invf[i] = invf[i+1]*(i+1)%mod;
    }
    while( t-- )
    {
        fact.clear();
        int x, y;
        cin >> x >> y;
        factorize(x);
        intl ans = two[y-1];
        for( int i = 0; i < fact.size(); i++ )
        {
            int p = fact[i];
            ans = ans*f[p+y-1]%mod*invf[p]%mod*invf[y-1]%mod;
        }
        cout << ans << endl;
    }
    return 0;
}
