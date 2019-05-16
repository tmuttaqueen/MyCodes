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

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

map<int, int>mm;
vector<int>edge[33];

int bfs( int u, int c)
{
    int vis[33], dist[33];
    for( int i = 0; i < 33; i++ ) dist[i] = 100;
    memset( vis, 0, sizeof vis );
    queue<int>q;
    q.push( u );
    dist[u] = 0;
    while( !q.empty() )
    {
        int u = q.front();
        q.pop();
        for( int i = 0; i < edge[u].size(); i++ )
        {
            int v = edge[u][i];
            if( vis[v] == 0 )
            {
                dist[v] = dist[u] + 1;
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    int ans = 0;
    for( int i = 1; i < 33; i++ )
    {
        if( dist[i] <= c )
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t = 1;
    int rev[44];
    while(1)
    {
        int n, c = 1;
        cin >> n;
        if(n==0) break;
        mm.clear();
        for( int i = 0; i < 33; i++ ) edge[i].clear();
        for( int i = 0; i < n; i++ )
        {
            int a, b;
            cin >> a >> b;
            if( mm[a] == 0 )
            {
                mm[a] = c;
                rev[c] = a;
                a = c++;
            }
            if( mm[b] == 0 )
            {
                mm[b] = c;
                rev[c] = b;
                b = c++;
            }
            edge[a].pb(b);
            edge[b].pb(a);
        }
        while(1)
        {
            int a, b;
            cin >> a >> b;
            if(a==0 && b == 0) break;
            cout << "Case " << t++ << ": " <<  bfs( mm[a], b ) <<  " nodes not reachable from node "<< a << " with TTL = " << b << "." << endl;

        }
    }
    return 0;
}
