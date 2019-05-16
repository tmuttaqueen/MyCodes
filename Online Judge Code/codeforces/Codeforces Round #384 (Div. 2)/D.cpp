#include <bits/stdc++.h>

using namespace std;

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

intl val[200005];
vector<int>edge[200005];
intl cost[200005];
intl maxx[200005];
int vis[200005];
int t = 1;
int nxt[200005];
int dis[200005];

void dfs( int u )
{
    vis[u] = 1;
    dis[t++] = u;
    intl sum = val[u];
    for( int v: edge[u] )
    {
        if( !vis[v] )
        {
            dfs(v);
            sum += cost[v];
        }
    }
    cost[u] = sum;
    nxt[u] = t;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, a, b;
    cin >> n;
    for( int i = 1; i <= n; i++ )
        cin >> val[i];
    for( int i = 1; i<n; i++ )
    {
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dfs(1);
    maxx[n+1] = -1000000000000000000LL;
    for( int i = n ;i >= 1; i-- )
    {
        maxx[i] = max( maxx[i+1], cost[ dis[i] ] );
    }
    intl ans = maxx[n+1];
    for( int i = 1; i <= n; i++ )
    {
        int u = dis[i];
        int v = nxt[u];
        if( v == n+1 )
            continue;
        ans = max( ans, cost[u] + maxx[v] );
    }
    if( ans == maxx[n+1] )
    {
        cout << "Impossible\n";
    }
    else
        cout << ans << endl;
    return 0;
}
