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

int vis[1005];
vector<int>edge[1005];
int c = 1;
vector<pii>group[1005];
int ww[1005], b[1005];
intl dp[1005][1005];

void dfs( int u )
{
    group[c].pb( mp(ww[u], b[u]) );
    vis[u] = 1;
    for( int v: edge[u] )
    {
        if( !vis[v] )
            dfs(v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int n, m, w;
    cin >> n >> m >> w ;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ww[i];
    }
    for( int i = 1; i <= n; i++ )
    {
        cin >> b[i];
    }
    int p,q;
    for( int i = 1; i <= m; i++ )
    {
        cin >> p >> q;
        edge[p].pb(q);
        edge[q].pb(p);
    }

    for( int i = 1; i <= n; i++ )
    {
        if(!vis[i])
        {
            dfs(i);
            c++;
        }
    }

    for( int i = 1; i < c; i++ )
    {
        intl x = 0, y = 0;
        group[i].pb( mp(0,0) );
        for( pii p: group[i] )
        {
            x += p.xx;
            y += p.yy;
        }
        group[i].pb( mp(x,y) );
    }
    /*for( int i = 1; i < c; i++ )
    {

        for( pii p: group[i] )
        {
            cout << p.xx << " " << p.yy << " n ";
        }
        cout << endl;
    }*/

    for( int i = 1; i < c; i++ )
    {
        for( int j = 1; j <= w; j++ )
        {
            dp[i][j] =dp[i-1][j];
            intl d =  dp[i][j];
            intl root = d;
            for( pii p: group[i] )
            {
                if( j - p.xx >= 0 )
                {
                    d = max( d, dp[i-1][j-p.xx] + p.yy );
                    dp[i][j] = max( dp[i][j], d );
                    d = root;
                }
            }
        }
    }
    /*for( int i = 1; i < c; i++ )
    {
        for( int j = 1; j <= w; j++ )
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }*/


    cout << dp[c-1][w] << endl;

    return 0;
}




