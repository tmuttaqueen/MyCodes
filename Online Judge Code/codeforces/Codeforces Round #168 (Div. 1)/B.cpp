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
#define double      long double

//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

intl val[111111];
vector<int>edge[111111];
intl ara[111111][2]; //0-dec, 1 = inc

void dfs( int u, int p )
{
    intl mn = 0, mx = 0;
    for( int x: edge[u] )
    {
        if( x != p )
        {
            dfs(x,u);
            mn = max( mn, ara[x][0] );
            mx = max( mx, ara[x][1] );
        }
    }
    //what_is(u);
    //what_is(mn);
    //what_is(mx);
    val[u] += mx - mn;
    if( val[u] < 0 )
        mx += abs(val[u]);
    else
        mn += abs(val[u]);
    ara[u][0] = mn;
    ara[u][1] = mx;

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    for( int i = 1; i < n; i++ )
    {
        int a, b;
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    for( int i = 1; i <= n; i++ )
    {
        cin >> val[i];
    }
    dfs(1,-1);
    cout << ara[1][0] + ara[1][1] << endl;

    return 0;
}
