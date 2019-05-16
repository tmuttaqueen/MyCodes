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
const int M = 135678;

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
    //par is the parent array we get from traversing the tree
	//d is the distance array to all vertex from root
    void create( int *par, int *d = nullptr ) //creates binary power parent of tree
    {
        for( int i = 1; i <= n; i++ )
        {
            if( d != nullptr )
            {
                dist[i] = d[i];
            }
            else
                dist[i] = -1;
        }
        par[root] = -1;
		for( int i = 0; i <= n; i++ )
            lca[0][i] = par[i];
        for( int j = 1; j <= factor; j++ )
        {
            for( int i = 1; i <= n; i++ )
            {
                if( lca[j-1][i] != -1 )
                    lca[j][i] = lca[j-1][ lca[j-1][i] ];
                else
                    lca[j][i] = -1;
            }
        }
    }
  	//finds lca of vertex u and v
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
    //find distance between u and v
    int distance( int u, int v )
    {
        if( u < 1 || v < 1 || u > n || v > n )
			return 0; //modify return value as needed
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

vector<int>edge[M];
int chainNo[M], posChain[M], chainLen[M], chainHead[M], parent[M], Index[M], sz[M], dist[M];
LCA lca;
int tree[M*5], lazy[M*5];

void dfs( int u, int p )
{
    sz[u] = 1;
    parent[u] = p;
    if( p != -1 ) dist[u] = dist[p] + 1;
    else dist[u] = 1;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( v == p ) continue;
        dfs(v,u);
        sz[u] += sz[v];
    }
}

int c = 1, chain = 1;

void create_hld( int u )
{
    chainLen[chain]++;
    posChain[u] = chainLen[chain];
    chainNo[u] = chain;
    Index[u] = c++;
    int mx = -1, maxV = -1;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( v == parent[u] ) continue;
        if( sz[v] > mx )
        {
            mx = sz[v];
            maxV = v;
        }
    }
    if( maxV != -1 )
        create_hld(maxV);
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( v == parent[u] || v == maxV ) continue;
        chain++;
        create_hld(v);
    }
}

void propagate( int cn, int s, int e )
{
    tree[cn] += (e-s+1)*lazy[cn];
    if( s != e )
    {
        lazy[cn<<1] += lazy[cn];
        lazy[ (cn<<1)|1 ] += lazy[cn];
    }
    lazy[cn] = 0;
}

void update_tree( int cn, int s, int e, int x, int y, int v = 1 )
{
    //cout << x << " --- " << y << " -- " << v << nedl;
    if( lazy[cn] ) propagate( cn, s, e );
    if( e < x || s > y ) return;
    if( s >= x && e <= y )
    {
        lazy[cn] += v;
        propagate(cn,s,e);
        return;
    }
    int m = (s+e)/2;
    update_tree( cn<<1, s, m, x, y, v );
    update_tree( (cn<<1)+1, m+1, e, x, y, v );
    tree[cn] = tree[cn<<1] + tree[(cn<<1)+1];
    return;
}

int query_tree( int cn, int s, int e, int x )
{
    if( lazy[cn] ) propagate(cn,s,e);
    if( s > x || e < x ) return 0;
    if( s == e )
    {
        return tree[cn];
    }
    int m = (s+e)/2;
    int a = query_tree( cn<<1, s, m, x );
    int b = query_tree( (cn<<1)+1, m+1, e, x );
    return a+b;
}

int n;

void update_up( int x, int p )
{
    //cout << x << " -- " << p << endl;
    if( chainNo[x] == chainNo[p] )
    {
        update_tree( 1, 1, n, Index[p], Index[x] );
        return;
    }
    update_tree( 1, 1, n, Index[x]-posChain[x]+1, Index[x] );
    x = parent[x];
    update_up( x, p );
}

void update( int a, int b )
{
    int p = lca.find_lca(a,b);
    //cout << a << b << p << endl;
    update_up( a, p);
    update_up( b, p );
    update_tree( 1, 1, n, Index[p], Index[p], -2 );
}

int query( int x )
{
    return query_tree( 1, 1, n, Index[x] );
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int q;
    cin >> n >> q;
    for( int i =1, a, b; i < n; i++ )
    {
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dfs(1,-1);
    create_hld(1);
    //for( int i =1; i <= n; i++ ) cout << Index[i] << endl;
    lca.setLCA(n);
    lca.create(parent, dist);
    int a, b;
    char c;
    while(q--)
    {
        cin >> c >> a >> b;
        //cout << c << a << b << endl;
        cin.ignore();
        if( c == 'P' )
        {
            update( a, b );
        }
        else
        {
            if( parent[a] == b )
            {
                cout << query( a ) << endl;
            }
            else
                cout << query(b) << endl;
        }
    }
    while(1);
    return 0;
}
