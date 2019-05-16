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

const intl mod = 100000007;
const intl mx = 1e10;
vector<intl>vec;
set<intl>po;

void process()
{
    int n = 1200;
    vec.pb(1);
    vec.pb(1);

    for( int i = 2; i <= n; i++ )
    {
         intl ans = 0;
         int m = ceil(i/2.0);
         for( int j = 0; j < m; j++ )
         {
             ans += 2*vec[j]*vec[i-j-1];
             ans %= mod;
         }
         if( i%2 == 1 )
             ans -= vec[i/2]*vec[i/2];
         ans = (ans%mod+mod)%mod;
         vec.pb(ans);
    }
    vec[0] = 0;
}

intl bigmod( intl x, intl y )
{
    if( y == 1 )
        return x;
    intl ans = bigmod( x, y/2 );
    ans = ans*ans;
    if( y&1 ) ans *= x;
    return ans;
}

void powers()
{
    for( intl i = 2; i < 34; i++ )
    {
        intl num = 2;
        for( intl j = 2; j <= 100000 && num <= mx; j++ )
        {
            num = bigmod(j, i);
            po.insert(num);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    process();
    powers();
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        intl a, b;
        scanf("%lld %lld", &a, &b);
        set<intl>::iterator itl, ith, xp;
        itl = po.lower_bound(a);
        ith = po.upper_bound(b);
        int x = 0;
        for( xp = itl; xp != ith; xp++ )
            x++;
        printf("Case %d: %lld\n", caseno++, vec[x]);
    }

    return 0;
}



