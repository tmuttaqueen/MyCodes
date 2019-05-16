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
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

vector<int>edge[111111];
int sz[111111];
intl ans[111111], c, m;

void dfs1( int u, int p )
{
    sz[u] = 1;
    for( int v: edge[u] )
    {
        if(v!= p)
        {
            dfs1(v,u);
            sz[u] += sz[v];
        }
    }
}

void dfs2( int u, int p )
{
    ans[c++] = u;
    m--;
    if(m==0)
    {
        return;
    }
    for( int v: edge[u] )
    {
        if( v== p )
            continue;
        if( m > sz[v] )
        {
            m -= sz[v];
        }
        else if( m > 0 )
        {
            dfs2(v,u);
        }
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    cin >> t;
    while(t--)
    {
        intl n, a, b;
        c = 0;
        cin >> n >> m;
        for( int i =1; i <= n; i++ )
        {
            edge[i].clear();
        }
        for( int i = 1; i < n; i++)
        {
            cin >> a >> b;
            edge[a].pb(b);
            edge[b].pb(a);
        }
        for( int i = 1; i <= n; i++ )
        {
            sort( edge[i].begin(), edge[i].end()  );
        }

        c = 0;
        intl ind = m/n;
        if( m%n )
        {
            ind++;
        }
        m -= n*(ind-1);

        dfs1( ind, -1 );
        dfs2(ind, -1);
        for( int i =0; i < c; i++ )
        {
            cout << ans[i] << " ";
        }
        cout << endl;

    }
    return 0;
}
