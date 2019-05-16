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
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    //filein;
    intl c = 0, n, k;

    cin >> n >> k;
    //cout << n << ' ' << k << endl;
    while( n > 0 )
    {
        //cout << n << " " << k << endl;
        c++;
        n /= 2;
    }

    //cout << k << ' ' << c << endl;
    int f = 0;
    if( k < c )
    {
        intl t = k;
        k = c;
        f = 1;
        c = t;
    }
    //cout << k << ' ' << c << endl;
    intl ans = (1LL)<<c;
    //cout << ans << endl;
    ans--;
    for( int i = c; i < k && f; i++ )
    {
        ans *= 2;
    }
   // ans--;
    cout << ans << endl;
    return 0;
}
