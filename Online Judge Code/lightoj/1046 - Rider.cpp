#include <bits/stdc++.h>

using namespace std;

int ans[11][11];
int how[11][11];
int t, r, c, n;
const int px[] = { 1,1,2,2,-1,-1,-2,-2 };
const int py[] = { 2,-2,1,-1,2,-2,1,-1 };
struct data
{
    int x, y;
};

void bfs( data d )
{
    int ara[r][c];
    int time[r][c], tm;
    memset( ara, 0, sizeof(ara) );
    memset( time, 0, sizeof(time) );
    ara[d.x][d.y] = 1;
    queue< data > q;
    q.push(d);
    while( !q.empty() )
    {
        data t1 = q.front(), t2;
        how[t1.x][t1.y]++;
        //cout << t1.x << " " << t1.y << endl; ;
        tm = time[t1.x][t1.y];
        ans[t1.x][t1.y] += ceil( (double)tm/(double)n );
        tm++;
        for( int i = 0; i < 8; i++  )
        {
            t2.x = t1.x + px[i];
            t2.y = t1.y + py[i];
            if( (t2.x >= 0 && t2.x < r) && (t2.y >= 0 && t2.y < c) && ara[t2.x][t2.y] == 0  )
            {
                q.push(t2);
                ara[t2.x][t2.y] = 1;
                time[t2.x][t2.y] = tm;
            }
        }
        q.pop();
    }
    return;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &t);
    int caseno = 1;
    while(t--)
    {
        getchar();
        memset( ans, 0, sizeof(ans) );
        memset( how, 0, sizeof(how) );
        int cc = 0;
        scanf("%d %d", &r, &c);
        char ara[r+2][c+2];
        for( int i = 0; i < r; i++ )
        {
            scanf("%s", &ara[i]);
        }
        data d;
        for( int i = 0; i < r; i++ )
        {
            for( int j = 0; j < c; j++ )
            {
                if( ara[i][j] != '.' )
                {
                    cc++;
                    n = ara[i][j] - '0';
                    d.x = i;
                    d.y = j;
                    bfs( d );
                }
            }
        }
        //cout << cc << endl;
        int yy = 0;
        int xxx = 100000000;
        for( int i = 0; i < r; i++ )
        {
            for( int j = 0; j < c; j++ )
            {
                if( how[i][j] == cc )
                {
                    if( ans[i][j] < xxx )
                        xxx = ans[i][j];
                }
            }
        }
        if( xxx == 100000000 )
            xxx = -1;
        printf("Case %d: %d\n",caseno++, xxx);
    }
    return 0;
}
