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

vector<int>edge[M];
int pos[M], sz[M], c = 1, arr[M];

pii tree[M*10];
int lazy[M*10], ara[M];

void dfs( int u, int p )
{
    sz[u] = 1;
    pos[u] = c++;
    for( int v: edge[u] )
    {
        if( v != p )
        {
            dfs( v, u );
            sz[u] += sz[v];
        }
    }
}


void init( int cn, int s, int e )
{
    if( s == e )
    {
        if( ara[s] == 0 ) tree[cn] = mp(1,0);
        else tree[cn] = mp(0,1);
        return ;
    }
    int m = (s+e)/2;
    init( cn*2, s, m );
    init( cn*2+1, m+1, e );
    tree[cn] = mp( tree[cn*2].xx+tree[cn*2+1].xx, tree[cn*2].yy+tree[cn*2+1].yy );
    return;
}

void propagate( int cn )
{
    if( lazy[cn]%2 == 1 )
    {
        swap( tree[cn].yy, tree[cn].xx );
        lazy[cn*2]++;
        lazy[cn*2+1]++;
    }
    lazy[cn] = 0;
}

void update( int cn, int s, int e, int x, int y )
{
    if( lazy[cn] > 0 )
    {
        propagate(cn);
    }
    if( s > y || e < x ) return ;
    if( s >= x && e <= y )
    {
        lazy[cn]++;
        propagate(cn);
        return;
    }
    int m = (s+e)/2, l = cn*2, r = cn*2+1;
    update( l, s, m, x, y );
    update( r, m+1, e, x, y );
    tree[cn] = mp( tree[l].xx+tree[r].xx, tree[l].yy+tree[r].yy );
    return;
}

int query( int cn, int s, int e, int x, int y )
{
    if( lazy[cn] > 0 )
    {
        propagate(cn);
    }
    if( s > y || e < x ) return 0;
    if( s >= x && e <= y )
    {
        return tree[cn].yy;
    }
    int m = (s+e)/2, l = cn*2, r = cn*2+1;
    int a = query( l, s, m, x, y );
    int b = query( r, m+1, e, x, y );
    return a+b;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, a;
    cin >> n;
    for( int i = 2; i <= n; i++ )
    {
        cin >> a;
        //edge[i].pb(a);
        edge[a].pb(i);
    }
    dfs(1, -1);
    for( int i = 1; i <= n; i++ )
    {
        cin >> arr[i];
        ara[ pos[i] ] = arr[i];
    }
    init(1, 1, n);
    int q;
    cin >> q;
    cin.ignore();
    string s;
    while(q--)
    {
        cin >> s;
        cin >> a;
        cin.ignore();
        if( s[0] == 'p' && s[1] == 'o' && s[2] == 'w' )
        {
            update( 1, 1, n, pos[a], pos[a]+sz[a]-1 );
        }
        else
        {
            int x = query( 1, 1, n, pos[a], pos[a]+sz[a]-1 );
            cout << x << endl;
        }
    }
    return 0;
}
