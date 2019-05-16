#include<bits/stdc++.h>

using namespace std;

#define intl unsigned long long

intl ara[20], tot;
intl x, n, ans;
bool flag[1<<18];

inline intl gcd( intl a, intl b )
{
    intl t;
    while(b>0)
    {
        intl t = a%b;
        a = b;
        b = t;
    }
    return a;
}

void solve( int mask, intl lcm = 1, int cur = 0, int bit = 0 )
{
    if( mask > tot ) return;
    if( flag[mask] == 0 )
    {
        intl temp = x/lcm;
        if( bit&1 )
        {
            ans += bit*temp;
        }
        else
        {
            ans -= bit*temp;
        }
        flag[mask] = 1;
    }
    if( cur >= n ) return;
    intl g = gcd(lcm, ara[cur]);
    intl d = ara[cur]/g;
    if( (x/lcm)/d )
    {
        solve( mask|(1<<cur), lcm*d, cur+1, bit+1 );
    }
    solve( mask, lcm, cur+1, bit );

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        memset( flag, 0, sizeof flag );
        cin >> x >> n;
        for( int i = 0; i < n; i++ )
        {
            cin >> ara[i];
        }
        ans = 0;
        tot = 1<<n;
        tot--;
        solve(0);
        cout << ans << endl;
    }
    return 0;
}
