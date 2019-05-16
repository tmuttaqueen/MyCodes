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

bool block[222][222];
int node[222][222];
int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2}, dy[] = { -1, 1, 2, -2, 2, -2, -1, 1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    //freopen( "input.txt", "r", stdin );
    //freopen( "output.txt", "w", stdout );
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int r, c, k;
        scanf("%d %d %d", &r, &c, &k);
        memset( block, 0, sizeof block );
        memset( node, 0, sizeof node );
        for( int i =1 ;i <= 40000; i++ ) edge[i].clear();
        int x = 1;
        for( int i = 0; i < k; i++ )
        {
            int a, b;
            scanf("%d %d", &a, &b);
            block[a][b] = 1;
        }
        for( int i = 1; i <= r; i++ )
        {
            for( int j = 1; j <= c; j++ )
            {
                if( (i+j)%2 == 1 && block[i][j] == 0 )
                {
                    node[i][j] = x++;
                }
            }
        }
        n = x - 1;
        for( int i = 1; i <= r; i++ )
        {
            for( int j = 1; j <= c; j++ )
            {
                if( (i+j)%2 == 0 && block[i][j] == 0 )
                {
                    node[i][j] = x++;
                }
            }
        }
        m = x - 1;
        for( int i = 1; i <= r; i++ )
        {
            for( int j = 1; j <= c; j++ )
            {
                if( block[i][j] ) continue;
                for( int p = 0; p < 8; p++ )
                {
                    int x = i+dx[p], y = j+dy[p];
                    if( x >= 1 && x <= r && y >= 1 && y <= c && block[x][y] == 0 )
                    {
                        edge[ node[i][j] ].pb( node[x][y] );
                    }
                }
            }
        }
        int y = hopcroft_karp();
        printf("Case %d: %d\n", caseno++, x-y-1);

    }
    return 0;
}
