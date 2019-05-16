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

intl doit( intl n, intl r, intl c )
{
    intl ans = 0;
    for( intl i = 1; i <= r; i++ )
    {
        ans += min( n/i, c );
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n, m, k;
    cin >> n >> m >> k;
    intl r =  min( n,m );
    intl c = max( n,m  );
    intl h = r*c, l = 1;
    intl ans = -1;
    while( h >= l )
    {
        //cout << h << " " << l << endl;
        intl m = ( h+l )/2;
        intl d = doit( m, r, c );
        if( d >= k )
        {
            ans = m;
            h = m -1;
        }
        else
            l = m+1;
    }
    cout << ans << endl;
    return 0;
}




