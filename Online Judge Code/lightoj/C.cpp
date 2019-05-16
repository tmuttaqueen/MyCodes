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

vector<int>edge[100005];
vector<int>cost[100005];
intl vis[100005];
//int par[100005];
intl del[100005];
//int sad[100005];
intl wrt[100005];
intl child[100005];
intl ans = 0;

void dfs( int u )
{
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        vis[v] = vis[u] + cost[u][i];
        dfs(v);
        del[u] += del[v];
        child[u] += child[v];
    }
    if( vis[u] > wrt[u]  )
    {
        del[u] = child[u];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    filein;
    //par[1] = -1;
    vis[1] = 0;
    int n;
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        intl a;
        cin >> a;
        wrt[i] = a;
    }
    for( int i = 1; i < n; i++ )
    {
        intl a, b;
        cin >> a >> b;
        edge[a].pb(i+1);
        cost[a].pb(b);
    }
    for( int i = 1; i <= n; i++ )
        child[i] = 1;
    dfs(1);
    for( int i = 1; i <= n; i++ )
    {
        cout << child[i] << " ";
    }
    cout << endl;
    for( int i = 1; i <= n; i++ )
    {
        cout << wrt[i] << " ";
    }
    cout << del[1] << endl;

    return 0;
}



