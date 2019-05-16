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

double dist( double x1, double y1, double z1, double x2, double y2, double z2 )
{
    return sqrt( sq(x1-x2) + sq(y1-y2) + sq(z1-z2) );
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
        double x1, x2, x, y1, y2, y, z1, z2, z;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x >> y >> z;
        int tx = x2-x1, ty = y2-y1, tz = z2-z1;
        double l = 0, r = 1, ans = 1e9;
        for( int i= 0; i < 100; i++ )
        {
            double m1 = l+(r-l)/3.0, m2 = r - (r-l)/3.0;
            double d1 = dist( x, y, z, x1+m1*tx, y1+m1*ty, z1+m1*tz ), d2 = dist( x, y, z, x1+m2*tx, y1+m2*ty, z1+m2*tz );
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
