#include<bits/stdc++.h>

using namespace std;

int ara[10005], diff[10005];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        for( int i = 0; i < n; i++ )
            cin >> ara[i];
        sort( ara, ara+n );
        for( int i = 1; i < n; i++)
        {
            diff[i-1] = ara[i] - ara[i-1];
        }
        sort( diff, diff+n-1 );
        reverse( diff, diff+n-1 );
        int ans = ara[n-1] - ara[0];
        for( int i = 1; i < k; i++ )
        {
            ans -= diff[i-1];
        }
        cout << ans << endl;
    }
}
