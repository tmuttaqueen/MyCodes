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
#define pii         pair<intl, intl>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 34567;
vector<intl>edge[M], cost[M];
intl dist[M], ans[M], maxdist[M];
intl n, e, x, mx;

void dijktra( intl u )
{
    priority_queue<pii> pq;
    pq.push( mp(0,u) );
    memset( dist, 125, sizeof dist );
    dist[u] = 0;
    while( !pq.empty() )
    {
        pii a = pq.top();
        pq.pop();
        for( int i = 0; i < edge[a.yy].size(); i++ )
        {
            intl v = edge[a.yy][i], w = cost[a.yy][i];
            if( dist[v] > dist[a.yy]+w )
            {
                dist[v] = dist[a.yy]+w;
                pq.push( mp(-dist[v], v) );
            }
        }

    }

}

int solve( intl u, intl lim )
{
    priority_queue<pii> pq;
    pq.push( mp(0,u) );
    for( int i =1; i <= n; i++ )
    {
        ans[i] = 1000000000000000000LL;
    }
    ans[1] = 0;
    while( !pq.empty() )
    {
        pii a = pq.top();
        pq.pop();
        for( int i = 0; i < edge[a.yy].size(); i++ )
        {
            intl v = edge[a.yy][i], w = cost[a.yy][i];
            if( w > lim ) continue;
            if( ans[v] > ans[a.yy]+w )
            {
                ans[v] = ans[a.yy]+w;
                pq.push( mp(-ans[v], v) );
            }
        }
    }
    return ans[n] <= dist[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    intl a, b, c;
    cin >> n >> e >> x;
    for( int i = 0; i < e; i++ )
    {
        cin >> a >> b >> c;
        edge[a].pb(b);
        cost[a].pb(c);
        edge[b].pb(a);
        cost[b].pb(c);
    }
    dijktra(1);
    for( int i =1; i <= n; i++ )
    {
        dist[i] = (1+x/100.0)*dist[i];
    }
    intl l = 0, r = 1000000000, ans = -1;
    while( l <= r )
    {
        intl m = (l+r)/2;
        int f = solve( 1, m );
        if(f)
        {
            ans = m;
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }

    cout << ans << endl;

    return 0;
}
