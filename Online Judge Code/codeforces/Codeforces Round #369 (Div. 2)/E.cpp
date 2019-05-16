//After so long today i talked to you. it felt so good, heavenly. i wish i could always talk to you and stare at you!!!!
#include <bits/stdc++.h>

using namespace std;

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
#define double      double

intl mod = 1000003;

intl bigmod( intl a, intl b )
{
    if( b == 0 )
        return 1;
    if( b == 1 )
        return a;
    intl z = bigmod( a, b/2 );
    z = (z*z)%mod;
    if(b&1)
        z = (z*a)%mod;
    return z%mod;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    //cout << bigmod(2,576460752303423488) << endl;
    intl n, k, x=0;
    cin >> n >> k;
    intl temp = 2;
    if(n < 63)
    {
        intl d = 1;
        for( int i = 1; i <= n; i++ )
            d *= 2;
        if( d < k )
        {
            cout << 1 << " " << 1 << endl;
            return 0;
        }
    }
    while( temp < k )
    {
        x += (k-1)/temp;
        temp *= 2;
    }
    //what_is(x);
    x = bigmod(2,x);
    intl rem = bigmod(x, mod-2);
    intl nn = bigmod(2, n);
    //what_is(nn);
    intl A, B;
    B = bigmod(nn, k-1);
    //what_is(B);
    B = (B*rem)%mod;
    //what_is(B);
    A = 1;
    //debug;
    if( k > mod )
        A = 0;
    else
        for( int i = 1; i < k; i++ )
            A = (A*(nn - i))%mod;
    A = (A*rem)%mod;
    A = (B-A)%mod;
    A = (A+mod)%mod;
    B = (B+mod)%mod;
    //debug;
    cout << A << " " << B << endl;
    return 0;
}




