#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

typedef tree < intl , null_type ,less<intl>,rb_tree_tag,tree_order_statistics_node_update > ordered_set;

int dx[] = {0,0,-1,1};
int dy[] = {-1, 1, 0, 0  }; //l, r, d, u 0, 1, 2, 3

int ans[4][1005][1005];
string s[1005];
int vis[4][1005][1005];
int n, m;
void dfs( int x, int y, int d )
{
    //cout << x << " " << y << endl;
    //if( d != -1 )
        //cout << d << " " << x << " " << y << " " << ans[d][x][y] << endl;
    if(d != -1)
        vis[d][x][y] = 1;
    for( int i = 0; i < 4; i++ )
    {
        int X = x + dx[i], Y = y + dy[i];
        //cout << X << " " << Y << " " << endl;  ;
        if( X >= 0 && X < n && Y >= 0 && Y < m && vis[i][X][Y] == 0 && s[X][Y] != '*' )
        {
            //cout << X << " " << Y << endl;
            if( i == d )
            {
                ans[i][X][Y] = ans[i][x][y];
                dfs( X, Y, i );
            }
            else
            {
                ans[i][X][Y] = (d == -1? 0: ans[d][x][y]) + 1;
                dfs(X,Y, i);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    int si, sj, ti, tj;

    cin >> n >> m;


    for( int i = 0; i < n; i++ )
    {
        cin >> s[i];
    }
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < m; j++ )
        {
            if( s[i][j] == 'S' )
            {
                si = i;
                sj = j;
            }
            if( s[i][j] == 'T' )
            {
                ti = i;
                tj = j;
            }
        }
    }
    vis[0][si][sj] = vis[1][si][sj]  = vis[2][si][sj] = vis[3][si][sj] = 1;
    ans[0][si][sj] = ans[1][si][sj] = ans[2][si][sj] = ans[3][si][sj] = 0;
    dfs( si, sj, -1 );
    int mn = 1e9;
    for( int i = 0; i < 4; i++ )
    {
        if( vis[i][ti][tj] != 0 )
            mn = min( mn, ans[i][ti][tj] );
    }
    //what_is(mn);
    if( mn <= 3 ) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}



