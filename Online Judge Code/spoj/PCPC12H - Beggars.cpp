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
#define pii         pair<intl, intl>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

namespace mcmf
{
const int MAX = 1000010;
const long long INF = 1LL << 60;

long long cap[MAX], flow[MAX], cost[MAX], dis[MAX];
int n, m, s, t, Q[10000010], adj[MAX], link[MAX], last[MAX], from[MAX], visited[MAX];

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


pair<pii, int>ara[123];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    while(1)
    {
        int n;
        cin >> n;
        if( n == 0 ) break;
        mcmf::init(2*n+4, 0, 2*n+3);
        for( int i = 2; i <= n+1; i++ )
        {
            cin >> ara[i].xx.xx >> ara[i].xx.yy >> ara[i].yy;
        }
        mcmf::addEdge(0,1,2,0);
        mcmf::addEdge(2*n+2, 2*n+3, 2, 0);
        for( int i = 2; i <= n+1; i++ )
        {
            mcmf::addEdge(1, i, 1, 0);
            mcmf::addEdge(n+i, 2*n+2, 1, 0);
            mcmf::addEdge( i, n+i, 1, -ara[i].yy );
            for( int j = 2; j <= n+1; j++ )
            {
                if( j == i ) continue;
                if( ara[j].xx.yy >= ara[i].xx.yy && abs( ara[j].xx.xx - ara[i].xx.xx ) <= (ara[j].xx.yy - ara[i].xx.yy) )
                {
                    mcmf::addEdge(n+i, j, 1, 0);
                }
            }
        }
        pii a = mcmf::solve();
        cout << -a.xx << endl;
    }
    return 0;
}
