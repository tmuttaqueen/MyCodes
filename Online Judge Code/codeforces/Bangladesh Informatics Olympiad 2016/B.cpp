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
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        intl n, k;
        cin >> n >> k;
        intl ans = 1000000000000000LL;
        for( intl i = 2; i*i <= k; i++ )
        {
            if( k%i == 0 )
            {
                int d = 0;
                while(k%i == 0)
                {
                    d++;
                    k/=i;
                }
                intl p = d, an = 0;
                d = i;
                while( d <= n )
                {
                    an += n/d;
                    d*=i;
                }
                an/=p;
                ans = min( ans, an );
            }

        }
        if( k != 1 )
        {
            intl p = 1, an = 0;
            intl d = k;
            while( d <= n )
            {
                an += n/d;
                d*=k;
            }
            an/=p;
            ans = min( ans, an );
        }


        cout << "Case " << caseno++ <<  ": " << ans << endl;
    }
    return 0;
}



