#include<bits/stdc++.h>

using namespace std;


#define pii pair<intl,intl>
#define mp make_pair
#define xx first
#define yy second
#define pb push_back
#define intl long long

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

intl distt( pii &a, pii &b )
{
    return (a.xx-b.xx)*(a.xx-b.xx) + (a.yy-b.yy)*(a.yy-b.yy);
}

vector<pii>aset, bset;

int main()
{

    int k, v;
    cin >> v >> k;
    intl a, b;
    for( int i = 0; i < v; i++ )
    {
        cin >> a >> b;
        aset.pb(mp(a,b));
    }
    for( int i = 0; i < v; i++ )
    {
        cin >> a >> b;
        bset.pb(mp(a,b));
    }
    n = v;
    m = 2*v;
    intl l = 0, r = 2*1e10+5.0;
    intl ans;
    while( l <= r )
    {
        intl mid = (l+r)/2;
        for( int i = 0; i < n; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                if( distt( aset[i], bset[j] ) > mid )
                {
                    edge[i+1].pb(n+j+1);
                    edge[n+j+1].pb(i+1);
                }
            }
        }
        int d = hopcroft_karp();
        //cout << mid << " " << d << endl;
        if( m - d >= k )
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
        for( int i = 0; i <= m; i++ ) edge[i].clear();
    }

    cout << setprecision(10) << fixed << sqrt(ans) << endl;

    return 0;
}
