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
#define piii        pair<pii, int>

int ara[106][106], flow[105][105], par[105], mn;
vector<int>edge[105];
bool vis[105];
int s, t, e, a, b, w, n;

int bfs( )
{
    mn = 1e9;
    memset(vis, 0, sizeof(vis));
    queue<int>qq;
    qq.push(s);
    vis[s] = 1;
    while( !qq.empty() )
    {
        int u = qq.front();
        qq.pop();
        for( int i = 0; i < edge[u].size(); i++ )
        {
            int v = edge[u][i];
            if( vis[v] == 0 && (ara[u][v] - flow[u][v]) > 0)
            {
                qq.push(v);
                vis[v] = 1;
                par[v] = u;
                mn = min( mn, ara[u][v] - flow[u][v] );
                if( v == t )
                    return 1;
            }
        }
    }
    return vis[t];
}

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int tst, caseno = 1;
    scanf("%d", &tst);
    while(tst--)
    {
        memset(ara, 0, sizeof(ara));
        memset( flow, 0, sizeof(flow) );
        scanf("%d", &n);
        scanf("%d %d %d", &s, &t, &e);
        for( int i = 0; i < e; i++ )
        {
            scanf("%d %d %d", &a, &b, &w);
            ara[a][b] += w;
            ara[b][a] += w;
            edge[a].pb(b);
            edge[b].pb(a);
        }
        par[s] = -1;
        int ans = 0;
        int c = 0;
        while( bfs() )
        {
            ans += mn;
            //what_is(mn);
            int v = t, u;
            while( v != s )
            {
                u = par[v];
                flow[u][v] += mn;
                flow[v][u] -= mn;
                v = u;
            }
            c++;
        }
        //what_is(c);
        printf("Case %d: %d\n", caseno++, ans);
    }

    return 0;
}



