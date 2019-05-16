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

intl x[M], y[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ )
        cin >> x[i] >> y[i];
    intl ans = 0, sx = 0, sy = 0, sqx = 0, sqy = 0;
    for( int i = n; i >= 1; i-- )
    {
        ans += (n-i)*(x[i]*x[i] + y[i]*y[i]);
        ans += (sqx + sqy);
        ans -= 2*x[i]*sx;
        ans -= 2*y[i]*sy;
        sx += x[i];
        sy += y[i];
        sqx += x[i]*x[i];
        sqy += y[i]*y[i];
    }
    cout << ans << endl;
    return 0;
}
