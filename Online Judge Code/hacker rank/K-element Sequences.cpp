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

const int mod = 1e9 + 7;

vector<intl>vec;

void init( )
{
    intl ans = 1;
    vec.pb(1);
    for( int i = 1; i <= 2000000; i++ )
    {
        ans *= i;
        ans%=mod;
        vec.pb(ans);
    }
    return;
}

intl bigmod( intl a, intl b )
{
    if( b == 1 )
        return a;
    intl ans = bigmod( a, b/2 );
    ans *= ans;
    ans %= mod;
    if( b&1 )
        ans *= a;
    return ans%mod;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    init();
    int t;
    cin >> t;
    while(t--)
    {
        intl ans;
        intl n, k;
        cin >> n >> k;
        n--;
        k--;
        cout << (((vec[n]*bigmod( vec[n-k], mod-2 ))%mod)*bigmod( vec[k], mod-2 ))%mod << endl;
    }

    return 0;
}



