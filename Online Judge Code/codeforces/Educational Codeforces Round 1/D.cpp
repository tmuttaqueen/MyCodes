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

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int n, m, k;
vector<string>vec(1005);
bool vis[1005][1005];
int ans[1005][1005];
int tt;
vector<pii>temp;

void dfs( int x, int y )
{
    vis[x][y] = 1;
    for( int i = 0; i < 4; i++ )
    {
        int nx = x+dx[i], ny = y+dy[i];
        if( nx >= 0 && nx < n && ny >= 0 && ny < m && vec[nx][ny] == '*' )
            tt++;
        if( nx >= 0 && nx < n && ny >= 0 && ny < m && vec[nx][ny] == '.' && vis[nx][ny] == 0 )
            dfs(nx,ny);
    }
    temp.pb(mp(x,y));
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    cin >> n >> m >> k;
    cin.ignore();
    for( int i = 0; i < n; i++ )
        cin >> vec[i];
    for( int i = 0; i < n; i++ )
    {
        for( int j = 0; j < m; j++ )
        {
            if( vec[i][j] == '.' && vis[i][j] == 0 )
            {
                tt = 0;
                dfs( i,j);
                //cout << i << " " << j << " " << tt << endl;
                for( int p = 0; p < temp.size(); p++ )
                {
                    ans[ temp[p].xx ][ temp[p].yy ] = tt;
                }
                temp.clear();
            }
        }
    }
    for( int i = 0; i < k; i++ )
    {
        int a, b;
        cin >> a >> b;
        cout << ans[a-1][b-1] << endl;
    }
    return 0;
}



