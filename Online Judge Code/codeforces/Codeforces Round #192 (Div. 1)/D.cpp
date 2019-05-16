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

int dist[1005][1005], vis[1005][1005], r , c, dd;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
string str[1005];
queue<pii>qq;

void bfs( pii p )
{
    qq.push(p);
    dist[p.xx][p.yy] = 0;
    vis[p.xx][p.yy] = 1;
    while( !qq.empty() )
    {
        pii t = qq.front();
        qq.pop();
        for( int i = 0; i < 4; i++ )
        {
            int x = t.xx + dx[i];
            int y = t.yy + dy[i];
            if( x >=0 && x < r && y >= 0 && y < c && str[x][y] != 'T' && vis[x][y] == 0 )
            {
                vis[x][y] = 1;
                qq.push( mp(x,y) );
                dist[x][y] = dist[t.xx][t.yy] + 1;
                if( str[x][y] == 'S' )
                    dd = dist[x][y];
            }
        }
    }
    return ;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //filein;
    cin >> r >> c;
    for( int i = 0; i < r; i++ ) cin >> str[i];
    for( int i = 0; i < r; i++ )
    {
        for( int j = 0; j < c; j++ )
        {
            if( str[i][j] == 'E' )
                bfs( mp(i,j) );
        }
    }
    int ans = 0;
    for( int i = 0; i < r; i++ )
    {
        for( int j = 0; j < c; j++ )
        {
            if( str[i][j] >= '1' && str[i][j] <= '9' && dist[i][j] <= dd && vis[i][j] == 1 )
                ans += str[i][j] - '0';
        }
    }
    cout <<ans << endl;
    return 0;
}




