#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

const int mx = 10005;

int n;
int depth[mx], par[mx], child[mx];//, par_child_cost[mx];
vector<int>edge[mx], cost[mx];
pii edge_list[mx];
int base_arr_node[mx], base_arr_val[mx], pos_in_base_arr[mx], chain_no[mx], chain_head[mx];
int c, chain;
int lca[20][mx];
int tree[4*mx];

///LCA O(logn)
//create par[] = parent of a vertex via dfs,
//create depth[] = level of a vertex from root via dfs
const int factor = 18;
void create_lca( int par[], int n ) // n is number of vertex
{
    for( int i = 0; i <= n; i++ )
        lca[0][i] = par[i];
    for( int j = 1; j <= factor; j++ )
    {
        for( int i = 0; i <= n; i++ )
        {
            if( lca[j-1][i] != -1 )
                lca[j][i] = lca[j-1][ lca[j-1][i] ];
        }
    }
}

int find_lca( int u, int v )
{
    if( depth[u] < depth[v] )//after this u is deeper than v
    {
        int t = u;
        u = v;
        v = t;
    }
    int diff = depth[u] - depth[v];
    int c = 0;
    while( diff > 0 )
    {
        if( diff&1 )
            u = lca[c][u];
        diff/=2;
        c++;
    }
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
///

void dfs( int u )
{
    //what_is(u);
    child[u] = 1;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( par[v] == -1 )
        {
            par[v] = u;
            //par_child_cost[v] = cost[u][i];
            depth[v] = depth[u] + 1;
            dfs(v);
            child[u] += child[v];
        }
    }

}



void hld( int u, int val = -1 )
{
    if( chain_head[chain] == -1 )
    {
        chain_head[chain] = u;
    }
    chain_no[u] = chain;
    pos_in_base_arr[u] = c;
    base_arr_node[c] = u;
    base_arr_val[c] = val;
    c++;
    int special = -1, value;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( v != par[u] && (special == -1 || child[v] > child[special])  )
        {
            special = v;
            value = cost[u][i];
        }
    }
    if( special != -1 )
    {
        hld(special, value);
    }

    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( v != par[u] && v != special )
        {
            chain++;
            hld( v, cost[u][i] );
        }
    }
}

///segment tree O(logn)
//base array is base_arr_val[], tree array is tree[]

void build( int cn, int s, int e )
{
    if( s == e )
    {
        tree[cn] = base_arr_val[s];
        //cout << cn << " tree cn " << tree[cn] << endl;
        return;
    }
    int m = (s+e)/2;
    build( cn*2, s, m );
    build( cn*2 + 1, m+1, e );
    tree[cn] = max( tree[cn*2], tree[cn*2+1] );
    //cout << cn << " tree cn " << tree[cn] << endl;
    return;
}

void update( int cn, int s, int e, int v, int val )
{
    if( s > v || e < v )
        return;
    if( s == e && v == s )
    {
        tree[cn] = val;
        base_arr_val[v] = val;
        return;
    }
    int m = (s+e)/2;
    update( cn*2, s, m, v, val );
    update( cn*2 + 1, m+1, e, v, val );
    tree[cn] = max( tree[cn*2], tree[cn*2+1] );
    //cout << cn << " tree cn " << tree[cn] << endl;
    return;
}

int query( int cn, int s, int e, int i, int j )
{
    if( s > j || e < i )
        return -1;
    if( s >= i && e <= j )
        return tree[cn];
    int m = (s+e)/2;
    int a = query( cn*2, s, m, i, j );
    int b = query( cn*2 + 1, m+1, e, i, j );
    return max(a,b);
}

int tree_query( int a, int b )
{
    int ans = -1;
    //cout << "a " << a << " b " << b << endl;
    //while(1);
    while( chain_no[a] != chain_no[b] )
    {
        int t = chain_head[chain_no[a]];
        //debug;
        int s = query(1,1,n, pos_in_base_arr[t], pos_in_base_arr[a] );
        ans = max(s,ans);
        a = par[t];
        //cout << "a " << a << " b " << b << " t " << t << endl;
    }
    if( a != b )
    {
        //what_is(pos_in_base_arr[b]);
        //what_is(pos_in_base_arr[a]);
        int s = query(1,1,n, pos_in_base_arr[b]+1, pos_in_base_arr[a] );
        ans = max(s,ans);
    }
    return ans;
}


int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t = 1;
    scanf("%d", &t);
    while(t--)
    {
        getchar();
        scanf("%d", &n);

        memset( child, 0, sizeof child );
        memset( depth, 0, sizeof depth );
        memset( par, -1, sizeof par );
        memset( chain_head, -1, sizeof chain_head );
        c = 1;
        chain = 1;
        for( int i = 0; i <= n; i++ )
        {
            edge[i].clear();
            cost[i].clear();
        }

        for( int i = 1; i < n; i++ )
        {
            int a, b, w;
            scanf( "%d %d %d", &a, &b, &w );
            edge[a].pb(b);
            edge[b].pb(a);
            cost[a].pb(w);
            cost[b].pb(w);
            edge_list[i] = mp(a,b);
        }
        par[1] = 1;
        dfs(1);
        /*for( int i = 1; i <= n; i++ )
        {
            cout << i << ": child: " << child[i] << " depth: " << depth[i] << " par: " << par[i] << endl;
        }*/
        create_lca(par,n);
        /*for( int j = 0; j <= 2; j++ )
        {
            for( int i = 1; i <= n; i++ )
            {
                cout << i << " " << j << " par " << lca[j][i] << endl;
            }
        }*/
        hld(1);
        /*for( int i = 1; i <= n; i++ )
        {
            cout << i << ": posinbase: " << pos_in_base_arr[i] << " chain no: " << chain_no[i] << " chain head: " << chain_head[chain_no[i]] << endl;
        }
        for( int i = 1; i <= n; i++ )
        {
            cout << i << ": basenode: " << base_arr_node[i] << " base_val: " << base_arr_val[i] << endl;
        }*/
        build(1,1,n);
        char str[10];
        while(1)
        {
            getchar();
            scanf("%s", str);
            if( str[0] == 'D' )
                break;
            if( str[0] == 'Q' )
            {
                int x, y;
                scanf("%d %d", &x, &y);
                if( x == y )
                {
                    printf("0\n");
                    continue;
                }
                int v = find_lca(x,y);
                //what_is(v);
                int s1 = tree_query(x,v);
                //what_is(s1);
                int s2 = tree_query(y,v);
                //what_is(s2);
                printf("%d\n", max(s1,s2));

            }
            else
            {
                int x, y, a, b;
                scanf("%d %d", &x, &y);
                a = edge_list[x].xx;
                b = edge_list[x].yy;
                if( par[a] == b )
                {
                    //what_is(a);
                    update( 1, 1, n, pos_in_base_arr[a], y );
                }
                else if( par[b] == a )
                {
                    //what_is(b);
                    update( 1, 1, n, pos_in_base_arr[b], y );
                }
            }
        }

    }

    return 0;
}




