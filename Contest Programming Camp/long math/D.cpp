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
#define double      long double

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;


intl ara[11111][5], n;
double eps = 0.00000001;

double value( double x )
{
    double mx = -1000000000.0;
    for( int i = 0; i < n; i++ )
    {
        mx = max( mx, ara[i][0]*x*x+ara[i][1]*x + ara[i][2] );
    }
    return mx;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for( int i = 0; i < n; i++ )
        {
            cin >> ara[i][0] >> ara[i][1] >> ara[i][2];
        }
        double ans, l = 0, h = 1000;
        //while( l-h <= eps )
        for( int i = 0; i < 200; i++ )
        {
            //what_is(l);
            //what_is(h);
            double m1 = ( l+ (h-l)/3 ), m2 = ( h - (h-l)/3 );
            double d1 = value(m1), d2 = value(m2);
            if( d1 - d2 < eps )
            {
                ans = d1;
                h = m2;
            }
            else
            {
                ans = d2;
                l = m1;
            }
        }
        ans = min(ans, value(0.0));
        ans = min(ans, value(1000.0));

        cout << setprecision(4) << fixed << ans << endl;
    }
    return 0;
}
