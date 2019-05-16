#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>

vector<int>edge[50005];
vector<int>cost[50005];
int v, e;
int rmq[50005][20], lca[50005][20], level[50005], depth;
bool visited[50005];

int find_par( int x, int par[] )
{
    if( par[x] == x ) return x;
    return par[x] = find_par( par[x], par );
}

bool comp( piii a, piii b )
{
    return a.yy < b.yy;
}

void kruskal()
{
    int par[v+5], taken = 0;
    for( int i = 1; i <= v; i++ ) par[i] = i;
    piii road[e+5];
    for( int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &road[i].xx.xx, &road[i].xx.yy, &road[i].yy );
    }
    sort( road, road+e, comp );
    for( int i = 0; i < e && taken < v; i++ )
    {
        int pa = find_par( road[i].xx.xx, par ), pb = find_par( road[i].xx.yy, par );
        if( pa != pb )
        {
            //cout << road[i].xx.xx << " " <<  road[i].xx.yy << " " <<  road[i].yy << endl;
            par[pa] = pb;
            edge[road[i].xx.xx].pb( road[i].xx.yy );
            edge[road[i].xx.yy].pb( road[i].xx.xx );
            cost[road[i].xx.xx].pb( road[i].yy );
            cost[road[i].xx.yy].pb( road[i].yy );
            taken++;
        }
    }
}

void dfs( int u )
{
    //cout << "vertex  " << u << endl;
    visited[u] = 1;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int x = edge[u][i];
        if( !visited[x] )
        {
            level[x] = level[u] + 1;
            lca[x][0] = u;
            rmq[x][0] = cost[u][i];
            dfs(x);
        }
    }
}

void process()
{
    for( int i = 1; i < 20; i++)
    {
        for( int j = 1; j <= 50000; j++)
        {
            if( lca[j][i-1] != -1)
               lca[j][i] = lca[ lca[j][i-1] ][i-1];
            else
               lca[j][i] = -1;
        }
    }

    for( int i = 1; i < 20; i++)
    {
        for( int j = 1; j <= 50000; j++)
        {
            if( lca[j][i-1] != -1)
               rmq[j][i] = max( rmq[ lca[j][i-1] ][i-1], rmq[j][i-1] );
            else
               rmq[j][i] = rmq[j][i-1];
        }
    }
}

int find_n_par( int u, int n )
{
    if( n == 0 )
        return u;
    int i = 0;
    while( n >= (1<<i) ) i++;
    i--;
    return find_n_par( lca[u][i], n - (1<<i) );
}

int common_lca( int x, int y )
{
    //cout << level[x] << " " << level[y] << endl;
    if( level[x] > level[y] )
        x = find_n_par( x, level[x] - level[y] );
    else if( level[x] < level[y] )
        y = find_n_par( y, level[y] - level[x] );
    if( x == y )
        return x;
    if( lca[x][0] == lca[y][0] )
        return lca[x][0];
    int i = 0;
    while( lca[x][i] != lca[y][i] ) i++;
    i--;
    return common_lca( lca[x][i], lca[y][i] );
}


int dist( int x, int y ) // maximum risk from x to its some parent  y
{
    if( x == y )
        return 0;
    if( lca[x][0] == y )
        return rmq[x][0];
    int n = level[x] - level[y];
    int i = 0;
    while( (1<<i) < n ) i++;
    i--;
    return max( rmq[x][i], dist( lca[x][i], y ) );
}


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &v, &e);
        kruskal();
        depth = 0;
        memset( visited, 0, sizeof(visited) );
        visited[1];
        memset( lca, -1, sizeof(lca) );
        memset( rmq, -1, sizeof(rmq) );
        level[1] = 0;
        dfs(1);
        process();
        //cout << find_n_par( 2, 1 ) << endl;
        //cout << common_lca(1, 2) << endl;
        //cout << dist( 3, 4 ) << endl;
        int q;
        scanf("%d", &q);
        printf("Case %d:\n", caseno++);
        while(q--)
        {
            int a, b, p;
            scanf("%d %d", &a, &b);
            p = common_lca(a, b);
            int ans = max( dist( a, p ), dist(b, p) );
            printf("%d\n", ans);
        }
        for( int i =0; i < 50005; i++ )
        {
            edge[i].clear();
            cost[i].clear();
        }
    }

    return 0;
}



