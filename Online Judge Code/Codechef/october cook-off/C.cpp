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
    int t;
    cin >> t;
    while(t--)
    {
        intl n;
        cin >> n;
        intl ans = 0;
        if( n <= 100000 )
        {
            for( int i = 1; i*i < n; i++ )
            {
                ans += min(700LL, n-i*i );
            }
        }
        else
        {
            intl d = sqrt(n+0.0);
            intl dd =d-40;
            ans += dd*700;
            for( intl i = dd+1; i*i< n; i++ )
            {
                ans += min( n-i*i, 700LL );
            }
        }
        cout << ans << endl;
    }
    return 0;
}
