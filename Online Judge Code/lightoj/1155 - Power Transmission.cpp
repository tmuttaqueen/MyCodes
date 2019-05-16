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

const int MAX_V = 222, MAX_E = 1111;
int C[MAX_V][MAX_V];
//initially u->v is C and v->u is 0 if flow increases through u->v is
//f then Capacity of v->u increases f and Capacity of u->v decreases f
vector<int>edge[MAX_V];
//edges goes in both direction but input is unidirectional
int n, m;
//node and edge
int level[MAX_V];

bool bfs( int u ) //source
{
    level[u] = 0;
    queue<int>q;
    int flag[MAX_V];
    memset( flag, 0, sizeof flag );
    flag[u] = 1;
    q.push(u);
    while( !q.empty() )
    {
        int u = q.front();
        q.pop();
        for( int i = 0; i < edge[u].size(); i++ )
        {
            int v = edge[u][i];
            if( C[u][v] > 0 && flag[v] == 0 )
            {
                flag[v] = 1;
                level[v] = level[u]+1;
                q.push(v);
            }
        }
    }
    return flag[n]; //is possible to go destination
}

int augmentPath( int u, int f ) //node, flow so far
{
    if( u == n ) return f;
    int tot = 0;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( level[v] == level[u]+1 && C[u][v] > 0 )
        {
            int d = augmentPath( v, min( f, C[u][v] ) );
            C[u][v] -= d;
            C[v][u] += d;
            tot += d;
            f -= d;
            if( f <= 0 )
                break;
        }
    }
    return tot;
}

int dinicMaxFlow( int s, int t ) //source, destination
{
    int flow = 0;
    while( bfs( s ) )
    {
        flow += augmentPath(s, 2000000);
    }
    return flow;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        memset(C, 0, sizeof C);
        cin >> n;
        int a;
        for( int i = 0; i <= 2*n; i++ )
        {
            edge[i].clear();
        }
        for( int i = 1; i <= n; i++ )
        {
            cin >> a;
            edge[n+i].pb(i);
            edge[i].pb(n+i);
            C[n+i][i] += a;
            C[i][n+i] += 0;
        }
        cin >> m;
        int b,c;
        for( int i = 0; i < m; i++ )
        {
            cin >> a >> b >> c;
            b += n;
            edge[a].pb(b);
            edge[b].pb(a);
            C[a][b] += c;
            C[b][a] += 0;
        }
        int d;
        cin >> b >> d;
        for( int i = 0; i < b; i++ )
        {
            cin >> a;
            a += n;
            edge[0].pb(a);
            edge[a].pb(0);
            C[0][a] += 2000000;
            C[a][0] += 0;
        }
        n = 2*n+1;
        for( int i = 0; i < d; i++ )
        {
            cin >> a;
            edge[n].pb(a);
            edge[a].pb(n);
            C[a][n] += 2000000;
            C[n][a] += 0;
        }
        int ans = dinicMaxFlow(0, n);
        cout << "Case " << caseno++ << ": " << ans << endl;

    }
    return 0;
}
