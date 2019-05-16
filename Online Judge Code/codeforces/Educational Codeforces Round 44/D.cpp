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
const int M = 345678;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl n , H;
    cin >> n >> H;
    intl l = 1, h = 2e9+7, ans = 1e18;
    while( l <= h )
    {
        intl x = (l+h)/2;
        intl c = min( H, x);
        intl s = (x-c)*(x+c-1)/2 + x*(x-1)/2;
        intl k = (n-s)/x;
        if( k <= 0 )
        {
            h = x - 1;
        }
        else
        {
            //what_is(s);
            s = n - s;
            s -= k*x;
            //what_is(x);
            //what_is(s);
            ans = min(ans, x-c + x-1 + k + (s>0) );
            l = x + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
