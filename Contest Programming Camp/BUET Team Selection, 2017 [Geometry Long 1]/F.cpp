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
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
//#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

double x[111111], y[111111], z[111111];
double eps = 0.000000001;
int n;
double r;
double volume( double h )
{
    r = 0;
    for( int i  =0; i < n; i++ )
    {
        double d = sqrt( x[i]*x[i] + y[i]*y[i] );
        //what_is(d);
        r = max( r, h*d/(h-z[i]) );
    }
    //what_is(h);
    //what_is(r);
    double v = r*r*h;
    return v;
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    filein;

    while( scanf("%d", &n) == 1 )
    {
        double l = eps, h = 1000000000000.0, vol = 100000000000000000.0, R=0, H=0;
        for( int i = 0; i < n; i++ )
        {
            //what_is(i);
            scanf("%lf %lf %lf", &x[i], &y[i], &z[i]);
            l = max(l,z[i]);
        }
        /*for( int i = 0; i < n; i++ )
        {
            cout << x[i] << " " << y[i] << " " << z[i];
        }*/

        for( int i = 0; i < 100; i++ )
        {
            double m1 = l + (h-l)/3.0, m2 = h - (h-l)/3.0;
            double v1 = volume(m1), v2 = volume(m2);
            //what_is(v1);
            //what_is(v2);
            if( v2-v1 < eps )
            {
                l = m1;
                H = m1;
                R = r;
            }
            else
            {
                h = m2;
                H = m2;
                R = r;
            }
        }
        printf( "%.3f %.3f\n", H, R );

    }

    return 0;
}
