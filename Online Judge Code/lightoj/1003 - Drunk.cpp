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
vector<int>edge[20005];
int dis[20005], vis[20005], flag, tt;

void dfs( int u )
{
    if(flag==0) return;
    dis[u] = tt++;
    int l = edge[u].size();
    for( int i = 0; i < l; i++ )
    {
        int v = edge[u][i];
        if( dis[v] != -1 && dis[v] <= dis[u] && vis[v] == 0 )
        {
            flag = 0;
            return;
        }
        else if( vis[v] == 0 )
            dfs(v);
    }
    vis[u] = 1;
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
        flag = 1;
        tt = 1;
        string x, y;
        int a, c = 1;
        cin >> a;
        memset( dis, -1, sizeof(dis) );
        memset( vis, 0, sizeof(vis) );
        for( int i = 0; i < a; i++ )
        {
            cin >> x >> y;
            if( mm[x] == 0 )
                mm[x] = c++;
            if( mm[y] == 0 )
                mm[y] = c++;
            int p = mm[x], q = mm[y];
            //cout << p << "   " << q << endl;
            edge[p].pb(q);
        }
        /*for( int i = 1; i < c; i++ )
        {
            int l = edge[i].size();
            cout << i << " -- ";
            for( int j = 0; j < l; j++ )
                cout << edge[i][j] << ' ';
            cout << endl;
        }*/
        for( int i = 1; i < c && flag == 1; i++ )
        {
            if(vis[i] == 0)
            {
                dfs(i);
            }

        }
        for( int i = 1; i < c; i++ )
        {
            //cout << dis[i] << ' ';
            edge[i].clear();
        }
        if(flag)
            cout << "Case " << caseno++ << ": Yes\n";
        else
            cout << "Case " << caseno++ << ": No\n";
        mm.clear();
    }

    return 0;
}



