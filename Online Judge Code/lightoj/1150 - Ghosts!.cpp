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

char str[55][55];
int id[30][30], distt[55][55], tempd[30][30], flag[30][30];
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int dim;

void bfs( int x, int y, int ind )
{
    memset( tempd, 125, sizeof tempd );
    memset( flag, 0, sizeof flag );
    queue<pii>Q;
    tempd[x][y] = 0;
    flag[x][y] = 1;
    Q.push( mp(x,y) );
    while( !Q.empty() )
    {
        pii a = Q.front();
        Q.pop();
        for( int i = 0; i < 4; i++ )
        {
            int x = a.xx + dx[i], y = a.yy + dy[i];
            if( x >= 0 && x < dim && y >= 0 && y < dim && str[x][y] != '#' && flag[x][y] == 0 )
            {
                tempd[x][y] = tempd[a.xx][a.yy] + 1;
                flag[x][y] = 1;
                if( str[x][y] == 'H' )
                {
                    distt[ind][ id[x][y] ] = tempd[x][y];
                }
                Q.push( mp(x,y) );
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {

        memset( id, 0, sizeof id );
        memset( distt, 62, sizeof distt );
        scanf("%d\n", &dim);
        for( int i = 0; i < dim; i++ ) scanf("%s", str[i]);
        int c1 = 1, c2 = 1;
        for( int i = 0; i < dim; i++ )
        {
            for( int j = 0; j < dim; j++ )
            {
                if( str[i][j] == 'G' )
                    id[i][j] = c1++;
                if( str[i][j] == 'H' )
                    id[i][j] = c2++;
            }
        }
        int x = 1;
        for( int i = 0; i < dim; i++ )
        {
            for( int j = 0; j < dim; j++ )
            {
                if( str[i][j] == 'G' )
                {
                    bfs( i, j, x++ );
                }
            }
        }
        int l = 2, r = 1300, ans = -1;
        n = c1-1;
        m = c1+c2-2;
        /*for( int i = 1; i < c1; i++ )
            {
                for( int j = 1; j < c2; j++ )
                {
                    cout << distt[i][j] << " ";
                }
                cout << endl;
            }*/
        while( l <= r )
        {
            int m = (l+r)/2;
            for( int i = 1; i <= c1+c2; i++ ) edge[i].clear();
            for( int i = 1; i < c1; i++ )
            {
                for( int j = 1; j < c2; j++ )
                {
                    if( distt[i][j]*2+2 <= m )
                    {
                        edge[i].pb( n+j );
                        edge[n+j].pb(i);
                    }
                }
            }
            int d = hopcroft_karp();
            if( d == c2-1 )
            {
                r = m -1;
                ans = m;
            }
            else
                l = m+1;
        }
        if( ans == -1 )
        {
            printf("Case %d: Vuter Dol Kupokat\n", caseno++);
        }
        else
        {
            printf("Case %d: %d\n",caseno++, ans);
        }
    }
    //while(1);
    return 0;
}
