#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.txt", "r", stdin);
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2 ;
    int x = x2 - x1;
    int y = y2 - y1;
    if( x < 0 )
        x = -x;
    if( y < 0 )
        y = -y;
    int ans = x + y - min(x,y);
    cout << ans << endl;
    return 0;
}
