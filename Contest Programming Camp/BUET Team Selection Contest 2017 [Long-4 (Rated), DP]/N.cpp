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

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int dist[111][111];
int dp[44444][22];
pii ara[22];
int c;
int n, m, b;

int solve( int mask, int last)
{
    //if( mask == 0 ) return ;
    //cout << mask << " " << last << endl;
    if( dp[mask][last] != 1000000000 ) return dp[mask][last];
    int mt = mask&(~(1<<last));
    if( mt == 0 )
    {
        dp[mask][last] = dist[ara[last].xx][ ara[last].yy ] +   dist[b][ ara[last].xx ];
        return dp[mask][last];
    }
    for( int j = 0; j < c; j++ )
    {
        if( mt&(1<<j) )
        {
            dp[mask][last] = min( dp[mask][last], solve( mt, j) + dist[ ara[j].yy ][ ara[last].xx ] + dist[ ara[last].xx ][ ara[last].yy ] );
        }
    }
    //debug;
    //what_is(mask);
    return dp[mask][last];
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {

        cin >> n >> m >> b;
        for( int i = 1; i <= n; i++ )
            for( int j = 1; j <= n ; j++ )
            dist[i][j] = 1000000000;
        for(int i = 1; i <= n; i++ )
            dist[i][i] = 0;
        for( int i = 0; i < m; i++ )
        {
            int a,b,w;
            cin >> a >> b >> w;
            dist[a][b] = w;
            dist[b][a] = w;
        }
        for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= n; j++ )
            {
                for( int k = 1; k <= n; k++ )
                {
                    dist[j][k] = min( dist[j][k], dist[j][i] + dist[i][k] );
                }
            }
        }
        //debug;
        int z;
        c = 0;
        cin >> z;
        for( int i = 0; i < z; i++ )
        {
            int u,v,b;
            cin >> u >> v >> b;
            for( int j = 0; j < b; j++ )
            {
                ara[c++] = mp(u,v);
            }
        }

        for( int i = 0; i < (1<<c); i++ )
        {
            for( int j = 0; j <= c; j++ )
                dp[i][j] = 1000000000;
        }
        int ans = 1000000000;
        //what_is(c);
        for( int i = 0; i < c; i++ )
        {
            ans = min( ans, solve( (1<<c)-1, i ) + dist[ ara[i].yy ][b] );
        }

        cout << ans << endl;

    }
    return 0;
}
