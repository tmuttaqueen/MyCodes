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

intl ara[1111];
intl mod = 1000000007;

intl gcd( intl a, intl b )
{
    if( b==0) return a;
    return gcd(b,a%b);
}

intl pow( intl a, intl b, intl mod )
{
    if( b == 0 )
        return 1;
    intl x = pow(a,b/2, mod);
    x = (x*x)%mod;
    if( b&1 )
        x = (x*a)%mod;
    return x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    //printf( "%lld\n", pow(3,5,100) );
    intl n, c;
    int t, caseno = 1;
    scanf("%d", &t);
    while( t-- )
    {
        scanf("%lld %lld", &n, &c);
        ara[0]  = 1;
        for( int i = 1; i <= n; i++ )
            ara[i] = (ara[i-1]*c)%mod;
        intl ans = 0;
        for( intl i = 0; i<n; i++ )
        {
            ans += ara[ gcd(n,i) ];
            ans %= mod;
        }
        //what_is(ans);
        ans = (ans* pow(n, mod-2, mod) )%mod;
        //what_is(ans);
        printf("Case %d: %lld\n", caseno++, ans);
    }
    return 0;
}
