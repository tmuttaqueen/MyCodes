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

int col[312456];
vector<int>edge[M], from[M];
vector<pii>vec;
int in[M];
int t = 0, f = 0;
int dp[M][31];

void dfs( int u )
{
    t++;
    col[u] = 1;
    for( int v: edge[u] )
    {
        if( col[v] == 0 )
        {
            dfs( v );
        }
        else if( col[v] == 1 )
        {
            f = 1;
        }
    }
    col[u] = 2;
    t++;
    vec.pb( mp(t, u) );
}

char str[M];

int main()
{

    int n, m,a , b;
    scanf("%d %d\n", &n, &m);
    scanf("%s", str+1);
    for( int i = 0; i < m; i++ )
    {
        scanf("%d %d", &a, &b);
        edge[a].pb(b);
        from[b].pb(a);
        in[b]++;
    }
    for( int i = 1; i <= n; i++ )
    {
        if( in[i]  == 0 && col[i] == 0 )
        {
            dfs(i);
        }
    }
    for( int i = 1; i <= n; i++ )
    {
        if( col[i] == 0 )
        {
            cout << -1 << endl;
            return 0;
        }
    }
    if(f)
    {
        cout << -1 << endl;
        return 0;
    }
    sort( vec.begin(), vec.end() );
    reverse( vec.begin(), vec.end() );
    for( int i = 0; i < vec.size(); i++ )
    {
        int v = vec[i].yy;
        //cout << v << endl;
        for( int u: from[v] )
        {
            for( int i  = 0; i < 26; i++ )
            {
                dp[v][i] = max( dp[v][i], dp[u][i] );
            }
        }
        dp[v][ str[v] - 'a' ]++;
    }
    int ans = 0;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 0; j < 26; j++ )
        {
            ans = max( ans, dp[i][j] );
        }
    }
    cout << ans << endl;

    return 0;
}
