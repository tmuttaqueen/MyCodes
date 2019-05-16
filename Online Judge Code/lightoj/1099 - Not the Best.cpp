#include <bits/stdc++.h>

using namespace std;

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

const int mx = 5005;
vector< vector<int> >edge(mx), path(mx), cost(mx);
int n,m;

///DIJKSTRA SHORTEST PATH O(elogv)
//a structure for maintaining priority queue
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
//s = source, eg = edge list, cost = cost of a edge, path = shortest distance keeper from source
void dijkstra( int s, vector< vector<int> >&eg, vector< vector<int> >&cost, vector< vector<int> >&path )
{
    priority_queue<edg>pq;
    pq.push( edg(s,0) );
    //path[s].pb(0);
    while( !pq.empty() &&  path[n].size() < 2 )
    {
        edg x = pq.top();
        pq.pop();
        if( path[x.a].size() < 2  )
        {
            if( path[x.a].size() == 0 )
                path[x.a].pb(x.w);
            else if( path[x.a].size() == 1 && x.w > path[x.a][0] )
                path[x.a].pb(x.w);
            //cout << x.a << " " << x.w << endl;
        }
        else
        {
            continue;
        }

        for( int i = 0; i < eg[x.a].size(); i++ )
        {
            int v = eg[x.a][i], cst = cost[x.a][i];
            if( path[v].size() < 2 )
            {
                pq.push( edg(v,x.w + cst) );
            }
        }
    }
}

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &m);
        int a, b, w;
        for( int i = 0; i < m; i++ )
        {
            scanf("%d %d %d", &a, &b, &w);
            edge[a].pb(b);
            edge[b].pb(a);
            cost[a].pb(w);
            cost[b].pb(w);
        }
        dijkstra(1, edge, cost, path);
        printf("Case %d: %d\n", caseno++, path[n][1] );
        for( int i = 0; i <= n; i++ )
        {
            edge[i].clear();
            cost[i].clear();
            path[i].clear();
        }
    }

    return 0;
}


