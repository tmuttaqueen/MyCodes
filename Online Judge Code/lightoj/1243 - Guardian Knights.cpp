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
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

using namespace std;

/// Min-cost Max-flow using SPFA (Shortest Path Faster Algorithm)
/// 0 Based indexed for directed weighted graphs (for undirected graphs, just add two directed edges)

namespace mcmf
{
const int MAX = 300010;
const long long INF = 1LL << 60;

long long cap[MAX], flow[MAX], cost[MAX], dis[MAX];
int n, m, s, t, Q[MAX*10], adj[MAX], link[MAX], last[MAX], from[MAX], visited[MAX];

void init(int nodes, int source, int sink)
{
    m = 0, n = nodes, s = source, t = sink;
    for (int i = 0; i <= n; i++) last[i] = -1;
}

void addEdge(int u, int v, long long c, long long w)
{
    adj[m] = v, cap[m] = c, flow[m] = 0, cost[m] = +w, link[m] = last[u], last[u] = m++;
    adj[m] = u, cap[m] = 0, flow[m] = 0, cost[m] = -w, link[m] = last[v], last[v] = m++;
}

bool spfa()
{
    int i, j, x, f = 0, l = 0;
    for (i = 0; i <= n; i++) visited[i] = 0, dis[i] = INF;

    dis[s] = 0, Q[l++] = s;
    while (f < l)
    {
        i = Q[f++];
        for (j = last[i]; j != -1; j = link[j])
        {
            if (flow[j] < cap[j])
            {
                x = adj[j];
                if (dis[x] > dis[i] + cost[j])
                {
                    dis[x] = dis[i] + cost[j], from[x] = j;
                    if (!visited[x])
                    {
                        visited[x] = 1;
                        if (f && rand() & 7) Q[--f] = x;
                        else Q[l++] = x;
                    }
                }
            }
        }
        visited[i] = 0;
    }
    return (dis[t] != INF);
}

pair <long long, long long> solve()
{
    int i, j;
    long long mincost = 0, maxflow = 0;

    while (spfa())
    {
        long long aug = INF;
        for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i])
        {
            aug = min(aug, cap[j] - flow[j]);
        }
        for (i = t, j = from[i]; i != s; i = adj[j ^ 1], j = from[i])
        {
            flow[j] += aug, flow[j ^ 1] -= aug;
        }
        maxflow += aug, mincost += aug * dis[t];
    }
    return make_pair(mincost, maxflow);
}
}


char str[50][50];
int ara[50][50];
int dist[33][33];
int lim[100];
int dx[] = {1,-1, 0,0}, dy[] = {0, 0, 1, -1};
int n;

void bfs( int x, int y )
{
    queue<pii>q;
    q.push( mp(x,y) );
    while( !q.empty() )
    {
        pii t = q.front();
        q.pop();
        for( int i = 0; i < 4; i++ )
        {
            x = t.xx+dx[i], y = t.yy + dy[i];
            if( x >= 0 && x < n && y >= 0 && y < n && str[x][y] != '#' && dist[x][y] == -1 )
            {
                dist[x][y] = dist[t.xx][t.yy]+1;
                q.push( mp(x,y) );
            }
        }
    }
}

int main()
{
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int  k, m;
        scanf("%d %d %d\n", &n, &k, &m);
        int S = 0, T = k+m+1;
        int cnt = 1;
        for( int i = 0; i < n; i++ )
            scanf("%s", str[i]);
        for( int i = 0; i < k; i++  )
            scanf("%d", &lim[i]);
        mcmf::init(T+1, S, T);
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < n; j++ )
                if( str[i][j] >= 'A' && str[i][j] <= 'Z' )
                {
                    ara[i][j] = cnt++;
                    mcmf::addEdge(S, ara[i][j], lim[ str[i][j] -'A' ], 0 );

                }
        for( int i = 0; i < n; i++ )
            for( int j = 0; j < n; j++ )
                if( str[i][j] == 'm' )
                {
                    ara[i][j] = cnt++;
                    mcmf::addEdge(ara[i][j], T, 1, 0 );
                }
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                if( str[i][j] >= 'A' && str[i][j] <= 'Z' )
                {
                    memset( dist, -1, sizeof dist );
                    dist[i][j] = 0;
                    bfs(i, j);
                    for( int x = 0; x < n; x++ )
                    {
                        for( int y = 0; y < n; y++ )
                        {
                            if( str[x][y] == 'm' && dist[x][y] > 0 )
                                mcmf::addEdge( ara[i][j], ara[x][y], 1, dist[x][y] );
                        }
                    }
                }
            }
        }
        pii ans = mcmf::solve();
        printf("Case %d: %d\n", caseno++, ans.xx);

    }
    return 0;
}
