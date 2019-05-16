#include <bits/stdc++.h>

using namespace std;

int ara[1005], k, n;

bool ispos( int d )
{
    int i, x, y = 0;
    //cout << d << endl;
    for( i = 0; i < n; i++ )
    {
        x = ara[i];
        while( i < n && x <= d )
        {
            x += ara[i+1];
            if( x <= d )
                i++;
        }
        y++;
    }
    if( y <= k )
        return true;
    else
        return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t, cn = 1, ans;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &n, &k);
        n++;
        k++;
        int l = 0, h = 100000000;
        for( int i = 0; i < n; i++ )
        {
            scanf("%d", &ara[i]);
            l = max(l, ara[i]);
        }
        ans = l;
        while( l <= h )
        {
            int mid = (l+h)/2;
            bool a = ispos( mid );
            if( a )
            {
                ans = mid;
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

    //cout << "ans " << ans << endl;
    printf("Case %d: %d\n", cn++, ans);
    int m = n - k, x = 0, i, p;
    for( i = 0; i < n; i++ )
    {
        p = ara[i];
        while( i < n && p <= ans )
        {
            if( x < m && p+ara[i+1] <= ans )
            {
                p += ara[i+1];
                i++;
                x++;
            }
            else
                break;
        }
        printf("%d\n", p);
    }
    }
    return 0;
}
