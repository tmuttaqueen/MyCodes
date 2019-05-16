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
intl mod = 1e9+7;

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

int mobius( intl n )
{
    if( n == 1 ) return 1;
    int c = 0;
    for( intl i = 2; i*i <= n; i++ )
    {
        if( n%(i*i) == 0 ) return 0;
        if( n%i == 0 ) c++;
        while( n%i == 0 ) n/=i;
    }
    if( n > 1 ) c++;
    return c%2?-1:1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    //for( int i = 1; i <= 10; i++ ) cout << mobius(i) <<endl;
    intl x, y;
    cin >> x >> y;
    if( y%x )
    {
        cout << 0 << endl;
        return 0;
    }
    intl n = y/x;
    intl ans = 0;
    for( intl i = 1; i*i <= n; i++ )
    {
        if( i*i == n )
        {
            ans += mobius(i)*exponentiation(2, i-1, mod);
            //what_is(ans);
        }
        else if( n%i == 0 )
        {
            ans += mobius(n/i)*exponentiation(2, i-1, mod);
            //cout << mobius(n/i) << " " << n/i << " " << i << " " << mobius(i) << endl;
            //what_is(ans);
            ans += mobius(i)*exponentiation(2, n/i-1, mod);
            //what_is(ans);
            ans %= mod;
        }
    }

    cout << (ans+mod)%mod << endl;
    return 0;
}
