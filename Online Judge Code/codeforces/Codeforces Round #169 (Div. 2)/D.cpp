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
    intl l, r;
    cin >> l >> r;
    intl la = l, lb = l, ra = r, rb = r;
    intl a = 0, b = 0;
    for( intl i = 62; i >= 0; i-- )
    {
        //what_is(i);
        //getchar();
        intl x = 1;
        intl d = x<<i;
        intl dd = d-1;
        //what_is(d);
        if( a + d <= r && a + d + dd >= l && b + dd >= l )
        {
            a += d;
        }
        else if( b + d <= r && b + d + dd >= l && a + dd >= l )
        {
            b += d;
        }
        else if( a + d > r && b + d > r )
        {
            a += 0;
            b += 0;
        }
        else
        {
            a += d;
            b += d;
        }
        //what_is(i);
        //what_is(a);
        //what_is(b);
    }
    cout << (a^b) << endl;
    //cout << min(a,b) << " " << max(a,b) << endl;
    return 0;
}



