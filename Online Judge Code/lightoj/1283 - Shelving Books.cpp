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
#define double      long double

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int book[105], decc[105], inc[105];

bool comp( pii a, pii b )
{
    if( a.xx == b.xx )
        return a.yy > b.yy;
    return a.xx < b.xx;
}

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while( t-- )
    {
        int n, a;
        scanf("%d", &n);
        for( int i = 1; i <= n; i++ )
        {
            scanf("%d", &book[i]);
        }
        memset( decc, 0, sizeof decc );
        for( int i = 1; i <= n; i++ )
        {
            int d = book[i], mx = 0;
            for( int j = 1; j < i; j++ )
            {
                if( book[j] >= d )
                {
                    mx = max( mx, decc[j] );
                }
            }
            decc[i] = mx+1;
        }

        int ans = 1;
        for( int i = 1; i <= n; i++ )
        {
            int d = book[i]-1, val = 0;
            memset( inc, 0, sizeof inc );
            for( int j = 1; j <= n; j++ )
            {
                if( book[j] > d )
                {
                    continue;
                }
                int v = book[j], mx = 0;
                for( int k = 1; k < j; k++ )
                {
                    if( book[k] <= v )
                    {
                        mx = max( mx, inc[k] );
                    }
                }
                inc[j] = mx+1;
                val = max( val, inc[j] );
            }
            ans = max( ans, val + decc[i] );
        }

        printf("Case %d: %d\n", caseno++, ans );
    }

    return 0;
}




