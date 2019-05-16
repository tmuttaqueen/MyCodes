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
#define debug       cout << "YES" << endl
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define pii         pair<int, int>

//find_by_order(int) and order_of_key(int)
//typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;
const int M = 345678;

const int MAX = 105;

namespace wm
{

/// n = number of row and m = number of columns in 1 based, flag = 1-MAXIMIZE or 0-MINIMIZE
/// match[i] contains the column to which row i is matched

bool visited[MAX];
int U[MAX], V[MAX], P[MAX], way[MAX], minv[MAX], match[MAX], ar[MAX][MAX];

int hungarian(int n, int m, int mat[MAX][MAX], int flag = 0)
{
    memset(U, 0, 4*(n+5));
    memset(V, 0, 4*(n+5));
    memset(P, 0, 4*(n+5));
    memset(ar, 0, 4*(n+5));
    memset(way, 0, 4*(n+5));
    int inf = 1e9;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            ar[i][j] = mat[i][j];
            if (flag) ar[i][j] = -ar[i][j];
        }
    }
    if (n > m) m = n;

    int i, j, a, b, c, d, r, w;
    for (i = 1; i <= n; i++)
    {
        P[0] = i, b = 0;
        for (j = 0; j <= m; j++) minv[j] = inf, visited[j] = false;

        do
        {
            visited[b] = true;
            a = P[b], d = 0, w = inf;

            for (j = 1; j <= m; j++)
            {
                if (!visited[j])
                {
                    r = ar[a][j] - U[a] - V[j];
                    if (r < minv[j]) minv[j] = r, way[j] = b;
                    if (minv[j] < w) w = minv[j], d = j;
                }
            }

            for (j = 0; j <= m; j++)
            {
                if (visited[j]) U[P[j]] += w, V[j] -= w;
                else minv[j] -= w;
            }
            b = d;
        }while (P[b] != 0);

        do
        {
            d = way[b];
            P[b] = P[d], b = d;
        }while (b != 0);
    }
    for (j = 1; j <= m; j++) match[P[j]] = j;

    return (!flag) ? -V[0] : V[0];
}
}

//int ara[MAX][MAX];
int sz1[MAX], sz2[MAX];
vector<int>g1[MAX], g2[MAX];
int n1, n2;
int dp[MAX][MAX];

void dfs1( int u, int p)
{
    sz1[u] = 1;
    for( int i = 0; i < g1[u].size(); i++ )
    {
        int v = g1[u][i];
        if( v == p ) continue;
        dfs1(v, u);
        sz1[u] += sz1[v];
    }
}

void dfs2( int u, int p)
{
    sz2[u] = 1;
    for( int i = 0; i < g2[u].size(); i++ )
    {
        int v = g2[u][i];
        if( v == p ) continue;
        dfs2(v, u);
        sz2[u] += sz2[v];
    }
}

int solve( int u, int v )
{
    //printf("%d %d\n", u, v);
    if( u > n1 ) return dp[u][v] = sz2[v];
    if( v > n2 ) return dp[u][v] = sz1[u];
    if( dp[u][v] != -1 ) return dp[u][v];

    int n = max( g1[u].size(), g2[v].size() );
    int ara[MAX][MAX];
    for( int i = 1; i <= n; i++ )
    {
        int a, b;
        for( int j = 1; j <= n; j++ )
        {
            if( i-1 >= g1[u].size() )
            {
                a = n1+1;
                b = g2[v][j-1];
            }
            else if( j-1 >= g2[v].size() )
            {
                b = n2+1;
                a = g1[u][i-1];
            }
            else
            {
                a = g1[u][i-1];
                b = g2[v][j-1];
            }
            ara[i][j] = solve(a, b );
            //printf("%d %d %d\n", a, b, ara[i][j]);
        }
    }

    dp[u][v] = wm::hungarian(n,n,ara, 0);
    //printf("dp: %d %d %d\n", u, v, dp[u][v]);
    return dp[u][v];
}

int main()
{

    //filein;
    int t, caseno = 1, a;
    scanf("%d", &t);
    while(t--)
    {
        for( int i = 0; i <= 100; i++ )
        {
            g1[i].clear();
            g2[i].clear();
        }
        scanf("%d", &n1);

        for( int i = 1; i <= n1; i++ )
        {
            scanf("%d", &a);
            g1[a].pb(i);

        }
        scanf("%d", &n2);

        for( int i = 1; i <= n2; i++ )
        {
            scanf("%d", &a);

            g2[a].pb(i);
        }
        memset( dp, -1, sizeof dp );
        dfs1(0,-1);
        dfs2(0,-1);
        //debug;
        printf("Case %d: %d\n", caseno++, solve(0,0));
    }
    return 0;
}
