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
const int MAX = 1000010;
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

int ara[55][55];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int k, n;
    cin >> n >> k;
    mcmf::init(n+1, 1, n);
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            cin >> ara[i][j];
            if( ara[i][j] )
                mcmf::addEdge(i, j, ara[i][j], 0);
        }
    }
    if( mcmf::solve().yy == 0 )
    {
        cout << 0 << endl;
        return 0;
    }
    int ans = 0;
    int l = 0, r = 1e9;
    while( l <= r )
    {
        int m = (l+r)/2;
        mcmf::init(n+2, 0, n+1);
        mcmf::addEdge(0, 1, m, 0);
        mcmf::addEdge(n, n+1, m, 0);
        for( int i = 1; i <= n; i++ )
        {
            for( int j = 1; j <= n; j++ )
            {
                if( ara[i][j] )
                {
                    mcmf::addEdge(i, j, ara[i][j], 0);
                    mcmf::addEdge(i, j, m, 1);
                }
            }
        }
        intl d = mcmf::solve().xx;
        if( d <= k )
        {
            ans = m;
            l = m+1;
        }
        else
            r = m-1;
    }
    cout << ans << endl;
    return 0;
}
