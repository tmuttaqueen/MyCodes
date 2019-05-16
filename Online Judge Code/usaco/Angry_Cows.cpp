#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("angry.in", "r", stdin);
    //freopen("angry.out", "w", stdout);
    int n;
    scanf("%d", &n);
    int ara[n];
    for( int i = 0; i < n; i++ )
    {
        scanf("%d", &ara[i]);
    }
    sort( ara, ara+n );
    int ans = 0;
    for( int i = 0; i < n; i++ )
    {
        int temp = 0, t = 1, head = i, tail = i, x = 1, tt = 0;
        bool f1 = 1, f2 =1;
        while( temp < x && (head > 0 || tail < n-1) ) //&& ( head >= 0 || tail <= (n-1) ) )
        {
            temp = x;
            tt = x;
            int val = ara[head-1], lim = ara[head] - t;
            if( head > 0 && val >= lim && f1 == 1 )
            {
                x++;
                head--;
                //cout << "h " << head << " ";
            }
            if( x == tt )
                f1 = 0;
            //cout << endl;
            val = ara[tail+1];
            lim = ara[tail] + t;
            tt = x;
            if( tail < n-1 && lim >= val && f2 == 1 )
            {
                x++;
                tail++;
                //cout << "t " << tail << " ";
            }
            if( x == tt )
                f2 = 0;
            //cout << endl;
            t++;
        }

        cout << "x ---------  " << x << endl;
        ans = max(ans, x);
    }
    printf("%d\n", ans);
    return 0;
}
