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
vector<int>flag[200005];
int inv[200005], mn = 1e9;

void dfs1( int u, int p )
{
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i], f = flag[u][i];
        if( v != p )
        {
            if( f == -1 ) inv[1]++;
            dfs1(v,u);
        }
    }
}

void dfs2( int u, int p )
{
    mn = min( mn, inv[u] );
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i], f = flag[u][i];
        if( v != p )
        {
            inv[v] = inv[u] + f;
            dfs2(v,u);
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
        flag[a].pb(1);
        edge[b].pb(a);
        flag[b].pb(-1);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    cout << mn << endl;
    for( int i = 1; i <= n; i++ )
    {
        if( inv[i] == mn )
            cout << i << " ";
    }

    cout << endl;

    return 0;
}




