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

const intl mod = 1e9 + 7;

intl bigmod( intl a, intl b )
{
    if( a == 1 ) return b;
    intl ans = bigmod( a/2, b );
    ans = (ans*ans)%mod;
    if( a%2 == 1 )
        ans *= b;
    return ans%mod;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        intl n, m;
        cin >> n >> m;
        if( n == 1 )
        {
            cout << m << endl;
            continue;
        }
        intl ans = bigmod(n-1, m-1);
        ans = (ans*m)%mod;
        cout << ans << endl;
    }

    return 0;
}



