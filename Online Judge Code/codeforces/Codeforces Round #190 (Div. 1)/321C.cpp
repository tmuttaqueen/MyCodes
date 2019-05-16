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
vector<int>edge[M], cent[M];
int sz[M], mark[M], par[M];

void dfsSZ( int u, int p )
{
    sz[u] = 1;
    for( int v: edge[u] )
    {
        if( v == p || mark[v] ) continue;
        dfsSZ(v, u);
        sz[u] += sz[v];
    }
}
int cnt = 0;

int Centroid( int u, int p )
{
    cnt++;
    int mx = 0, node = -1;
    for( int v: edge[u] )
    {
        if( par[v] == 0 && sz[v] > mx )
        {
            mx = sz[v];
            node = v;
        }
    }
    if( mx <= sz[u]/2 )
    {
        par[u] = p;
        for( int v: edge[u] )
        {
            if( par[v] == 0 )
                Centroid(v, u);
        }
    }
    else
    {
        swap(sz[u], sz[node]);
        sz[u] = sz[node] - mx;
        Centroid(node, p);
    }
}

char ans[M];

void solve( int u, int p )
{
    for( int v: cent[u] )
    {
        if( v != p )
        {
            ans[v] = ans[u] + 1;
            solve(v, u);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    for( int i = 1; i < n; i++ )
    {
        int a, b;
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dfsSZ(1,-1);
    Centroid(1, -1);
    int root;
    for( int i = 1; i <= n; i++ )
    {
        if( par[i] != -1 )
        {
            cent[i].pb( par[i] );
            cent[par[i]].pb(i);
        }
        else
            root = i;
    }
    ans[root] = 'A';
    solve( root, -1 );
    for( int i =1; i <= n; i++ )
    {
        cout << ans[i] << " ";
    }
    //what_is(cnt);

    return 0;
}
