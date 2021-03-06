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

intl ara[111];

intl gcd( intl a, intl b )
{
    if( b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl n, c;
    while( scanf("%lld %lld", &n, &c) == 2 )
    {
        ara[0]  = 1;
        for( int i = 1; i <= n; i++ ) ara[i] = ara[i-1]*c;
        intl ans = 0;
        //debug;
        if( n%2 == 0 )
        {
            for( intl i = 0; i<n; i++ )
                ans += ara[ gcd(n,i) ];
            printf("%lld ", ans/n );
            ans += ara[n/2]*n/2 + ara[n/2+1]*n/2;
            ans/=2;
            printf("%lld\n", ans/n);
        }
        else
        {
            for( intl i = 0; i<n; i++ )
                ans += ara[ gcd(n,i) ];
            printf("%lld ", ans/n );
            ans += ara[n/2+1]*n;
            ans/=2;
            printf("%lld\n", ans/n);
        }
    }
    return 0;
}
