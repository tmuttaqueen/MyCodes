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
const int M = 20678;

vector<int>edge[M];
intl n, a, b;
intl ans, sz[M];

void dfs(int u, int p)
{
    sz[u] = 1;
    intl s = (n-1)*(n-1), d = n-1;
    for( int x: edge[u] )
    {
        if(x==p) continue;
        dfs(x, u);
        s -= sz[x]*sz[x];
        d -= sz[x];
        sz[u] += sz[x];
    }
    s -= d*d;
    ans = max(ans,s );
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t , caseno = 1;
    cin >> t;
    while(t--)
    {
        ans = 0;
        cin >> n;
        for( int i = 1; i < n; i++ )
        {
            cin >> a >> b;
            edge[a].pb(b);
            edge[b].pb(a);
        }
        dfs(1, - 1);
        ans /= 2;
        cout << "Case #" << caseno++ << ": " << ans << endl;
        for( int i = 1; i <= n;i++ ) edge[i].clear();
    }
    return 0;
}
