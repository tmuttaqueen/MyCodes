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

vector<intl>edge[100005], weight[100005];
intl dp[100005], st[100005], ch[100005];

void dfs( int u, int p )
{
    ch[u]++;
    intl c = 0;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( v != p )
        {
            dfs(v,u);
            ch[u] += ch[v];
            dp[u] += dp[v];
            dp[u] %= mod;
        }
    }

    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( v != p )
        {
            intl d = st[v] + (weight[u][i]*ch[v])%mod;
            st[u] += d;
            d = ( d*( ch[u] - ch[v] ) )%mod;
            dp[u] += d;
            dp[u] %= mod;
            st[u] %= mod;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, a, b, w;
        cin >> n;
        for( int i = 1; i < n; i++ )
        {
            cin >> a >> b >> w;
            edge[a].pb(b);
            edge[b].pb(a);
            weight[a].pb(w);
            weight[b].pb(w);
        }
        dfs(1,-1);
        intl ans = 0;
        for( int i = 1; i <= n; i++ )
        {
            ans = (ans+dp[i])%mod;
        }
        cout << "Case " << caseno++ << ": " << ans << endl;
        for( int i = 0; i <= n; i++ )
        {
            edge[i].clear();
            weight[i].clear();
        }
        memset(dp, 0, sizeof dp);
        memset(ch, 0, sizeof ch );
        memset(st, 0, sizeof st );
    }
    return 0;
}




