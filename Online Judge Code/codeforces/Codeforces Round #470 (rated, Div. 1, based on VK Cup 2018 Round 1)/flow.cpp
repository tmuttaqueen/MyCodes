#include<bits/stdc++.h>

using namespace std;

#define pb push_back

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
    cin >> n >> m;
    for( int i = 0; i < m; i++ )
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[a].pb(b);
        edge[b].pb(a);
        C[a][b] = c;
    }
    cout <<  dinicMaxFlow( 1, n ) << endl;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}







