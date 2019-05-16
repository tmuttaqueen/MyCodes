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
const int mx = 1111111;
vector<int>edge[mx];
int fl[mx], ara[mx];
vector<int>group[mx];
vector<int>ind[mx];
int c = 0;
int ans[mx];

void dfs( int u )
{
    fl[u] = 1;
    group[c].pb( -ara[u] );
    ind[c].pb( u );
    for( int v: edge[u] )
    {
        if( fl[v] == 0  )
        {
            dfs(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, q, a , b;
    cin >> n >> q;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
    }

    for( int i = 0;i < q; i++ )
    {
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }

    for( int i = 1; i <= n; i++ )
    {
        if( fl[i] == 0 )
        {
            dfs(i);
            c++;
        }
    }
    //debug;
    for( int i = 0; i < c; i++ )
    {
        sort( group[i].begin(), group[i].end() );
        sort( ind[i].begin(), ind[i].end() );
    }

    for( int i = 0; i < c; i++ )
    {
        for( int j = 0; j < group[i].size(); j++ )
        {
            ans[ ind[i][j] ] = - group[i][j];
        }
    }

    for( int i = 1; i <= n; i++ )
    {
        cout << ans[i] << " ";
    }

    return 0;
}




