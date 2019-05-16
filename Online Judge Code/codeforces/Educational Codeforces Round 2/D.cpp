#include <bits/stdc++.h>

using namespace std;

const long double pi = 3.141592653589793238462;

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

long double sq(long double a)
{
    return a*a;
}

int main()
{
    ios::sync_with_stdio(false);
    filein;
    long double x1, x2, y1, y2, R, r, d, ans;
    cin >> x1 >> y1 >> R >> x2 >> y2 >> r;
    if( r > R )
    {
        long double temp = R;
        R = r;
        r = temp;
    }
    d = sqrt( sq(x1-x2)+sq(y1-y2) );
    if( d >= R+r )
    {
        cout << 0 << endl;
        return 0;
    }

    if( d+r <= R )
    {
        cout << fixed << setprecision(10) << pi*r*r << endl;
        return 0;
    }

    long double aR = 2*acos( (R*R+d*d-r*r)/(2*R*d) ), ar = 2*acos( (r*r+d*d-R*R)/(2*r*d) ), area;
    ans = 0.5*r*r*ar- 0.5*r*r*sin(ar) + 0.5*R*R*aR - 0.5*R*R*sin(aR);
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}



