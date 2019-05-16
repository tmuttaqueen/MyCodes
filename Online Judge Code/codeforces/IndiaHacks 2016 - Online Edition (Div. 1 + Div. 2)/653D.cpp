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
#define piii        pair<pii, int>
//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

struct Dinic
{
    struct edge
    {
        int ind, to, cap;
        bool isReal;
    };
    int s, t, V;
    int *level;
    bool *flag;
    vector<edge> *all;


    Dinic(int v = 10005)
    {
        this->V = v;
        flag = new bool[V];
        level = new int[V];
        all = new vector<edge>[V];
        for( int i = 0; i < V; i++ )
            all[i].clear();
    }
    void setGraph( int s, int t )  //source, destination
    {
        this->s = s;
        this->t = t;
    }
    void addEdge( int u, int v, int c) //from, to, capacity
    {
        all[u].push_back( { all[v].size() , v, c, true} );
        all[v].push_back( { all[u].size()-1 , u, 0, false} );
    }

    bool bfs( int u ) //source
    {
        level[u] = 0;
        queue<int>q;
        memset( flag, 0, V );
        flag[u] = 1;
        q.push(u);
        while( !q.empty() )
        {
            int u = q.front(); q.pop();
            for( int i = 0; i < all[u].size(); i++ )
            {
                int v = all[u][i].to, c = all[u][i].cap;
                if( c > 0 && flag[v] == 0 )
                {
                    flag[v] = 1;
                    level[v] = level[u]+1;
                    q.push(v);
                }
            }
        }
        return flag[t]; //is possible to go destination?
    }
    int augmentPath( int u, int f ) //node, flow so far
    {
        if( u == t ) return f;
        int tot = 0;
        for( int i = 0; i < all[u].size(); i++ )
        {
            int v = all[u][i].to, ind = all[u][i].ind, c = all[u][i].cap;
            if( level[v] == level[u]+1 && c > 0 )
            {
                int d = augmentPath( v, min( f, c ) );
                all[u][i].cap -= d;
                all[v][ind].cap += d;
                tot += d;
                f -= d;
                if( f <= 0 )
                    break;
            }
        }
        return tot;
    }

    int maxFlow()
    {
        int flow = 0;
        while( bfs( s ) )
        {
            flow += augmentPath(s, 2000000);
        }
        //to get mincut check flag here
        //to get flow per edge check capacity here
        return flow;
    }

    ~Dinic()
    {
        for( int i = 0; i < V; i++ )
            all[i].clear();
        delete[] all;
        delete[] flag;
        delete[] level;
    }

};

vector<piii>edge;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, m, x, a, b, c;
    cin >> n >> m >> x;
    for( int i = 0; i < m; i++ )
    {
        cin >> a >> b >> c;
        edge.pb( mp( mp(a,b), c ) );
    }
    double l = 0, r = 2000000;
    for( int i = 0; i <= 100; i++ )
    {
        double md = (l+r)/2.0;
        Dinic flow(n+5);
        flow.setGraph(1,n);
        //debug;
        for( int i = 0; i < m; i++ )
        {
            double d = min( (edge[i].yy/md), 10000000.0 );
            flow.addEdge( edge[i].xx.xx, edge[i].xx.yy, int(d) );
        }
        //debug;
        int d = flow.maxFlow();
        //what_is(d);
        //what_is(md);
        if( d >= x )
            l = md;
        else
            r = md;
    }
    double ans = (l+r)*x/2.0;
    cout << setprecision(10) << fixed << ans << endl;
    return 0;
}
