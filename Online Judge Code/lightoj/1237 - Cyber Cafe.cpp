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

namespace mcmf
{
const int MAX = 300001;
const long long INF = 1LL << 60;

long long cap[MAX], flow[MAX], cost[MAX], dis[MAX];
int n, m, s, t, Q[3000010], adj[MAX], link[MAX], last[MAX], from[MAX], visited[MAX];

void init(int nodes, int source, int sink)
{
    m = 0, n = nodes, s = source, t = sink;
    for (int i = 0; i <= n; i++) last[i] = -1;
}

void addEdge(int u, int v, int c, int w)
{
    //printf("%d %d %d\n", u, v, w);
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

int st[100], en[100];

int main()
{

    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n, k, g;
        scanf("%d %d %d", &n, &k, &g);
        for( int i = 1; i <= n; i++ )
            scanf("%d", &st[i]);
        for( int i = 1; i <= n; i++ )
            scanf("%d", &en[i]);
        mcmf::init(2*n+1, 0, 2*n+1);
        for( int i = 1; i <= n; i++ )
        {
            mcmf::addEdge(0,i, 1, 0);
            mcmf::addEdge(i+n,2*n+1, 1, 0);
            for( int j = 1; j <= n; j++ )
            {
                if( en[j] <= st[i] ) continue;
                mcmf::addEdge( i, j+n, 1, min(g, (en[j]-st[i]-k)*(en[j]-st[i]-k) ) );
            }
        }
        pii a = mcmf::solve();
        if( a.yy < n )
        {
            printf("Case %d: impossible\n", caseno++);
            continue;
        }
        int mn = a.xx;
        mcmf::init(2*n+1, 0, 2*n+1);
        for( int i = 1; i <= n; i++ )
        {
            mcmf::addEdge(0,i, 1, 0);
            mcmf::addEdge(i+n,2*n+1, 1, 0);
            for( int j = 1; j <= n; j++ )
            {
                if( en[j] <= st[i] ) continue;
                mcmf::addEdge( i, j+n, 1, -min(g, (en[j]-st[i]-k)*(en[j]-st[i]-k) ) );
            }
        }
        int mx = -mcmf::solve().xx;
        printf("Case %d: %d %d\n", caseno++,mn, mx);
    }
    return 0;
}
