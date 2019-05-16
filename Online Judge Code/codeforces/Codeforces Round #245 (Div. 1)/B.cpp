#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl ara[1005][1005];
intl lur[1005][1005], rul[1005][1005], ldr[1005][1005], rdl[1005][1005];

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, m;
    cin >> n >> m;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            cin >> ara[i][j];
        }
    }

    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= m; j++ )
        {
            ldr[i][j] = ara[i][j] + max( ldr[i-1][j], ldr[i][j-1] );
        }
    }

    for( int i = n; i >= 1; i-- )
    {
        for( int j = 1; j <= m; j++ )
        {
            lur[i][j] = ara[i][j] + max( lur[i+1][j], lur[i][j-1] );
        }
    }

    for( int i = 1; i <= n; i++ )
    {
        for( int j = m; j >= 1; j-- )
        {
            rdl[i][j] = ara[i][j] + max( rdl[i-1][j], rdl[i][j+1] );
        }
    }

    for( int i = n; i >= 1; i-- )
    {
        for( int j = m; j >= 1; j-- )
        {
            rul[i][j] = ara[i][j] + max( rul[i+1][j], rul[i][j+1] );
        }
    }
    intl ans = -1, p , q;
    for( int i = 2; i < n; i++ )
    {
        for( int j = 2; j < m; j++ )
        {

            ans = max( ans,  max(rul[i][j+1] + rdl[i-1][j] + ldr[i][j-1] + lur[i+1][j], ldr[i-1][j] + rul[i+1][j] + lur[i][j-1] + rdl[i][j+1] ));
            /*if( rul[i][j] + rdl[i][j] + ldr[i][j] + lur[i][j] - 4*ara[i][j] == ans )
            {
                cout << i << " " << j << " " << ans << endl;
            }*/
        }
    }
    //cout << p << " " << q << endl;
    cout << ans << endl;

    return 0;
}




