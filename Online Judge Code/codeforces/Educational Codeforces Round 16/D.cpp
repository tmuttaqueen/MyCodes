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
//#define double      long double

piii euclid( intl a, intl b )
{
    if(b==0)
        return mp( mp(1,0), a);
    piii x = euclid(b, a%b);
    //cout << x.xx.xx << " " << x.xx.yy << endl;
    return mp( mp(x.xx.yy, x.xx.xx - (a/b)*x.xx.yy), x.yy );
}

intl gcd( intl a, intl b )
{
    if(b==0)return a;
    return gcd(b, a%b);
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl a, b, c, a1, a2, b1, b2, l, r;
    cin >> a1 >> b1 >> a2 >> b2 >> l >> r;
    intl g = gcd( a1, a2 );
    intl lcm = (a1/g)*a2;
    if( (b2-b1)%g !=0 )
    {
        cout << 0 << endl;
        return 0;
    }
    intl cc = (b2-b1)/gcd(a1,-a2);
    piii d = euclid( a1/g, -a2/g );
    intl x0 = d.xx.xx*cc, y0 = d.xx.yy*cc;
    //what_is(x0);
    //what_is(y0);
    c = ( (a1*x0+b1)%lcm+lcm)%lcm;
    l = max( l, max(b1, b2) );
    if( r < l )
    {
        cout << 0 << endl;
        return 0;
    }
    l -= c;
    r -= c;
    intl d1 = ceil((double)l/lcm), d2 = floor((double)r/lcm);
    cout << d2-d1+1 << endl;
    return 0;
}




