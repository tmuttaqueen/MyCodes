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

int n, x, y, a, b;

int cnt[M], mark[M];



void dfs( int u, int p, int cl, int col )
{
    mark[u] = col;
    cnt[u]++;
    for( int v: edge[u] )
    {
        if(v == p || v == cl) continue;
        dfs(v, u, cl, col);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    cin >>n >> x >> y;
    for( int i = 1; i < n; i++ )
    {

        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dfs(x, -1, y, 0);
    dfs(y, -1, x, 1);
    intl one = 0, two = 0;
    for( int i = 1; i <= n; i++ )
    {
        if( cnt[i] == 1 && mark[i] == 0 ) one++;
        else if( cnt[i] == 1 && mark[i] == 1  ) two++;
    }
    intl ans = 1LL*n*(n-1LL) - one*two;
    cout << ans << endl;
    return 0;
}
