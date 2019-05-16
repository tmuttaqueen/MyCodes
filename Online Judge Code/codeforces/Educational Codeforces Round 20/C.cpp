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
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int SZ = 1000005, mod = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl n, k;
    cin >> n >> k;
    if( k > 1000000LL )
    {
        cout << -1 ;
        return 0;
    }
    if( k*(k+1) > 2*n )
    {
        cout << -1;
        return 0;
    }
    intl ans = 0;
    for( intl x = 1; x*x <= n; x++ )
    {
        if( n%x == 0 )
        {
            intl p = n/x;
            if( k*(k+1) <= 2*p )
            {
                ans = max(ans, x);
            }
            if( k*(k+1) <= 2*x )
            {
                ans = max(ans, p);
            }
        }
    }

    intl d = n/ans;

    for( intl i = 1; i < k; i++ )
    {
        cout << i*ans << " ";
    }
    cout << (d - k*(k-1)/2 )*ans << " ";


    return 0;
}




