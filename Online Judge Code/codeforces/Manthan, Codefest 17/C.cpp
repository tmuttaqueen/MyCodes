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
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double
typedef struct touple
{
    int xx,yy,zz;
    touple( int x = 0, int y = 0, int z = 0 )
    {
        xx=x;
        yy=y;
        zz=z;
    }
    bool operator<(const touple &a )
    {
        if( xx == a.xx )
        {
            if( yy == a.yy )
                return zz < a.zz;
            return yy < a.yy;
        }
        return xx<a.xx;
    }

} tii;
//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
intl n, m, k, x;
vector<int>edge[123456];
intl dp[123456][12][3];
intl mod = 1e9+7;

void dfs( int u, int pp )
{
    //cout << u << ": " << p << endl;
    int f = 1;
    for( int v: edge[u] )
    {
        if( v != pp )
        {
            f = 0;
            dfs(v,u);
        }
    }
    if( f )
    {
        dp[u][0][0] = k-1;
        dp[u][0][1] = m-k;
        dp[u][1][2] = 1;
        return;
    }

    intl ans[x+1];
    intl temp[x+1], anstemp[x+1];
    for( int i = 0; i < 3; i++ )
    {
        ans[0] = 1;
        for( int j = 1; j <= x; j++ )
        {
            ans[j] = 0;
        }
        for( int v: edge[u] )
        {
            if( v == pp )
                continue;
            for( int j = 0; j <= x; j++ )
            {
                anstemp[j] = 0;
                temp[j] = 0;
                for( int k = 0; k < 3; k++ )
                {
                    if( i + k <= 2 )
                    {
                        temp[j] += dp[v][j][k];
                    }
                }
                temp[j] %= mod;
            }
            for( int j = 0; j <= x; j++ )
            {
                for( int k = 0; k <= x; k++ )
                {
                    if( j+k <= x )
                    {
                        anstemp[j+k] = ( anstemp[j+k] + temp[k]*ans[j] )%mod;
                    }
                }
            }
            for( int j = 0; j <= x; j++ ) ans[j] = anstemp[j];
        }
        intl mul = 1;
        if(i==0) mul = k-1;
        if(i==1) mul = m-k;
        if( i != 2 )
            for( int j = 0; j <= x; j++ )
                dp[u][j][i] = (ans[j]*mul)%mod;
        if( i == 2 )
            for( int j = 1; j <= x; j++ )
                dp[u][j][i] = ans[j-1];

    }


}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int a, b;
    cin >> n >> m;
    for( int i = 1; i < n; i++  )
    {
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    cin >> k >> x;
    dfs(1,-1);
    intl ans = 0;
    for( int i = 0; i <= x; i++ )
    {
        for( int j = 0; j < 3; j++ )
        {
            ans = ( ans+ dp[1][i][j] )%mod;
        }
    }
    cout << ans << endl;
    return 0;
}
