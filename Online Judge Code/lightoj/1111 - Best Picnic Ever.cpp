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


vector<int>edge[1005];
int hm[105], rc[1005];
int vis[1005];

void dfs( int u )
{
    int x = edge[u].size();
    vis[u] = 1;
    rc[ u ]++;
    for( int i = 0; i < x; i++ )
    {
        if( vis[ edge[u][i] ] == 0 )
        {
            dfs( edge[u][i] );
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int k, n, m, a, b, ans = 0;
        scanf("%d %d %d", &k, &n, &m);
        for( int i = 0; i < k; i++ )
            scanf("%d", &hm[i]);
        for( int i = 0; i < m; i++ )
        {
            scanf("%d %d", &a, &b);
            edge[a].pb(b);
        }
        memset( rc, 0, sizeof(rc) );
        for( int i = 0; i < k; i++ )
        {
            memset( vis, 0, sizeof(vis) );
            dfs( hm[i] );
        }
        for( int i = 1; i <= n; i++ )
        {
            if( rc[i] == k )
                ans++;
        }
        printf("Case %d: %d\n", caseno++, ans);
        for( int i = 0; i <= n; i++ )
            edge[i].clear();
    }
    return 0;
}



