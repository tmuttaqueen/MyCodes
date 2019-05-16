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
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int SZ = 200005, mod = 1000000007;

int dist[SZ][2];
int dep[SZ];
vector<int>edge[SZ];
void dfs( int u, int p, int f )
{
     for( int v: edge[u] )
     {
         if( v != p )
         {
             dist[v][f] = dist[u][f] + 1;
             dfs( v, u, f );
             if( f == 0 )
             {
                 dep[u] = max( dep[u], dep[v]+1 );
             }
         }
     }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, x, a, b;
    cin >> n >> x;
    for( int i = 1; i < n; i++ )
    {
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dist[1][0] = 0;
    dist[x][1] = 0;
    dfs(1,-1,0);
    dfs(x,-1,1);
    int ans = 0;
    for( int i = 1; i <= n; i++ )
    {
        if( dist[i][0] > dist[i][1] )
        {
            ans = max(ans, dist[i][0] + dep[i] );
        }
    }
    cout << ans*2 << endl;
    return 0;
}




