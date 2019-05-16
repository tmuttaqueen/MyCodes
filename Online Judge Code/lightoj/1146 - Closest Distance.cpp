#include <bits/stdc++.h>

//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

double sq( double x )
{
    return x*x;
}

double dist( double x1, double y1, double x2, double y2 )
{
    return sqrt( sq(x1-x2) + sq(y1-y2) );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        double ax, ay, bx, by, cx, cy, dx, dy;
        cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
        double tax = bx-ax, tay = by-ay, tcx = dx-cx, tcy = dy-cy;
        double l = 0, r = 1, ans = 1e9;
        for( int i= 0; i < 100; i++ )
        {
            double m1 = l+(r-l)/3.0, m2 = r - (r-l)/3.0;
            double d1 = dist( cx+m1*tcx, cy+m1*tcy, ax+m1*tax, ay+m1*tay ), d2 = dist( cx+m2*tcx, cy+m2*tcy, ax+m2*tax, ay+m2*tay );
            if( d2 < d1 )
            {
                l = m1;
                ans = min(ans, d2);
            }
            else
            {
                r = m2;
                ans = min(ans, d1);
            }
        }
        cout << "Case " << caseno++ << ": " << setprecision(10) << fixed << ans << endl;

    }
    return 0;
}
