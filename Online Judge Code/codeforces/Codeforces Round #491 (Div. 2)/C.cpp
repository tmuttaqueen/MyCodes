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
intl n;
intl solve(intl k)
{
    intl t = n, x  =0;
    while(t > 0)
    {
        x += min(k, t);
        t = max(0LL, t-k);
        t -= t/10;
    }
    return x*2LL >= n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl l = 1, r = 1e18, ans = 1e18;
    cin >> n;
    while(l <= r)
    {
        intl m = (l+r)/2;
        if( solve(m) )
        {
            ans = m;
            r = m -1;
        }
        else
            l = m+1;
    }
    cout << ans << endl;
    return 0;
}
