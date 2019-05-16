#include<bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
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

map<int,int>r, c;
vector<pii>vec;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int v = n;
        for( int i = 0; i < n; i++ )
        {
            int a, b;
            cin >> a >> b;
            vec.push_back( mp(a,b) );
            r[a] = 0;
            c[b] = 0;
        }
        int cnt = 1;
        for( auto it = r.begin(); it != r.end(); it++ )
        {
            it->second = cnt++;
        }
        n = cnt-1;
        for( auto it = c.begin(); it != c.end(); it++ )
        {
            it->second = cnt++;
        }
        m = cnt-1;
        for( int i = 0; i < vec.size(); i++ )
        {
            int a = r[vec[i].xx], b = c[vec[i].yy];
            //cout << a << " " << b << endl;
            edge[a].pb(b);
            edge[b].pb(a);
        }
        //cout << n << m << endl;
        int d = hopcroft_karp();
        cout << d << endl;
        for( int i = 1; i <= m; i++ ) edge[i].clear();
        r.clear();
        c.clear();
        vec.clear();
    }
    return 0;
}
