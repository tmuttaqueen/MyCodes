#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int r, c, cost = 0;
    scanf("%d %d", &r, &c);
    for( int i = 0; i < r; i++ )
    {
        int x = 1000000005, y;
        for( int j = 0; j < c; j++ )
        {
            scanf("%d", &y);
            x = min(x,y);
        }
        cost= max(x, cost);
    }
    cout << cost << endl;
    return 0;
}
