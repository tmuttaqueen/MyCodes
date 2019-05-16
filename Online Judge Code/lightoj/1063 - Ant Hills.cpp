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
bool vis[mx];
bool art[mx];
int low[mx], dis[mx], par[mx];
int tt, child, root;
int ans;
int t, caseno = 1;

void dfs( int u )
{
    low[u] = dis[u] = tt++;
    vis[u] = 1;
    int l = edge[u].size();
    for( int i = 0; i < l; i++ )
    {
        int v = edge[u][i];
        if( !vis[v] )
        {
            if( u == root ) child++;
            par[v] = u;
            dfs(v);
            low[u] = min( low[u], low[v] );
            if( dis[u] <= low[v] && art[u] == 0 && par[u] != -1 )
            {
                art[u] = 1;
                ans++;
                //cout << u << " -- " << v << endl;
            }
        }
        else if( v != par[u])
        {
            low[u] = min( low[u], dis[v] );
        }
    }

}
int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    scanf("%d", &t);
    while(t--)
    {
        memset( vis, 0, sizeof(vis) );
        memset( art, 0, sizeof(art)  );
        //memset( low, 0, sizeof(low)  );
        //getchar();
        int v, e;
        scanf("%d %d", &v, &e);
        for( int i = 0; i < e; i++ )
        {
            int a, b;
            scanf("%d %d", &a, &b);
            edge[a].pb(b);
            edge[b].pb(a);
        }

        tt = 1;
        ans= 0;


        for( int i = 1; i <= v; i++ )
        {
            if( !vis[i] )
            {
                root = i;
                child = 0;
                par[i] = -1;
                dfs(root);
                //what_is(child);
                if( child > 1 )
                {
                    art[i] = 1;
                    ans++;
                }
            }
        }
        for( int i = 1; i <= v; i++ )
        {
            edge[i].clear();
        }
        cout << "Case " << caseno++ << ": " << ans << endl;
    }

    return 0;
}



