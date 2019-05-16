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

int deg[M];
vector<int>edge[M];
vector<int>ans;

void dfs( int u, int p )
{
    int f = 0;
    for( int v: edge[u] )
    {
        if(v== p) continue;
        f = 1;
        dfs(v, u);
    }
    if(f==0)
        ans.pb(u);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n;
    cin >> n;
    int a, b;
    for( int i = 1; i < n; i++ )
    {
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
        deg[a]++;
        deg[b]++;
    }
    int c = 0, nd = 1;
    for( int i = 1; i <= n; i++ )
    {
        if( deg[i] > 2 )
        {
            c++;
            nd = i;
        }
    }
    if(c>1)
    {
        cout << "No" << endl;
    }
    else
    {
        //what_is(nd);
        dfs(nd, -1);
        cout << "Yes" << endl;
        int t = 0;
        for( int v: ans )
        {
            if(v != nd) t++;
        }
        cout << t << endl;
        for( int v: ans )
        {
            if(v != nd)
            {
                cout << nd << " " << v << endl;
            }
        }
    }

    return 0;
}
