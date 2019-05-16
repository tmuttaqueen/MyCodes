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
#define double      long double

intl ara[100005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n, n1, n2;
    cin >> n >> n1 >> n2;
    for( int i = 0; i < n; i++ )
    {
        cin >> ara[i];
    }
    sort( ara, ara + n );
    intl x = max(n1,n2);
    intl y = min(n1,n2);
    intl sx = 0, sy = 0, tx = 0, ty = 0;
    for( int i = n-1; i >= 0; i-- )
    {
        if( n - i <= y )
        {
            sy += ara[i];
        }
        else
            sx += ara[i];

        if( n - i <= x )
            tx += ara[i];
        else
            ty += ara[i];
        if( n - i >= x+y ) break;
    }
    double dd = ty*x + tx*y;
    //what_is(dd);
    double d = sy*x + sx*y;
    d = max(d,dd);
    d /= x;
    d /= y;

    cout << setprecision(10) << fixed << d << endl;

    return 0;
}



