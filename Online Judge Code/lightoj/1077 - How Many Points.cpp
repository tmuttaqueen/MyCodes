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

intl gcd( intl a, intl b )
{
    if( b == 0 )
        return a;
    return gcd(b, a%b);
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno =1;
    cin >> t;
    while(t--)
    {
        intl a, b, c, d, g;
        cin >>a >> b >> c >> d;
        c = a - c;
        d = d - b;
        c = abs(c);
        d = abs(d);
        g = gcd(c,d);
        cout << "Case " << caseno++ << ": " << ++g << endl;
    }

    return 0;
}


