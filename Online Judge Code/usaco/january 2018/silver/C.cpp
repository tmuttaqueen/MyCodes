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
#define filein      freopen("mootube.in", "r", stdin)
#define fileout     freopen("mootube.out", "w", stdout)
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 5005;

int u[M], v[M], r[M];
vector<pii>edge[M];
int cnt, lim;

void dfs( int u, int p )
{
    cnt++;
    for( pii v: edge[u] )
    {
        if( v.xx == p ) continue;
        if( v.yy < lim ) continue;
        dfs(v.xx, u);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    filein;
    fileout;
    int n, q, u, v, r;
    cin >> n >> q;
    for( int i = 1; i < n; i++ )
    {
        cin >> u >> v >> r;
        edge[u].pb(mp(v, r));
        edge[v].pb(mp(u, r));
    }
    while(q--)
    {
        cnt = 0;
        int s;
        cin >> lim >> s;
        dfs(s, -1);
        cout << cnt-1 << endl;
    }
    return 0;
}
