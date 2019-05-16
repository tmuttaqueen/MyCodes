#include <cstdio>
#include<iostream>
#include<vector>
#include<cstring>
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
#define INT_MAX     1000000005

namespace HLD
{
const int LOG = 18, MAX = 100005;
int lca[LOG][MAX];
int dist[MAX], par[MAX], depth[MAX];
int n, root;
vector<int>edge[MAX];
int chain, cur;
int sz[MAX], //size of subtree of 'u'
    chainNo[MAX], //In what chain is the vertex 'u' in
    chainLen[MAX], //Length of a 'chain'
    posChain[MAX], //position of 'u' in a chain-1 based
    chainHead[MAX], //Head of a 'chain'
    ind[MAX]; //position of vertex 'u' in mapped hld array

///call it everytime for initializing the HLD process before adding edge
///v = total vertex, r = root
void init( int v, int r = 1 )
{
    n = v;
    root = r;
    dist[root] = 0;
    depth[root] = 0;
    chain = 1;
    cur = 1;
    for( int i = 1; i <= n; i++ )
    {
        chainLen[i] = 0;
        edge[i].clear();
    }
}

/************** ESSENTIAL PART OF HLD START ****************/

void addEdge( int a, int b )
{
    edge[a].push_back(b);
    edge[b].push_back(a);
}
///after creating the tree call it
///hidden step, called in create lca
void dfs( int u, int p )
{
    sz[u] = 1;
    if( p != -1 )
    {
        dist[u] = dist[p] + 1; //if needed change weight
        depth[u] = depth[p] + 1;
    }
    par[u] = p;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( p != v )
        {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

/************** ESSENTIAL PART OF HLD END ****************/

/************** LCA PART OF HLD START ********************/

///1st step of HLD call it first
void create_lca()
{
    dfs(1, -1);
    for( int i = 1; i <= n; i++ )
        lca[0][i] = par[i];
    for( int p = 1; p < LOG; p++ )
    {
        for( int v = 1; v <= n; v++ )
        {
            if( lca[p-1][v] != -1 )
                lca[p][v] = lca[p-1][ lca[p-1][v] ];
            else
                lca[p][v] = -1;
        }
    }
}

///return the child below the LCA in
///order by passing the nodes to function
pair<int,int> find_lca( int a, int b ) /// u, v
{
    int f = 0;
    if( depth[a] < depth[b] )
    {
        f = 1;
        swap(a,b);
    }
    int d = depth[a] - depth[b], c = 0;
    int temp = d, v = a;
    while( d > 0 )
    {
        if( d&1 )
            a = lca[c][a];
        d >>= 1;
        c++;
    }
    if( a == b)
    {
        a = v;
        d = temp-1;
        c = 0;
        while( d > 0 )
        {
            if( d&1 )
                a = lca[c][a];
            d >>= 1;
            c++;
        }
        //-1 indicates that b is an ancestor of a
        //for vertex HLD use path (u, par[xx] ), u is highest depth vertex
        //for edge HLD use path (u, xx), u is highest depth vertex
        return mp(a, -1);
    }
    for( int i = LOG-1; i >= 0; i--  )
    {
        if( lca[i][par[a]] != lca[i][par[b]] )
        {
            a = lca[i][a];
            b = lca[i][b];
        }
    }
    //for vertex HLD use path (u, par[xx] ), (v, par[v])
    //for edge HLD use path(u, xx), (v, yy)
    if( par[a] != par[b] )
    {
        if(f) return mp( par[b], par[a] );
        else return mp( par[a], par[b] );
    }
    if( f ) return mp(b,a);
    else return mp(a,b);
}

/************** LCA PART OF HLD END ****************/

/************** CREATING HLD **********************/
///2nd step of HLD call it second
///call it with root from main
void create_hld( int u )
{
    ind[u] = cur++;
    chainNo[u] = chain;
    chainLen[chain]++; //memset it for multiple test case
    posChain[u] = chainLen[chain];
    int maxSize = -1, maxV = -1;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( v == par[u] ) continue;
        if( maxSize < sz[v] )
        {
            maxV = v;
            maxSize = sz[v];
        }
    }
    if( maxV != -1 )
        create_hld( maxV );
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( v == par[u] || v == maxV ) continue;
        chain++;
        chainHead[chain] = v;
        create_hld(v);
    }
}

/***************** HLD CREATION END *******************/


/************** SEGMENT TREE START *******************/
int data[MAX]; // value of mapped vertex
int tree[4*MAX];
int lazy[4*MAX];
void init_tree( int cn, int s, int e )
{
    //cout << "tree: " << cn << " " << s << "-" << e << endl;
    lazy[cn] = INT_MAX;
    if( s == e )
    {
        tree[cn] = data[s];
        return;
    }
    int m = (s+e)/2, l = cn<<1;
    init_tree( l, s, m );
    init_tree( l+1, m+1, e );
    tree[cn] = min( tree[l], tree[l+1] );

}

void propagate( int cn, int s, int e )
{
    tree[cn] = min( tree[cn], lazy[cn] );
    if( s != e )
    {
        int l = cn<<1;
        lazy[l] = min( lazy[l], lazy[cn] );
        lazy[l+1] = min( lazy[l+1], lazy[cn] );
    }
    lazy[cn] = INT_MAX;
}

void update_tree( int cn, int s, int e, int x, int y, int v )
{
    //cout << "upd: " << cn << " " << s << " " << e << " " << x << " " << y << " " << v << endl;
    if( lazy[cn] != INT_MAX )
        propagate(cn, s, e);
    if( e < x || s > y ) return;
    if( s >= x && e <= y )
    {
        lazy[cn] = min( v, lazy[cn] );
        propagate(cn, s, e);
        //cout << "in: " << cn << " " << tree[cn] << endl;
        return;
    }
    int m = (s+e)/2;
    update_tree( cn<<1, s, m, x, y, v );
    update_tree( (cn<<1)+1, m+1, e, x, y, v );
    tree[cn] = min(tree[cn<<1],tree[ (cn<<1)+1 ]);
    return;
}

int query_tree( int cn, int s, int e, int x )
{
    //cout << "q: " << cn << " t " << tree[cn] << " " << s << " " << e << " " << x << endl;
    if( lazy[cn] != INT_MAX )
        propagate(cn, s, e);
    if( s == e )
    {
        return tree[cn];
    }
    int m = (s+e)/2;
    if( x <= m )
        return query_tree( cn<<1, s, m, x );
    else
        return query_tree( (cn<<1)+1, m+1, e, x );
}

/**************** SEGMENT TREE END ******************/

/**************** QUERY AND UPDATE START ************/

void update_up( int x, int p, int v )
{
    while(1)
    {
        if( chainNo[x] == chainNo[p] )
        {
            //cout << p << " " << ind[p] << " " << x << " " << ind[x] << " " << v << endl;
            update_tree( 1, 1, n, ind[p], ind[x], v );
            break;
        }
        else
        {
            //cout << p << " " << ind[p] << " " << x << " " << ind[x] << " " << v << endl;
            int l = ind[x] - posChain[x] + 1, r = ind[x];
            update_tree( 1, 1, n, l, r, v );
            x = par[chainHead[ chainNo[x] ]];
        }
    }
}

void update( int x, int y, int v )
{
    pii p = HLD::find_lca(x, y);
    //cout << p.xx << " " << p.yy << " " << x << " " << y << endl;
    if( p.yy == -1 )
    {
        if( depth[x] < depth[y] ) x = y;
        update_up( x, p.xx, v );
    }
    else
    {
        update_up( x, p.xx, v );
        update_up( y, p.yy, v );
    }
}

int query( int x, int y )
{
    if( par[x] == y )
        return query_tree(1, 1, n, ind[x]);
    return query_tree(1, 1, n, ind[y]);
}
/*************************** QUERY AND UPDATE END ********************/
}

