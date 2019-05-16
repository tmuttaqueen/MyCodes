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

//typedef tree < intl, null_type,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl mod = 1e9+7;
intl fact[1002];
intl inv[1004];

long long exponentiation( long long a, long long b, long long mod )
{
    long long ans = 1;
    while( b > 0 )
    {
        if( b&1 )
            ans = (a*ans)%mod;
        a = (a*a)%mod;
        b /= 2;
    }
    return ans;
}

vector<int>edge[1005];
int flag[1003];
int sz[1004];
intl dp[1004];

void dfs( int u, int p )
{
    //what_is(u);
    sz[u] = 1;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        //what_is(v);
        if( v != p )
        {
            //what_is(v);
            dfs( v, u );
            sz[u] += sz[v];
        }
    }
    //what_is( sz[u] );
    dp[u] = fact[ sz[u] - 1 ] ;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( v != p )
        {
            dp[u] = (dp[u]*inv[ sz[v] ])%mod;
            dp[u] = ( dp[u]*dp[v] )%mod;
            //what_is( dp[u] );
        }
        //what_is( dp[u] );
    }
    //cout << u << " " << dp[u] << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    fact[0] = 1;
    for( int i = 1; i <= 1000; i++ )
        fact[i] = ( fact[i-1]*i )%mod;
    for( int i = 1; i <= 1000; i++ )
    {
        inv[i] = exponentiation( fact[i], mod-2, mod );
    }

    int t, caseno = 1;
    scanf("%d", &t);
    while( t-- )
    {
        int n;
        scanf("%d", &n);
        for( int i = 0; i <= n; i++ ) edge[i].clear();
        memset( flag, 0, sizeof flag );
        memset( sz, 0, sizeof sz );
        for( int i = 1; i < n; i++ )
        {
            int a, b;
            scanf("%d %d", &a, &b);
            edge[a].pb(b);
            edge[b].pb(a);
            flag[b] = 1;
        }
        int p;
        for( int i = 1; i <= n; i++ )
            if( flag[i] == 0 )
                p = i;
        dfs(p, -1);
        //what_is(p);
        printf("Case %d: %lld\n", caseno++, dp[p] );
    }
    return 0;
}




