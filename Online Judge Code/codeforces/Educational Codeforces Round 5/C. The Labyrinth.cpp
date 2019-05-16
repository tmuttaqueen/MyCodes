#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1, 0,0 };
int r, c, xx, yy, p1, p2, ans;
int par[1000][1000];
int num[1000][1000];

int find_par( int i, int j )
{
    if( (c*i + j) == par[i][j] )
        return (c*i+j);
    par[i][j] = find_par( par[i][j]/ c , par[i][j] -  (par[i][j]/ c)*c );
    return par[i][j];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d %d", &r, &c);
    char str[r][c+1];
    for( int  i = 0; i < r; i++ )
    {
        scanf("%s", str[i]);
    }
    for( int i  = 0; i < r; i++  )
    {
        for( int j = 0; j < c; j++ )
        {
            par[i][j] = c*i + j;
            num[i][j] = 1;
        }
    }
    //cout << find_par(3,1) << endl;
    for( int  i = 0; i < r; i++ )
    {
        for( int j = 0; j < c; j++ )
        {
            if( str[i][j] == '*' )
                num[i][j] = 0;
            else
            {
                p1 = find_par(i,j);
                //cout << i << " " << j << " " << p1 << endl;
                for( int x = 0; x < 4; x++ )
                {
                    xx = i + dx[x];
                    yy = j + dy[x];
                    if( xx >= 0 && xx < r && yy >= 0 && yy < c && str[xx][yy] != '*' )
                    {
                        p2 = find_par(xx, yy);
                        //if( i == 1 && j == 0 )
                            //cout << xx << " " << yy << " <" <<  p2 << endl;
                        if( p1 != p2 )
                        {
                            par[p2/c][p2 - (p2/c)*c] = p1;
                            num[p1/c][p1 - (p1/c)*c] = num[p1/c][p1 - (p1/c)*c] + num[p2/c][p2 - (p2/c)*c];
                            num[p2/c][p2 - (p2/c)*c] = 0;
                        }
                        //if( i == 1 && j == 0 )
                            //cout << xx << " " << yy << " <" << find_par(xx, yy) << endl;
                    }
                }
            }
        }
    }
    for( int  i = 0; i < r; i++ )
    {
        for( int j = 0; j < c; j++ )
        {
            if( str[i][j] == '.' )
            {
                printf(".");
            }
            else
            {
                ans = 0;
                set<int>s1;
                for( int x = 0; x < 4; x++ )
                {
                    xx = i + dx[x];
                    yy = j + dy[x];
                    if( xx >= 0 && xx < r && yy >= 0 && yy < c && str[xx][yy] != '*' )
                    {
                        p1 = find_par(xx,yy);
                        if( s1.count(p1)==0 ){
                            ans += num[p1/c][p1-(p1/c)*c];
                            s1.insert(p1);

                        }
                    }
                }
                ans++;
                printf("%d", ans%10);
            }

        }
        printf("\n");
    }
    return 0;
}
