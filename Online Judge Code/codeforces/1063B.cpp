#include<bits/stdc++.h>

using namespace std;
long long n, m, r, c, x, y;
struct pii
{
    int x, y;
};

string s[2005];
long long ara[2005][2005];
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, 1, -1};
//int vis[2005][2005];

void bfs( int x, int y )
{
    deque<pii>q;
    q.push_back( {x,y} );
    ara[x][y] = 0;
    //vis[x][y] = 1;
    //cout << "xx " << x << " " << y << " " << ara[x][y] << endl;
    while( !q.empty() )
    {
        int cx = q.front().x, cy = q.front().y;
        q.pop_front();
        //cout << "from: " << cx << " " << cy << " v: " << ara[cx][cy] << endl;
        for( int i = 0; i < 4; i++ )
        {
            int xx = cx + dx[i], yy = cy+dy[i];
            if( xx >= 0 && xx <= n && yy >= 0 && yy <= m  && ara[xx][yy] > ara[cx][cy] + (i==3) && s[xx][yy] == '.')
            {
                //cout << "to: " << xx << " " << yy << endl;
                //vis[xx][yy] = 1;
                ara[xx][yy] = ara[cx][cy] + (i==3);
                (i==3)?q.push_back({xx,yy}):q.push_front( {xx,yy} );
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> r >> c >> x >> y;
    for( int i = 0; i < n; i++ ) cin >> s[i];
    n--;
    m--;
    r--;
    c--;
    for( int i = 0; i <= n; i++ )
    {
        for( int j = 0; j <= m; j++ )
            ara[i][j] = 1e9+10;
    }
    bfs(r,c);
    int ans = 0;

    for( int i = 0; i <= n; i++ )
    {
        for( int j = 0; j <= m; j++ )
        {
            //cout << setw(10) << ara[i][j] << " ";
            if( ara[i][j] <= x && ara[i][j] + j - c <= y )
                ans++;
        }
        //cout << endl;
    }
    cout << ans << endl;
    return 0;
}
