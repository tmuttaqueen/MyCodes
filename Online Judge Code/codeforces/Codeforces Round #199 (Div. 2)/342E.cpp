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
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double
typedef struct touple
{
    int xx,yy,zz;
    touple( int x = 0, int y = 0, int z = 0 )
    {
        xx=x;
        yy=y;
        zz=z;
    }
    bool operator<(const touple &a )
    {
        if( xx == a.xx )
        {
            if( yy == a.yy )
                return zz < a.zz;
            return yy < a.yy;
        }
        return xx<a.xx;
    }

} tii;
//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;


const int M = 345678;
vector<int>edge[M];

//****************************************************LCA**************************************************

///LCA O(logn)
//create par[] = parent of a vertex via dfs,
//create dist[] = distance of a vertex from root via dfs
//lca[i][j] = 2^i th ancestor of vertex j
//1 based node counting
class LCA
{
    int factor;
    int **lca;
    int *dist;
    int n, root;
public:
    LCA(){}
    void setLCA( int vertex, int root = 1 )
    {
        n = vertex;
        this->root = root;
        factor = 19;
        lca = new int*[factor+1];
        for( int i = 0; i <= factor; i++ )
            lca[i] = new int[n+5];
        dist = new int[n+5];
    }
    void create( int par[], int level[] )
    {
        for( int i = 0; i <= n; i++ )
            dist[i] = level[i];
        par[root] = -1;
        preprocess( par );
    }
    void preprocess(int par[] )
    {
        for( int i = 0; i <= n; i++ )
            lca[0][i] = par[i];
        for( int j = 1; j <= factor; j++ )
        {
            for( int i = 0; i <= n; i++ )
            {
                if( lca[j-1][i] != -1 )
                    lca[j][i] = lca[j-1][ lca[j-1][i] ];
                else
                    lca[j][i] = -1;
            }
        }
    }
    int find_lca( int u, int v )
    {
        if( dist[u] < dist[v] )
            swap(u,v); //after this u is deeper than v
        int diff = dist[u] - dist[v];
        int c = 0;
        while( diff > 0 )
        {
            if( diff&1 )
                u = lca[c][u];
            diff >>= 1;
            c++;
        }
        if( v == u) return v;
        for( int i = factor; i >= 0; i--  )
        {
            if( lca[i][u] != lca[i][v] )
            {
                u = lca[i][u];
                v = lca[i][v];
            }
        }
        return lca[0][u];
    }
    int distance( int u, int v )
    {
        if( u < 1 || v < 1 || u > n || v > n ) return 0;
        int l = find_lca(u, v);
        return dist[u] + dist[v] - 2*dist[l];
    }
    ~LCA()
    {
        for( int i = 0; i <= factor; i++ ) delete[] lca[i];
        delete[] lca;
        delete[] dist;
    }
};

//************************************************************** LCA END ********************************************************


//************************************************************** CENTROID DECOMPOSITION ********************************************************

//sz[u] is size of subtree u in orginal tree
//par[u] is parent of u in centroid tree
//dist[u] is distance between u and par[u] in orginal tree
//repetedly calling distance function can be avoided be precalculation distance to i'th parent

int sz[M], par[M], parOrg[M];
int red[M], depth[M];
LCA lca;

//this dfs calculates the subtree sizes
void dfs( int u, int p )
{
    parOrg[u] = p;
    sz[u] = 1;
    for( int v: edge[u] )
    {
        if( v == p ) continue;
        depth[v] = depth[u] + 1;
        dfs(v,u);
        sz[u] += sz[v];
    }
    //cout << u << " : " << sz[u] << endl;
}

//finds the centroid tree
void centroid( int u, int p)
{
    int mx = 0, child = -1, nodesz = sz[u] ;
    //finding maximum subtree
    // par[v] == 0 means v is yet to add in centroid tree
    for( int v: edge[u] )
    {
        if( par[v] == 0 && sz[v] > mx )
        {
            mx = sz[v];
            child = v;
        }
    }
    //if child subtree size is greater than halfsize of subtree
    if( mx > nodesz/2 )
    {
        //subtree size modification
        sz[u] -= sz[child];
        sz[child] = sz[u] + sz[child];
        //here other operations should be performed
        //recursively find centroid tree
        centroid( child, p );
    }
    else
    {
        par[u] = p;
        for( int v: edge[u] )
        {
            if( par[v] == 0 )
            {
                centroid( v, u );
            }
        }
    }
}

void update( int u )
{
    int d = 0, p = u;
    while( p != -1 )
    {
        red[p] = min( d, red[p] );
        d = lca.distance(u, par[p] );
        p = par[p];
    }
}

int query( int u )
{
    int d = 0, p = u, ans = M*122;
    while( p != -1 )
    {
        ans = min( ans, d+red[p] );
        d = lca.distance(u, par[p] );
        p = par[p];
    }
    return ans;
}

//************************************************************** CENTROID DECOMPOSITION ********************************************************

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, a, b, m;
    memset( red, 125, sizeof red );
    //red[1] = 0;
    //red[5] = 0;
    cin >> n >> m;
    for( int i = 1; i < n; i++ )
    {
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    depth[1] = 0;
    dfs(1,-1);
    lca.setLCA(n,1);
    lca.create( parOrg, depth );
    centroid(1,-1);
    update(1);
    for( int i = 0; i < m; i++ )
    {
        cin >> a >> b;
        if( a == 1 )
        {
            update(b);
        }
        else
        {
            cout << query(b) << endl;
        }
    }
    return 0;
}
