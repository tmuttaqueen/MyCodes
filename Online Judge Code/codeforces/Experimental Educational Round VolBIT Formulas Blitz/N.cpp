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


int main()
{
    //filein;
    long long a, b, c;
    double x, y;
    cin >> a >> b >> c;
    x = -b/1.0 + sqrt(b*b-4*a*c);
    y = -b/1.0 - sqrt(b*b-4*a*c);
    x /= (2*a);
    y /= (2*a);
    if( x > y )
    {
        printf("%.10lf\n%.10lf\n", x, y);
    }
    else
    {
        printf("%.10lf\n%.10lf\n", y, x);
    }

    return 0;
}




