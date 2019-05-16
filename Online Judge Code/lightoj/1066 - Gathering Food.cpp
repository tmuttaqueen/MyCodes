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

char ara[12][12];
int flag[12][12], cnt, n;
vector<pii>vec(50);
pii s, e;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};

int bfs( pii s )
{
    int isv[12][12], lv[12][12];
    memset( isv, 0, sizeof(isv) );
    memset( lv, 0, sizeof(lv) );

    queue<pii>q;
    q.push(s);
    while( !q.empty() )
    {
        pii v = q.front();
        q.pop();
        isv[ v.xx ][ v.yy ] = 1;
        for( int i = 0; i < 4; i++ )
        {
            int x = v.xx+dx[i], y = dy[i] +v.yy;
            if( x >= 0 && x < n && y >= 0 && y < n && flag[x][y] == 1 && isv[x][y] == 0 )
            {
                q.push( mp(x,y) );
                lv[x][y] = lv[v.xx][v.yy] + 1;
                if( x == e.xx && y == e.yy )
                    return lv[x][y];
            }
        }
    }
    return -1;
}

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int ans = 0, isp = 1;
        cnt = 0;
        getchar();
        scanf("%d", &n);
        for( int i = 0; i < n; i++ )
            scanf("%s", &ara[i]);

        for( int i = 0; i<n; i++ )
        {
            for( int j = 0; j < n; j++ )
            {
                if( ara[i][j] >= 'A' && ara[i][j] <= 'Z' )
                {
                     vec[ ara[i][j] - 'A' ] = mp(i,j);
                     cnt++;
                }

            }
        }

        for( int i = 1; i < cnt; i++ )
        {
            s = vec[i-1], e = vec[i];
            //cout << s.xx << "," << s.yy << endl;
            //cout << e.xx << "," << e.yy << endl;
            memset( flag, 0, sizeof(flag) );
            for( int i = 0; i<n; i++ )
            {
                for( int j = 0; j < n; j++ )
                {
                    if( ara[i][j] == '.' )
                    {
                        flag[i][j] = 1;
                    }

                }
            }
            flag[e.xx][e.yy] = 1;
            flag[s.xx][s.yy] = 1;
            ara[e.xx][e.yy] = '.';
            ara[s.xx][s.yy] = '.';
            int tt = bfs(s);
            //what_is(tt);
            if( tt == -1 )
            {
                isp = 0;
                break;
            }
            else
                ans += tt;
        }
        if(isp)
            printf("Case %d: %d\n", caseno++, ans);
        else
            printf("Case %d: Impossible\n", caseno++);
    }

    return 0;
}



