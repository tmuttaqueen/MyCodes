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

char str[23][23];
int id[23][23];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int r, c, c1 = 1;
        scanf("%d %d\n", &r , &c);
        memset( id, 0, sizeof id );
        for( int i = 0; i <= r*c; i++ ) edge[i].clear();
        for( int i = 0; i < r; i++ ) scanf("%s", str[i]);
        for( int i = 0; i < r; i++ )
        {
            for( int j = 0; j < c; j++ )
            {
                if( str[i][j] == '*' && (i+j)%2==0 )
                    id[i][j] = c1++;
            }
        }
        n = c1 - 1;
        for( int i = 0; i < r; i++ )
        {
            for( int j = 0; j < c; j++ )
            {
                if( str[i][j] == '*' && (i+j)%2==1 )
                    id[i][j] = c1++;
            }
        }
        m = c1 - 1;
        for( int i = 0; i < r; i++ )
        {
            for( int j = 0; j < c; j++ )
            {
                //cout << id[i][j] << " ";
                for( int k = 0; k < 4; k++ )
                {
                    int x = i+dx[k], y = j+dy[k];
                    if( x >= 0 && x < r && y >= 0 && y < c && str[x][y] == '*' && str[i][j] == '*' )
                    {
                        edge[ id[x][y] ].pb( id[i][j] );
                    }
                }
            }
            //cout << endl;
        }
        int x = hopcroft_karp();
        //what_is(x);
        printf("Case %d: %d\n", caseno++, m-x);
    }
    return 0;
}
