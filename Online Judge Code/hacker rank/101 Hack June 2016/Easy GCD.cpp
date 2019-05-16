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
    if( b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n, k, g, a;
    cin >> n >> k;
    n--;
    cin >> g;
    while(n--)
    {
        cin >> a;
        g = gcd(g,a);
    }
    intl sq = sqrt(g);
    intl x = k/g;
    x = g*x;
    for( int i = 2; i <= sq; i++ )
    {
        if(g%i==0)
        x = max( x, k/i*i );
    }


    cout << x << endl;

    return 0;
}



