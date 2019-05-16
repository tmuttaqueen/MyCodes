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

intl mod = 1e9+7;


intl bigmod( intl x, intl y)
{
    if(y==1) return x;
    intl tt = bigmod(x,y/2);
    tt = (tt*tt)%mod;
    if(y&1) tt = (tt*x)%mod;
    return tt;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl a, b, c, d, n, x, ans;
    cin >> a >> b >> n >> x;
    d = bigmod(a,n);
    ans = (d*x)%mod;
    d--;
    d = (d+mod)%mod;
    d = (d*bigmod(a-1, mod-2))%mod;
    d = (d*b)%mod;
    ans = (ans+d)%mod;
    if( a == 1 )
    {
        ans = (x + ((b%mod)*(n%mod))%mod)%mod;
    }
    cout << ans%mod << endl;
    return 0;
}



