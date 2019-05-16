#include <bits/stdc++.h>

using namespace std;


const int mx = 1005, my = 1005;
int tree[mx][my];

int query( int x, int y )
{
    int sum = 0, temp = y;
    while( x > 0 )
    {
        y = temp;
        while(y>0)
        {
            sum += tree[x][y];
            y -= (y&-y);
        }
        x -= (x&-x);
    }
    return sum;
}

void update( int x,int y, int val )
{
    int temp = y;
    while( x < mx )
    {
        y = temp;
        while( y < my )
        {
            tree[x][y] += val;
            y += (y&-y);
        }
        x += x&-x;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        memset(tree, 0, sizeof(tree));
        int q;
        scanf("%d", &q);
        printf("Case %d:\n", caseno++);
        while(q--)
        {
            int a;
            scanf("%d", &a);
            if(!a)
            {
                int p, q;
                scanf("%d %d", &p, &q);
                p++;
                q++;
                int s = query(p, q) + query(p-1, q-1) - query( p-1, q ) - query( p, q-1 );
                if( !s )
                    update(p, q, 1);
            }
            else
            {
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                x2++;
                x1++;
                y1++;
                y2++;
                int ans = query(x2, y2) + query(x1-1, y1-1) - query( x1-1, y2 ) - query( x2, y1-1 );
                printf("%d\n", ans);
            }
        }
    }


    return 0;
}
