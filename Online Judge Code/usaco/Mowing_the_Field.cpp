#include <bits/stdc++.h>

using namespace std;

const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { 1, -1, 0, 0 };

int pre[2002][2002];

int main()
{
    //freopen("input.txt", "r", stdin);
    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    //memset( pre, -1, sizeof(pre) );

    //cout << pre[100][100] << endl;
    int n, k, t = 0, x=1001, y=1001, ans = 1000000000;
    char c;
    scanf("%d\n", &n);
    while(n--)
    {
        scanf("%c %d\n", &c, &k);
        //cout << c << " " << k <<endl;
        while(k--){
            t++;
            if( c == 'N' )
            {
                x += dx[0];
                y += dy[0];
            }
            else if( c == 'S' )
            {
                x += dx[1];
                y += dy[1];
            }
            else if( c == 'E' )
            {
                x += dx[2];
                y += dy[2];
            }
            else
            {
                x += dx[3];
                y += dy[3];
            }

            if( pre[x][y] == 0 )
            {
                pre[x][y] = t;
            }
            else
            {
                ans = min( t - pre[x][y], ans );
                pre[x][y] = t;
            }
        }
    }
    if( ans == 1000000000 )
        printf("-1\n");
    else
        printf("%d\n", ans);
    return 0;
}
