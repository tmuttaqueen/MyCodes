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

const int mx = 10005;

vector< vector<int> >edge(mx), cost(mx), redge(mx), rcost(mx);
int anss[mx], p, anst[mx];
int n, m, s, t, a, b , w;

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

void dijkstra( int s, vector< vector<int> >&eg, vector< vector<int> >&cost, int path[] )
{
    priority_queue<edg>pq;
    pq.push( edg(s,0) );
    path[s] = 0;
    while( !pq.empty()  )
    {
        edg x = pq.top();
        pq.pop();
        if( x.w > path[x.a] )
            continue;
        for( int i = 0; i < eg[x.a].size(); i++ )
        {
            int v = eg[x.a][i], cst = cost[x.a][i];
            if( x.w + cst < path[v] )
            {
                path[v] = x.w + cst;
                pq.push( edg(v,x.w + cst) );
            }
        }
    }
}


int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int ts, caseno = 1;
    scanf("%d", &ts);
    while(ts--)
    {
        memset( anss, 63, sizeof anss );
        memset( anst, 63, sizeof anst );
        for( int i = 0; i < mx; i++ )
        {
            edge[i].clear();
            cost[i].clear();
            redge[i].clear();
            rcost[i].clear();
        }

        scanf("%d %d %d %d %d", &n, &m, &s, &t, &p);
        for( int i = 0; i < m; i++ )
        {
            scanf("%d %d %d", &a, &b, &w);
            edge[a].pb(b);
            cost[a].pb(w);
            redge[b].pb(a);
            rcost[b].pb(w);
        }

        dijkstra( s, edge, cost, anss );
        //cout << "reverse\n";
        dijkstra( t, redge, rcost, anst );
        /*for( int i = 1; i<= n; i++ )
        {
            //cout << anss[i] << " " << anst[i] << endl;
        }
        //what_is(p);*/
        int ans = -1;
        for( int i = 1; i <= n; i++  )
        {
            for( int j = 0; j < edge[i].size(); j++ )
            {
                int u = i, v = edge[i][j], w = cost[i][j];
                if( anss[u] + w + anst[v] <= p )
                {
                    //cout << u << " " << v << endl;
                    ans = max( ans, w );
                }
            }
        }
        printf("Case %d: %d\n", caseno++, ans );
    }

    return 0;
}




