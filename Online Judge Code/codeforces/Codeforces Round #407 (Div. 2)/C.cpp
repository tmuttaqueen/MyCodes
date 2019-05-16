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

intl aa[111111], ara[111111], dpx[111111], dpn[111111];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n;
    cin >> n;
    for( int i = 0; i < n; i++ ) cin >> aa[i];
    for( int i = 0 ;i < n-1; i++ )
        ara[i] = abs( aa[i] - aa[i+1] );
    dpx[n-2] = dpn[n-2] = ara[n-2];
    for( int i = n-3; i >= 0; i-- )
    {
        dpx[i] = max( ara[i], ara[i] - dpn[i+1] );
        dpn[i] = min( ara[i], ara[i] - dpx[i+1] );
    }
    n--;
    intl ans = -1000000000000000000LL;
    for( int i = 0; i < n; i++  )
    {
        ans = max( ans, dpx[i] );
    }

    cout << ans << endl;

    return 0;
}



