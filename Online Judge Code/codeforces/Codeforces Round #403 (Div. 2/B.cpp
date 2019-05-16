#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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
#define pii         pair<intl, intl>
#define piii        pair<pii, int>
#define double      long double

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

pii dist[100000];
int n;

//long double eps = 0.00000000001;

double maxx( double x )
{
    double ans = 0;
    for( int i = 0; i < n; i++ )
    {
        ans = max( ans, abs( dist[i].xx - x )/(double)dist[i].yy );
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;
    for( int i = 0; i < n; i++ )
        cin >> dist[i].xx;
    for( int i = 0; i < n; i++ )
        cin >> dist[i].yy;
    sort( dist, dist+n );
    double high = 1e9, low = 1;
    double ans = 1e9;

    for( int i = 0; i < 100; i++ )
    {
        double mid1 = (low*2+high)/3.0, mid2 = (low+high*2)/3.0;
        double t1 = maxx(mid1), t2 = maxx(mid2);
        //what_is(mid1);
        //what_is(mid2);
        ans = min( ans, max( t1,t2 ) );
        if( t1 > t2 )
        {
            low = mid1;
        }
        else
        {
            high = mid2;
        }
    }
    cout << setprecision(10) << fixed << ans << endl;
    return 0;
}




