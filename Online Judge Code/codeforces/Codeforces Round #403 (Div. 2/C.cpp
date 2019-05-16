#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

vector<int>edge[200005];
int col[200006];
int par[200006];

int maxcol = 3;

void dfs( int u, int p )
{
    //cout << u << " " << p << endl;
    int c = 1;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        c++;
        int v = edge[u][i];
        if( v != p )
        {
            dfs( v, u );
            par[v] = u;
        }
    }
    //if(p != -1) c++;
    maxcol = max( maxcol, c );
}

void color( int u, int p )
{
    int s = 1;
    if( u == 1 ) s = 2;
    if( p != -1 && col[p] == s ) s++;

    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        //what_is(v);

        if( v != p )
        {
            if( u != -1 && col[u] == s ) s++;
            if( p != -1 && col[p] == s ) s++;
            if( u != -1 && col[u] == s ) s++;
            if( p != -1 && col[p] == s ) s++;
            if( s > maxcol ) while(1);
            col[v] = s++;

            color( v, u );
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
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
    par[1] = -1;
    dfs(1, -1);
    col[1] = 1;
    color(1,-1);
    cout << maxcol << endl;
    for( int i = 1; i <= n; i++ ) cout << col[i] << " ";
    cout << endl;
    return 0;
}




