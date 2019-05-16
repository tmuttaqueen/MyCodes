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

const int mx = 200005;

intl dist[20][mx], ver[mx], an[20][mx];
vector<int>edge[mx];
int par[mx];
int inf = 2e9;
int aux[mx];
int ans[mx], n;


void dfs( int u, int p )
{
    int temp = 0;
    for( int v: edge[u] )
    {
        if( v != p )
        {
            dfs(v, u);
            temp += ans[v];
        }
    }
    //cout << u << ' ' << temp << endl;
    temp += edge[u].size() - 1;
    temp += aux[u];
    ans[u] = temp;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    for( int i = 0; i < 20; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            dist[i][j] = inf;
        }
    }

    memset( an, -1, sizeof an );
    int n, a, b;
    cin >> n;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ver[i];
    }
    for( int i = 2; i <= n; i++ )
    {
        cin >> a >> b;
        dist[0][i] = b;
        an[0][i] = a;
        par[i] = a;
        edge[i].pb(a);
        edge[a].pb(i);
    }
    edge[1].pb(0);
    par[1] = 0;
    for( int i = 1; i < 20; i++ )
    {
        for( int j = 1; j <= n; j++ )
        {
            dist[i][j] = (an[i-1][j] != -1) ? (dist[i-1][j] + dist[i-1][ an[i-1][j] ]): inf;
            an[i][j] = (an[i-1][j] != -1) ? (an[i-1][ an[i-1][j] ]): -1;
        }
    }
    for( int i = 1; i <= n; i++ )
    {
        int cn = i;
        intl sum = ver[i];
        for(  int j = 19; j >= 0; j-- )
        {
            if( an[j][cn] == -1 ) continue;
            if( dist[j][cn] <= sum )
            {
                sum -= dist[j][cn];
                cn = an[j][cn];
            }
        }
        //cout << cn << " ";
        aux[par[cn]]--;
    }
    //cout << endl;
    //for( int i = 1; i <= n; i++ ) cout << aux[i] << " ";
    //cout << endl;
    dfs(1, 0);
    for( int  i = 1; i <= n; i++ ) cout << ans[i] << " ";
    cout << endl;
    return 0;
}



