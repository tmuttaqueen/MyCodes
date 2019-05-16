#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl       long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<intl, intl>
#define piii        pair<pii, intl>
#define double      long double

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

const intl mx = 111111;
map<intl,intl> mm[mx];
intl col[mx];
vector<intl>edge[mx];
intl sz[mx];
intl sum[mx];
intl dom[mx];

void dfs( intl u, intl p )
{
    sz[u] = 1;
    intl val = 0, ind = u;
    dom[u] = 1;
    sum[u] = col[u];
    mm[u][ col[u] ] = 1;
    for( intl v: edge[u] )
    {
        if( v != p )
        {
            dfs( v, u );
            if( sz[v] > val )
            {
                val = sz[v];
                ind = v;
            }
            sz[u] += sz[v];
        }
    }
    //swap( mm[ind], mm[u] );
    mm[u].swap( mm[ind] );
    sum[u] = sum[ind];
    dom[u] = dom[ind];
    //what_is(u);
    //what_is( dom[u] );
    //what_is( sum[u] );
    for( intl v: edge[u] )
    {
        if( v != p )
        {
            for( map<intl,intl>::iterator it = mm[v].begin(); it != mm[v].end(); it++ )
            {
                //cout << u << " " << v << " " << it->xx << " " << it->yy << endl;
                mm[u][ it->xx ] += it->yy;
                if( mm[u][ it->xx ] > dom[u] )
                {
                    dom[u] = mm[u][ it->xx ];
                    sum[u] =  it->xx;
                }
                else if( mm[u][ it->xx ]  == dom[u] )
                {
                    sum[u] +=  it->xx ;
                }
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n;
    cin >> n;
    for( intl i = 1; i <= n; i++ ) cin >> col[i];
    for( intl i = 1; i < n; i++ )
    {
        intl a, b;
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dfs( 1, -1 );
    for( intl i = 1; i <= n; i++ )
    {
        cout << sum[i] << " ";
    }
    return 0;
}




