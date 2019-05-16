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

///DIJKSTRA SHORTEST PATH O(elogv)
//a structure for maintaining priority queue
int k;
int cnt[111];
vector<int>eg[111];
vector<int>cost[111];
int path[111][15];


struct edg
{
    int a, w;
    edg( int x, int y )
    {
        a = x;
        w = y;
    }
    bool operator<( const edg &x )const
    {
        return w > x.w;
    }
};
priority_queue<edg>pq;
//s = source, eg = edge list, cost = cost of a edge, path = shortest distance keeper from source
void dijkstra( int s )
{
    for( int i = 0; i <= 100; i++ )
    {
        cnt[i] = 1;
        for( int j = 0; j <= 12; j++ )
        {
            path[i][j] = 1e9;
        }
    }
    while( !pq.empty() )
        pq.pop();
    pq.push( edg(s,0) );

    while( !pq.empty()  )
    {
        edg x = pq.top();
        //cout << x.a << " " << x.w << " " << cnt[x.a] << endl;
        path[x.a][ cnt[x.a]++ ] = x.w;
        pq.pop();
        if( x.w > path[x.a][ cnt[x.a] ] || cnt[x.a] > k )
            continue;
        for( int i = 0; i < eg[x.a].size(); i++ )
        {
            int v = eg[x.a][i], cst = cost[x.a][i];
            if( cnt[v] <= k) //x.w + cst < path[v][ cnt[v] ] )
            {
                path[v][ cnt[v] ] = x.w + cst;
                pq.push( edg(v,x.w + cst) );
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t;
    int n,m;
    while(1)
    {
        cin >> n >> m;
        if( n ==0 && m == 0 )
            break;

        int x, y;
        cin >> x >> y >> k;
        for( int i = 0; i <= n; i++ )
        {
            eg[i].clear();
            cost[i].clear();
        }
        int a, b, w;
        for( int i = 0; i < m; i++ )
        {
            cin >> a >> b >> w;
            eg[a].pb(b);
            cost[a].pb(w);
        }
        dijkstra(x);
        if( path[y][k] == 1000000000 )
            cout << -1 << endl;
        else
            cout << path[y][k] << endl;
    }
    return 0;
}
