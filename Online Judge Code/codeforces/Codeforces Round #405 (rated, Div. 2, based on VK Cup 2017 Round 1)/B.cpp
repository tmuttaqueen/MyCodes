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

int vis[200000];

vector<int>edge[200000];
intl s = 0;

void dfs( int u )
{
    //what_is(u);
    vis[u] = 1;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( vis[v] == 0 )
        {
            s++;
            dfs( v );
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, m;
    cin >> n >> m;
    for( int i = 0; i < m; i++ )
    {
        int a, b;
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    intl d = 0, sum = 0;
    for( int i = 1; i <= n; i++ )
    {
        if( vis[i] == 0 )
        {
            s = 1;
            dfs( i);
            sum += s*(s-1)/2;
        }
    }
    if( sum == m )
    {
        cout << "YES\n";
    }
    else
        cout << "NO\n";
    return 0;
}




