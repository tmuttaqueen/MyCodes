#include <bits/stdc++.h>

using namespace std;

long long dis( int a, int b, int x, int y )
{
    return (long long)((long long)(a-x)*(a-x) + (long long)(b-y)*(b-y));

}

int main()
{
    freopen("input.txt", "r", stdin);
    int n, x, y, a, b;
    cin >> n >> x >> y;
    long long mm = 0, m = 1000000000000000009;
    for( int i =0 ;i < n; i++ )
    {
        scanf("%d %d", &a, &b);
        long long d = dis( a, b , x, y );
        //cout << d << endl;
        if( d > mm )
            mm = d;
        if( d < m )
            m = d;
    }
    double ans = acos(0)*2*(mm-m);
   //cout << ans << endl;
    printf("%.8f\n", ans);

    return 0;
}