const int MAX = 100005;
pii ara[MAX];

int main()
{
    //freopen("input.txt", "r", stdin);
    freopen("disrupt.in", "r", stdin);
    freopen("disrupt.out", "w", stdout);
    int t, caseno = 1;
    t = 1;
    while(t--)
    {
        int a, b, n, w, m;
        //cin >> n;
        scanf("%d %d", &n, &m);
        HLD::init( n );
        for( int i = 1; i < n; i++ )
        {
            //cin >> a >> b >> w;
            scanf("%d %d", &a, &b);
            ara[i] = mp(a,b);
            HLD::addEdge( a, b );
        }
        //cout << "ok" << endl;
        HLD::create_lca();
        HLD::create_hld(1);
        for( int i = 1; i <= n; i++ )
        {
            //cout << "H: " << i << " " << HLD::ind[i] << endl;
            HLD::data[i] = INT_MAX;
        }
        HLD::init_tree(1, 1, n);
        //cout << "bal" << HLD::query(4,5) << endl;
        for( int i = 1; i <= m; i++ )
        {

            scanf("%d %d %d", &a, &b, &w);
            if( a == b ) continue;
            HLD::update(a, b, w);
        }

        for( int i =1; i < n; i++ )
        {
            //debug;
            int d = HLD::query( ara[i].xx, ara[i].yy );
            if( d != INT_MAX )
                printf("%d\n", d);
            else
                printf("-1\n");
        }

    }
    return 0;
}
