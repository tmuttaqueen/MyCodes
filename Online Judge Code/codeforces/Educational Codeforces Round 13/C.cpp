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

intl gcd( intl a, intl b )
{
    if( b ==0 ) return a;
    return gcd(b,a%b);
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n, a, b, p, q, x,y, z;
    cin >> n >> a >> b >> p >> q;
    intl g = a*b/gcd(a,b);
    x = n/a;
    y = n/b;
    g = n/g;
    if( p > q )
    {
        cout << x*p+(y-g)*q << endl;
    }
    else
        cout << y*q+(x-g)*p << endl;
    return 0;
}



