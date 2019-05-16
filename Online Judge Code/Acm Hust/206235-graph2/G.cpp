#include<bits/stdc++.h>

using namespace std;

#define pii pair<double, double>
#define mp make_pair
#define xx first
#define yy second
#define pb push_back

const int MAX = 100001, NIL = 0, INF = 1<<28;


vector< int > edge[MAX];
int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// edge = NIL[0] ∪ edge1[edge[1---n]] ∪ edge2[edge[n+1---n+m]]

bool bfs()
{
    int u, v, len;
    queue< int > Q;
    for( int i = 1; i <= n; i++)
    {
        if( match[i] == NIL)
        {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while( !Q.empty() )
    {
        u = Q.front();
        Q.pop();
        if( u != NIL)
        {
            len = edge[u].size();
            for( int i = 0; i < len; i++ )
            {
                v = edge[u][i];
                if( dist[match[v]] == INF )
                {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return dist[NIL] != INF;
}

bool dfs(int u)
{
    int v, len;
    if( u != NIL)
    {
        len = edge[u].size();
        for( int i = 0; i < len; i++)
        {
            v = edge[u][i];
            if( dist[match[v]] == dist[u]+1 )
            {
                if( dfs(match[v]) )
                {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp()
{
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in edge. Clear it for multiple case.
    memset( match, 0, sizeof match );
    memset( dist, 0, sizeof dist );
    while( bfs() )
    {
        for( int i = 1; i <= n; i++)
            if( match[i] == NIL && dfs(i) )
                matching++;
    }
    return matching;
}

vector<pii> rat, hole;

double distt( pii &a, pii &b )
{
    return (a.xx-b.xx)*(a.xx-b.xx) + (a.yy-b.yy)*(a.yy-b.yy);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int s, v;
    while( cin >> n >> m >> s >> v )
    {
        double p, q;
        for( int i = 0; i < n; i++ )
        {
            cin >> p >> q;
            rat.pb(mp(p,q));
        }
        for( int i = 0; i < m; i++ )
        {
            cin >> p >> q;
            hole.pb(mp(p,q));
        }
        double x = s*s*v*v;
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < m; j++ )
            {
                double d = distt( rat[i], hole[j] );
                if( d <= x )
                {
                    edge[i+1].pb( n+j+1 );
                    edge[n+j+1].pb(i+1);
                }
            }
        }
        m += n;
        int mat = hopcroft_karp();
        cout << n -mat << endl;

        for( int i = 0; i <= 200; i++ ) edge[i].clear();
        rat.clear();
        hole.clear();
    }
    return 0;
}
