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

const int MAX = 12001, NIL = 0, INF = 1<<28;

struct BPM
{
    vector< int > edge[MAX];
    int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// edge = NIL[0] ∪ edge1[edge[1---n]] ∪ edge2[edge[n+1---n+m]]

    bool bfs()
    {
        int u, v, len;
        queue< int > Q;
        for( int i = 1; i <= n; i++)
        {
            if( match[i] == NIL)
            {
                dist[i] = 0;
                Q.push(i);
            }
            else dist[i] = INF;
        }
        dist[NIL] = INF;
        while( !Q.empty() )
        {
            u = Q.front();
            Q.pop();
            if( u != NIL)
            {
                len = edge[u].size();
                for( int i = 0; i < len; i++ )
                {
                    v = edge[u][i];
                    if( dist[match[v]] == INF )
                    {
                        dist[match[v]] = dist[u] + 1;
                        Q.push(match[v]);
                    }
                }
            }
        }
        return dist[NIL] != INF;
    }

    bool dfs(int u)
    {
        int v, len;
        if( u != NIL)
        {
            len = edge[u].size();
            for( int i = 0; i < len; i++)
            {
                v = edge[u][i];
                if( dist[match[v]] == dist[u]+1 )
                {
                    if( dfs(match[v]) )
                    {
                        match[v] = u;
                        match[u] = v;
                        return true;
                    }
                }
            }
            dist[u] = INF;
            return false;
        }
        return true;
    }
    void init( int nn, int mm )
    {
        n = nn;
        m = mm;
        // match[] is assumed NIL for all vertex in edge. Clear it for multiple case.
        for( int i = 0; i <= n+m; i++ )
            edge[i].clear();
        memset( match, 0, sizeof match );
        memset( dist, 0, sizeof dist );
    }
    void addEdge( int u, int v )
    {
        //u := [1, n] ... v := [n+1,n+m]
        edge[u].push_back(v);
    }
    int hopcroft_karp()
    {
        int matching = 0, i;
        while( bfs() )
        {
            for( int i = 1; i <= n; i++)
                if( match[i] == NIL && dfs(i) )
                    matching++;
        }
        return matching;
    }

};

int col[1234], b, r, ind[1234];
vector<int>edge[1234];

void dfs( int u, int p )
{
    if( col[u] == 1 ) b++;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( v == p ) continue;
        col[v] = !col[u];
        dfs(v, u);
    }
}

int main()
{
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    BPM bpm;
    while(t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        b = 0;
        r = 0;
        for( int i = 0; i < m; i++ )
        {
            int a, b;
            scanf("%d %d", &a, &b);
            edge[a].pb(b);
            edge[b].pb(a);
        }
        b = 0;
        memset( col, -1, sizeof col );
        for( int i = 1; i <= n; i++ )
        {
            if( col[i] != -1 ) continue;
            col[i] = 1;
            dfs(i,-1);
        }

        bpm.init(b, n-b);
        int x = 1, y = b+1;

        for( int i = 1; i <= n; i++ )
        {
            if( col[i] == 1 )
            {
                ind[i] = x++;
            }
            else
                ind[i] = y++;
        }
        for( int i = 1; i <= n; i++ )
        {
            if( col[i] == 0 ) continue;
            int u = ind[i];
            for( int j = 0; j < edge[i].size(); j++ )
            {
                int v = edge[i][j];
                bpm.addEdge(u, ind[v]);
            }
        }
        int ans = n - bpm.hopcroft_karp();
        printf("Case %d: %d\n", caseno++, ans);
        for( int i = 1; i <= n; i++ )
            edge[i].clear();
    }
    return 0;
}
