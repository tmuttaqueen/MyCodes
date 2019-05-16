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

intl val[300005];
intl child[300006][2], par[300005][2];//0=min,1=max
intl sub[300006][2], subpar[300005][2], all[300005][2];
vector<int>edge[300005];
int parent[300005];
intl ans = -1e18;

void dfs1( int u, int p )
{
    parent[u] = p;
    intl mn = val[u], mx = val[u], mnn = 0, mxx = 0;
    for( int v: edge[u] )
    {
        if( v != p )
        {
            dfs1(v,u);
            mn = min( mn, mn+child[v][0] );
            mx = max( mx, mx+child[v][1] );
            mnn = min( mnn, all[v][0] );
            mxx = max( mxx, all[v][1] );
        }
    }

    child[u][0] = mn;
    child[u][1] = mx;
    sub[u][0] = mnn;
    sub[u][1] = mxx;
    all[u][0]= min( child[u][0], sub[u][0] );
    all[u][1]= max( child[u][1], sub[u][1] );
}

void dfs2( int u, int p )
{
    for( int v: edge[u] )
    {
        intl mn = child[u][0], mx = child[u][1], mnn = 0, mxx = 0;
        if( v != p )
        {

            //what_is(ans);
            mn = max( mn, mn - child[v][0]);
            mx = min( mx, mx - child[v][1]);
            mn = min( mn, mn + par[p][0]);
            mx = max( mx, mx + par[p][1]);
            par[u][0] = mn;
            par[u][1] = mx;
            //cout << u << " -> " << v << endl;
            //cout << u << " " << v << " is " << mn << " " << child[v][0] << " n " << mx << " " << child[v][1] << endl;
            ans = max(ans, mn*all[v][0]);
            ans = max(ans, mx*all[v][1]);
            //what_is(ans);


            if( sub[u][1] == all[v][1] )
            {
                for( int x: edge[u] )
                    if( x != v && x != p )
                        mxx = max( mxx, all[x][1] );
            }
            else
                mxx = sub[u][1];

            mxx = max(mxx, par[p][1] );
            mxx = max(mxx, subpar[p][1] );
            //what_is(mxx);
            subpar[u][1] = mxx;
            ans = max( ans, mxx*all[v][1] );


            if( sub[u][0] == all[v][0] )
            {
                for( int x: edge[u] )
                    if( x != v && x != p )
                        mnn = min( mnn, all[x][0] );
            }
            else
                mnn = sub[u][0];

            mnn = min(mnn, par[p][0] );
            mnn = min(mnn, subpar[p][0] );

            subpar[u][0] = mnn;
            //what_is(mnn);
            ans = max( ans, mnn*all[v][0] );
            //what_is(ans);
            //cout << u << " " << v << " " << ans <<endl;
            dfs2(v,u);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ ) cin >> val[i];
    for( int i = 1; i < n; i++ )
    {
        int a, b;
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dfs1(1,0);
    //for( int i = 1; i <= n; i++ ) cout << i << " is " << child[i][0] << " " << child[i][1] << " : " << all[i][0] << " " << all[i][1] << endl;
    dfs2(1,0);
    cout << ans << endl;
    return 0;
}




