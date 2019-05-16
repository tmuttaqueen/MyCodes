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
int ans = 0;
int ara[100005];
int n,m;
int vis[100005];

void dfs( int u, int cat )
{
    //what_is(u);
    vis[u] = 1;
    if( ara[u]==1 ) cat++;
    if( ara[u]==0 ) cat = 0;
    if( cat > m  )
        return;
    if( edge[u].size() == 1 && u != 1 )
        ans++;
    for( int i = 0; i < edge[u].size(); i++ )
    {
        int v = edge[u][i];
        if( vis[v] == 0 )
            dfs(v, cat);
    }
}


int main()
{
    ios::sync_with_stdio(false);
    //filein;

    cin >> n >> m;

    for( int i = 1; i <= n; i++ )
        cin >> ara[i];
    for( int i = 1; i < n; i++ )
    {
        int a, b;
        cin >> a >> b;
        edge[a].pb(b);
        edge[b].pb(a);
    }
    dfs( 1,0  );
    cout << ans << endl;
    return 0;
}



