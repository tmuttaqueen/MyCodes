#include<bits/stdc++.h>
using namespace std;

const int mx = 1e5+5;

#define xx first
#define yy second

vector<pair<int, int>> all;
vector< int >edge[mx];
int par[mx], dep[mx], col[mx], temp[mx], pared[mx];
vector< pair<int,int> >cyc;

int adj( int u, int x )
{
    if( all[x].xx == u) return all[x].yy;
    return all[x].xx;
}

void dfs( int u, int p )
{
    //cout << "u: " << u << " p: " << p << endl;
    col[u] = 1;
    if( p == -1 ) dep[u] = 0;
    else dep[u] = dep[p] + 1;

    for( int x: edge[u] )
    {
        int v = adj(u, x);
        if( v == p ) continue;
        if( par[v] == 0 )
        {
            par[v] = u;
            pared[v] = x;
            dfs(v, u);
        }
        else if( col[v] == 1 )
        {
            cyc.push_back({u, x});
        }
    }
    col[u] = 2;
}

int leader[mx], mark[mx], sz[mx];

int find_leader( int u )
{
    if( leader[u] == u ) return u;
    return leader[u] = find_leader( leader[u] );
}

set<int>ans;

void process()
{
    //cout << "IN" << endl;
    for( int i = 0; i < mx; i++ )
    {
        mark[i] = -1;
        temp[i] = par[i];
        leader[i] = i;
    }
    for( int i = 0; i < cyc.size(); i++ )
    {
        sz[i] = 1;
        int u = cyc[i].xx, v = adj(u, cyc[i].yy);
        //cout << u << " " << v << endl;
        vector<int>path;
        while( dep[u] > dep[v] )
        {
            path.push_back(u);
            if( mark[u] == -1 )
                mark[u] = i;
            else
            {
                int pu = find_leader(mark[u]), pi = find_leader(i);
                if( pi != pu )
                {
                    leader[pi] = pu;
                    sz[pu] += sz[pi];
                    sz[pi] = 0;
                }
            }
            u = temp[u];
        }
        for( int i = 0; i < path.size(); i++ )
            temp[path[i]] = v;
    }
    for( int i = 0; i < cyc.size(); i++ )
    {
        int u = cyc[i].xx, v = adj(u, cyc[i].yy);
        int pu = find_leader(mark[u]);
        //cout << u << " mark " << mark[u] << " " << sz[pu] << endl;
        if( sz[pu] == 1 )
        {
            //cout << u << " cyc " << v << endl;
            ans.insert( cyc[i].yy );
            while( dep[u] > dep[v] )
            {
                ans.insert( pared[u] );
                u = par[u];
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int u, v;
    all.push_back({-1,-1});
    for( int i = 1; i <= m; i++ )
    {
        cin >> u >> v;
        all.push_back({u,v});
        edge[u].push_back(i);
        edge[v].push_back(i);
    }
    for( int i = 1; i <= n; i++ )
    {
        if( par[i] == 0 )
        {
            //cout << i << endl;
            par[i] = -1;
            dfs(i, -1);
        }
    }

    process();
    cout << ans.size() << endl;
    for( int x: ans )
        cout << x << ' ';
    return 0;
}
