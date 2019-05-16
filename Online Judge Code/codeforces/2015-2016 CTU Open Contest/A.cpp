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
#define pii         pair<double, double>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;
const double inf = 1000000000000000.0;
int n;
pii ara[M];

double solve( double t )
{
    double mx = 0, mn = inf*10000000.0;
    for( int i = 0; i < n; i++ )
    {
        mn = min( mn, (t- ara[i].xx)*ara[i].yy );
        mx = max( mx, (t- ara[i].xx)*ara[i].yy );
    }
    return abs(mx-mn);
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    while( cin >> n )
    {
        if( n == 0 ) break;
        double l = 0, r = 100000.0;
        for( int i = 0; i < n; i++ )
        {
            cin >> ara[i].xx >> ara[i].yy;
            l = max( l, ara[i].xx );
        }
        int c = 0;
        double ans = inf*100000000.0;
        /*for( double m = l; m <= l+1000.0; m++ )
        {
            cout << solve(m) << endl;
        }*/

        while( l <= r )
        {
            if( c > 40 ) break;
            c++;
            double m1 = l+(r-l)/3.0, m2 = r - (r-l)/3.0;
            double d1 = solve(m1), d2 = solve(m2);
            //cout << setprecision(2) << fixed << l << " " << r << " " << m1 << " " << d1 << " " << m2 << " " << d2 << endl;
            if( d1 < d2 )
            {
                r = m2;
                ans = min(ans, d1);
            }
            else
            {
                l = m1;
                ans = min(ans, d2);
            }
        }

        cout << setprecision(10) << fixed << ans << endl;
    }

    return 0;
}
