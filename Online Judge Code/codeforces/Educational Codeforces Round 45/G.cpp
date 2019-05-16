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
const int M = 200005;
vector<int>val[M], node[M], edge[M];
int flag[M];
intl cnt[M], mu[M], ans[M];

intl dfs( int u, int p )
{
    flag[u] = 0;
    intl tot = 1;
    for( int v: edge[u] )
    {
        if( flag[v] == 0 || v == p ) continue;
        tot += dfs(v, u);
    }
    return tot;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, a;
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        cin >> a;
        val[a].pb(i);
    }
    for( int i = 1; i < n; i++ )
    {
        int a, b;
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    mu[1] = 1;
    for( int i = 1; i <= 200000; i++ )
    {
        for( int j = i; j <= 200000; j+=i )
        {
            if( j > i ) mu[j] -= mu[i];
            for( int x: val[j] )
            {
                node[i].pb( x );
            }
        }
    }
    memset( flag, 0, sizeof flag );
    for( int i = 1; i <= 200000; i++ )
    {
        for( int x: node[i] )
        {
            flag[x] = 1;
        }
        for( int x : node[i] )
        {
            if( flag[x] == 1 )
            {
                intl c = dfs(x, -1);
                cnt[i] += (c*(c-1)/2 + c);
            }
        }
    }
    for( int i = 200000; i >= 1; i-- )
    {
        for( int j = 1; j*i <= 200000; j++ )
        {
            ans[i] += mu[j]*cnt[i*j];
        }
    }
    for( int i = 1; i <= 200000; i++ )
    {
        if( ans[i] > 0 )
            cout << i << ' ' << ans[i] << endl;
    }

    return 0;
}
