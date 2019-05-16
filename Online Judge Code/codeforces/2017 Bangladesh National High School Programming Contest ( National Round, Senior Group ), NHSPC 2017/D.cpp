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
int ara[11111], bit[111];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n;
        memset( bit, 0, sizeof bit );
        cin >> n;
        for( int i = 0; i < n; i++ )
        {
            cin >> ara[i];
            for( int j = 0; j < 20; j++ )
            {
                if( (1<<j)&ara[i] )
                {
                    bit[j]++;
                }
            }
        }
        int ans = 0;
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < 20; j++ )
            {
                if( (1<<j)&ara[i] )
                {
                    bit[j]--;
                }
            }
            int a = 0;
            for( int j = 0; j < 20; j++ )
            {
                if( bit[j]%2 )
                {
                    a += ( 1<<j );
                }
            }
            if( a < ara[i] )
                ans++;
            for( int j = 0; j < 20; j++ )
            {
                if( (1<<j)&ara[i] )
                {
                    bit[j]++;
                }
            }
        }
        cout << "Case " << caseno++ << ": " << ans << endl;
    }
    return 0;
}



