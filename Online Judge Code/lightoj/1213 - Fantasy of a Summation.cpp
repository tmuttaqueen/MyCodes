#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>

intl n, k, s, mod, a;

intl bigmod( intl x, intl y )
{
    if( y == 0 )
        return 1;
    if(y==1)
        return x;
    intl ans = bigmod(x, y/2);
    ans = (ans*ans)%mod;
    if( y&1 )
        ans = (ans*x)%mod;
    return ans;
}

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld %lld %lld", &n, &k, &mod);
        s = 0;
        for( int i = 0; i < n; i++ )
        {
            scanf("%lld", &a);
            s += a;
        }
        intl ans = bigmod(n, k-1);
        ans = (ans*s)%mod;
        ans = (ans*k)%mod;
        printf("Case %d: %lld\n", caseno++, ans);
    }

    return 0;
}



