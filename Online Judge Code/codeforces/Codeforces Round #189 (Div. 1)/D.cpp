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

const int mx = 111111;
int ara[mx], dp[mx], c = 0, st[mx];
vector<int>edge[mx];
int vis[mx];

void dfs( int u )
{
    if( edge[u].size() == 0 )
        dp[u] = 1;
    vis[u] = 1;
    for( int v: edge[u] )
    {
        if( vis[v] == 0 )
        {
            dfs( v );
            dp[u] += dp[v];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n;
    cin >> n;
    for( int i = 0; i < n; i++ ) cin >> ara[i];
    st[c++] = 0;
    for( int i = 1; i < n; i++ )
    {
        int d = ara[i];
        /*int l = 0, h = c-1, ans = -1;
        while( l <= h )
        {
            int m = (l+h)/2;
            if( ara[ st[m] ] >= d )
            {
                ans = m;
                l = m+1;
            }
            else
                h = m - 1;
        }
        cout << d << " " << ara[ans] << endl;
        if( ans != -1 )
            dp[ans]++;*/
        while( c > 0 && ara[ st[c-1] ] < d )
            c--;
        if( c > 0 )
            edge[ st[c-1] ].pb(i);
            //dp[st[c-1]]++;
        st[c++] = i;
        //cout << dp[i] << " ";
        //for( int i = 0; i < c; i++ ) cout << ara[st[i]] << " ";
        //cout << endl;
    }
    //debug;
    int ans = -1;
    //for( int i = 0; i < n; i++ ) cout << dp[i] << " ";
    for( int i = 0; i < n; i++ )
    {
        if( vis[i] == 0 )
        {
            dfs(i);
            what_is(i);
        }
    }
    for( int i = 0; i < n; i++ ) ans = max( ans, dp[i] );
    cout << ans << endl;
    return 0;
}




