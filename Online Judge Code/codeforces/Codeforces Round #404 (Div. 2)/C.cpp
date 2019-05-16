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


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n,m;
    cin >> n >> m;
    if( n <= m )
    {
        cout << n << endl;
        return 0;
    }
    n = n - m;
    intl h = 1414213570LL, l = 0;
    intl ans = -1;
    while( h >= l )
    {
        intl m = (h+l)/2;
        intl d = n - m*(m+1)/2;
        if( d <= 0 )
        {
            ans = m;
            h = m - 1;
        }
        else
            l = m+1;
    }
    cout << ans+m << endl;
    return 0;
}




