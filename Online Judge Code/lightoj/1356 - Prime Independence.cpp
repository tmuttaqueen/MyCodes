#include<bits/stdc++.h>

using namespace std;

#define pb push_back

const int MAX = 40005, NIL = 0, INF = 1<<28;

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

int pos[500005], ara[40005], mm[40005];
int flag[500005];
vector<int>vec[40005];

void prime( int x)
{
    int d = ara[x];
    for( int i = 2; i*i <= d; i++ )
    {
        if( d%i == 0 )
        {
            while(d%i==0) d/=i;
            vec[x].pb(i);
        }
    }
    if( d != 1 ) vec[x].pb(d);
    return;
}

int main()
{
    //cout << "yes" << endl;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int N;
        scanf("%d", &N);
        memset( flag, 0, sizeof flag );
        memset( pos, 0, sizeof pos );
        for( int i = 0; i <= N; i++ ) edge[i].clear();
        for( int i = 0; i <= N; i++ ) vec[i].clear();
        for( int i = 1; i <= N; i++ )
        {
            scanf("%d", &ara[i]);
            flag[ ara[i] ] = i;
            prime(i);
        }
        for( int i = 1; i <= N; i++ )
        {
            //cout << flag[ ara[i] ] << endl;
            int u = ara[i];
            if( pos[u] == 0 )
            {
                for( int j = 0; j < vec[i].size(); j++ )
                {
                    //cout << u << " - "  << u/vec[i][j] << endl;
                    if( flag[ u/vec[i][j] ] )
                    {
                        if( pos[  u/vec[i][j] ] == -1 )
                            pos[u] = 1;
                        else if( pos[ u/vec[i][j] ] == 1 )
                            pos[u] = -1;
                    }
                }
            }
            //cout << pos[u] << endl;
            for( int i = 0; i < vec[flag[u]].size(); i++ )
            {
                int v = u/vec[flag[u]][i];
                //cout << u << " " << v << endl;
                if( flag[v] )
                {
                    if( pos[v] == 0 && pos[u] == 0 )
                    {
                        pos[u] = -1;
                        pos[v] = 1;
                    }
                    else if( pos[u] == 0 )
                    {
                        if( pos[v] == -1 ) pos[u] = 1;
                        else pos[u] = -1;
                    }
                    else if( pos[v] == 0 )
                    {
                        if( pos[u] == -1 ) pos[v] = 1;
                        else pos[v] = -1;
                    }
                }
            }
            //cout << pos[u] << endl;
        }
        int c = 1;
        for( int i = 1; i <= N; i++ )
        {
            //cout << pos[ ara[i] ] << endl;
            if( pos[ ara[i] ] == -1 )
                mm[i] = c++;
        }
        n = c-1;
        //cout << n << " --------- " << endl;
        for( int i = 1; i <= N; i++ )
        {
            if( pos[ ara[i] ] == 1 )
            {
                mm[i] = c++;
            }
        }
        m = c-1;
    if( n == 0 || m == n)
    {
        printf("Case %d: %d\n", caseno++, N );
        continue;
    }
        //cout << m << endl;
        //if( m != N ) while(1);
        //cout << m << " ---- ";
        for( int i = 1; i <= N; i++ )
        {
            //cout << mm[i] << " - " ;
            int u = ara[i];
            for( int i = 0; i < vec[flag[u]].size(); i++ )
            {
                int v = u/vec[flag[u]][i];
                if( flag[v] )
                {
                    //cout << u << " " << v << " " << flag[u] << " " << flag[v] << " " << mm[flag[u]] << ' ' << mm[flag[v]] << endl;
                    edge[ mm[flag[u]] ].pb( mm[flag[v]]);
                    edge[ mm[flag[v]] ].pb( mm[flag[u]]);
                }
            }
        }
        int x = hopcroft_karp();
        //cout << "x is " << x << endl;
        printf("Case %d: %d\n", caseno++, N-x );
    }
    return 0;
}
