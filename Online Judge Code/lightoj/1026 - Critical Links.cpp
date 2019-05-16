#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>

const int mx = 10005;

vector<int>edge[mx];
int vis[mx], par[mx], low[mx], tt, dis[mx];
vector<pii>ans;

bool comp( pii a, pii b )
{
    if( a.xx == b.xx )
        return a.yy < b.yy;
    return a.xx < b.xx;
}

void dfs( int u )
{
    vis[u] = 1;
    low[u] = dis[u] = tt++;
    int l = edge[u].size();
    for( int i = 0; i < l; i++ )
    {
        int v = edge[u][i];
        if( !vis[v] )
        {
            par[v] = u;
            dfs(v);
            low[u] = min( low[u], low[v] );
        }
        else if( v != par[u] )
        {
            low[u] = min( low[u], dis[v] );
        }
        if( low[v] > dis[u] )
        {
            if( u < v )
                ans.pb(mp(u, v));
            else
                ans.pb(mp(v, u));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int v;
        scanf("%d", &v);
        for( int i = 0; i < v; i++ )
        {
            int d, a, b;
            scanf("%d (%d)", &a, &d);
            for( int j = 0; j < d; j++ )
            {
                scanf("%d", &b);
                edge[a].pb(b);
            }
        }
        tt = 1;
        memset( vis, 0, sizeof(vis) );
        for( int i = 0; i < v; i++ )
        {
            if( !vis[i] )
            {
                par[i] = -1;
                dfs(i);
            }
        }

        int len = ans.size();

        sort(ans.begin(),ans.end(),comp );


        printf("Case %d:\n%d critical links\n", caseno++, len);

        for( int i = 0; i < len; i++ )
        {
            pii a = ans[i];
            printf("%d - %d\n", a.xx, a.yy);
        }
        for( int i = 0; i < v; i++ ) edge[i].clear();
        ans.clear();
    }

    return 0;
}



