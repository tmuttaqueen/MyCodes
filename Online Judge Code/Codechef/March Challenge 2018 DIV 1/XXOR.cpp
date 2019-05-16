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

int ara[33][123456];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, q, a;
    cin >> n >> q;
    for( int i = 1; i <= n; i++ )
    {
        cin >> a;
        for( int j = 0; j < 31; j++ )
        {
            if( a&(1<<j) )
            {
                ara[j][i] = 1;
            }
        }
    }
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 0; j < 31; j++ )
        {
            ara[j][i] += ara[j][i-1];
        }
    }
    while(q--)
    {
        int l, r;
        int ans = 0;
        cin >> l >> r;
        for( int i = 0; i < 31; i++ )
        {
            int c = ara[i][r] - ara[i][l-1];
            if( 2*c < r - l + 1 )
            {
                ans |= (1<<i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
