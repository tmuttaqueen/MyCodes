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

int val[300005], ans = -1e9;
vector<int>edge[300005];

void dfs( int u, int p, int l )
{
    ans = max( ans, val[u] + min(2,l) );
    for( int v: edge[u] )
    {
        if( v != p )
        {
            dfs( v, u, l+1 );
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n,a ,b, mx = -1e9,c=0;
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        cin >> val[i];
        mx = max(mx,val[i] );
    }
    for( int i = 1; i < n; i++ )
    {
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    for( int i = 1; i <= n; i++ )
    {
        if( val[i] == mx ) c++;
    }
    if( c == 1 )
    {
        for( int i = 1; i <= n; i++ )
        {
            if( val[i] == mx )
                dfs( i, -1, 0 );
        }
        cout << ans << endl;
    }
    else
    {
        for( int i = 1; i <= n; i++ )
        {
            int d = 0;
            if( val[i] == mx ) d++;
            for( int u: edge[i] )
            {
                if( val[u] == mx )
                    d++;
            }
            if( d == c )
            {
                ans = mx+1;
                cout << ans << endl;
                return 0;
            }
        }
        cout << mx+2 << endl;
    }
    return 0;
}



