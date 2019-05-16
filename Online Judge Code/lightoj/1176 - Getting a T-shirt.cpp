#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>

map<string, int>mm;

int ara[60][60], flow[60][60], temp, par[60];
bool vis[60];
vector<int>edge[60];

int bfs( int nn )
{
    temp = 1e9;
    memset( vis, 0, sizeof(vis) );
    queue<int>qq;
    qq.push(0);
    vis[0] = 1;
    while( !qq.empty() )
    {
        int u = qq.front();
        qq.pop();
        for( int i = 0; i < edge[u].size(); i++ )
        {
            int v = edge[u][i];
            if( vis[v] == 0 && (ara[u][v] - flow[u][v]) > 0 )
            {
                qq.push(v);
                vis[v] = 1;
                par[v] = u;
                temp = min( temp, ara[u][v] - flow[u][v] );
                if( v == nn )
                    return 1;
            }
        }

    }
    //what_is( vis[nn] );
    return vis[nn];
}


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    cin >> t;
    mm["XXL"] = 1;
    mm["XL"] = 2;
    mm["XS"] = 3;
    mm["L"] = 4;
    mm["M"] = 5;
    mm["S"] = 6;
    while(t--)
    {
        int n, m, p, q;
        int c = 7;
        memset( ara, 0, sizeof(ara) );
        memset( flow, 0, sizeof(flow) );
        string a, b;
        cin >> n >> m;
        //cout << n << " " << m << endl;
        for( int i = 1; i < 7; i++ )
        {
            ara[i][c+m] = n;
            edge[i].pb(c+m);
            edge[c+m].pb(i);
        }

        for( int i = 0; i < m; i++ )
        {
            cin.ignore();
            cin >> a >> b;
            //cout << a << " " << b << endl;
            p = mm[a];
            q = mm[b];
            ara[c+i][p] = ara[c+i][q] = 1;
            ara[0][c+i] = 1;
            edge[0].pb(c+i);
            edge[c+i].pb(0);
            edge[c+i].pb(p);
            edge[c+i].pb(q);
            edge[p].pb(c+i);
            edge[q].pb(c+i);
        }
        par[0] = -1;
        int ans = 0;
        while( bfs(c+m) )
        {
            //debug;
            ans += temp;
            int u = c+m;
            while(u!=0)
            {
                flow[ par[u] ][u] += temp;
                flow[ u ][par[u]] -= temp;
                u = par[u];
            }
        }
        if( ans >= m )
            cout << "Case " << caseno++ << ": YES\n";
        else
            cout << "Case " << caseno++ << ": NO\n";
    }

    return 0;
}



