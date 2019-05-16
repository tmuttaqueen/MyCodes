
#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", "stdout")
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
const long long mod = 1000000007;

long long temp;
long long ara[100005];

long long bigmod( long long a, int d )
{
    if( d == 1 )
        return a;
    long long x = bigmod( a, d/2 );
    x = (x*x)%mod;
    if( d&1 )
        x = (x*temp)%mod;
    return x%mod;
}


int main()
{
    //filein;
    int t;
    scanf("%d", &t);
    while( t-- )
    {
        long long n, x;
        long long m;
        cin >> n >> x >> m;
        for( int i = 1; i <= n; i++ )
        {
            scanf("%lld", &ara[i]);
            ara[i] %= mod;
        }
        //temp = 3;
        //cout << (10*6*bigmod((long long)3,mod-2))%mod << endl;
        long long p = 1, a = 0;
        long long ans = (p*ara[x])%mod;
        for( int i = x-1; i > 0; i-- )
        {
            a++;
            temp = a;
            p = (bigmod( temp, mod - 2 )*p)%mod;
            p = (p*((a+m-1)%mod))%mod;
            ans += (p*ara[i])%mod;
            ans %= mod;
            //what_is(ans);
        }
        cout << ans << "\n";
    }
    return 0;
}

