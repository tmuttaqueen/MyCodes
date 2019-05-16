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

vector<pii>vec;

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int n, b, q, x, y;
    cin >> n >> b >> q;

    for( int i = 0; i < q; i++ )
    {
        cin >> x >> y;
        vec.pb( mp(x,y) );
    }
    q++;
    vec.pb( mp(b, n) );
    sort( vec.begin(), vec.end() );
    Dinic flow(2*10000+10);
    flow.setGraph(0, b+q+6);
    for( int i = 1; i < q; i++ )
    {
        if( (vec[i].xx == vec[i-1].xx && vec[i].yy != vec[i-1].yy) || ( vec[i].yy < vec[i-1].yy ) )
        {
            cout << "unfair" << endl;
            return 0;
        }
    }
    //debug;
    int l = 1;
    for( int i = 0; i < q; i++ )
    {
        //cout << vec[i].xx << " " << vec[i].yy << endl;
        int r = vec[i].xx;
        for( int j = l; j <= r; j++ )
        {
            flow.addEdge(i+1, q+j, 1);
        }
        l = r+1;

        flow.addEdge(0,i+1, (i==0?vec[i].yy: vec[i].yy-vec[i-1].yy));
    }
    /*for( int i = l; i <= b; i++ )
    {
        flow.addEdge(q, i, 1);
    }*/
    for( int i = 1; i <= b; i++ )
    {
        int r = i%5;
        if(r==0) r = 5;
        flow.addEdge(q+i, q+b+r, 1);
    }
    for( int i = 1; i <= 5; i++ )
    {
        int r = i%5;
        if(r==0) r = 5;
        flow.addEdge(q+b+i, q+b+6, n/5);
    }

    int f = flow.maxFlow();
    ///what_is(f);
    if( f == n )
    {
        cout << "fair" << endl;
    }
    else
        cout << "unfair" << endl;


    return 0;
}
