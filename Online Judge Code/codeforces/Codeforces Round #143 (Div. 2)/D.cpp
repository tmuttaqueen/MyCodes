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
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl val[20]; //-j, j, -k, k, -i, i
intl x[20], y[20], z[20];
intl x1, y1, z1;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl p, q, r;
    cin >> p >> q >> r;
    cin >> x1 >> y1 >> z1;
    for( int i = 0; i < 6; i++ ) cin >> val[i];
    x[0] = x1;
    y[0] = 0;
    z[0] = z1;

    x[1] = x1;
    y[1] = 2*y1;
    z[1] = z1;

    x[2] = x1;
    y[2] = y1;
    z[2] = 0;

    x[3] = x1;
    y[3] = y1;
    z[3] = 2*z1;

    x[4] = 0;
    y[4] = y1;
    z[4] = z1;

    x[5] = 2*x1;
    y[5] = y1;
    z[5] = z1;

    intl ans = 0;

    for( int i = 0; i < 6; i++ )
    {
        x[i] = 2*p - x[i];
        y[i] = 2*q - y[i];
        z[i] = 2*r - z[i];
        cout << x[i] << " " << y[i] << " " << z[i] << endl;
    }

    if( y[0] < 0 )
        ans += val[0];
    if( y[1] > 0 )
        ans += val[1];
    if( z[2] < 0 )
        ans += val[2];
    if( z[3] > 0 )
        ans += val[3];
    if( x[4] < 0 )
        ans += val[4];
    if( x[5] > 0 )
        ans += val[5];

    cout << ans << endl;

    return 0;
}




