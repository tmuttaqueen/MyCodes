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
long double ara[111][5555];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    for( int i = 1; i <= 100; i++ )
    {
        long double d = (100+i)/100.0;
        ara[i][1] = d;
        for( int j = 2; j <= 5000; j++ )
        {
            ara[i][j] = ara[i][j-1]*d;
            if( ara[i][j] < ara[i][j-1] || ara[i][j] < 0 )
            {
                ara[i][j] = 0;
            }
        }
    }
    while(t--)
    {
        unsigned long long n, p;
        int rr;
        cin >> n >> rr >> p;

        if( p <= n )
        {
            cout << "Case " << caseno++ << ": " << 0 << endl;
            continue;
        }
        long double d = (long double)p/n;
        int l = 1, r = 5000, ans = -1;
        while( l <= r )
        {
            int m = (l+r)/2;
            if( ara[rr][m] <= 0.000000000001 || ara[rr][m] - d >= -0.000000000001 )
            {
                ans = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        cout << "Case " << caseno++ << ": " << ans << endl;
    }
    return 0;
}



