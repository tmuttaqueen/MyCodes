#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const double pi = 3.141592653589793;
const double inf = 10000000000000000.0;

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

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl x[111111], y[111111];
intl px, py;

intl sq(intl a)
{
    return a*a;
}

intl dist2( intl x1, intl y1, intl x2, intl y2  )
{
    return sq(x1-x2)+sq(y1-y2);
}

double dist( intl x1, intl y1, intl x2, intl y2 )
{
    intl d1 = dist2(x1,y1,x2,y2);
    intl d2 = dist2(px, py, x1, y1);
    intl d3 = dist2(px,py,x2,y2);
    if( d2 >= d1+d3 || d3 >= d1+d2 )
        return min(d2,d3);
    else
    {
        double area = (px-x1)*(y1-y2) - (x1-x2)*(py-y1);
        double d = area/sqrt(d1);
        return d*d;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;

    cin >> n >> px >> py;
    for( int i = 0; i < n; i++ )
    {
        cin >> x[i] >> y[i];
    }
    double mx = 0, mn = 100000000000000000.0;
    for( int i = 0; i < n; i++ )
    {
        double dd = sq( x[i]-px ) + sq(y[i]-py);
        mx = max(dd,mx);
        mn = min(dd,mn);
    }
    for( int i = 1; i < n; i++ )
    {
        mn = min( dist(x[i-1], y[i-1], x[i], y[i]), mn );
    }
    //what_is(mn);
    //what_is(mx);
    mn = min( dist(x[0], y[0], x[n-1], y[n-1]), mn );
    cout << setprecision(10) << fixed << pi*mx-pi*mn << endl;;
    return 0;
}
