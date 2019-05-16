#include<bits/stdc++.h>

using namespace std;

#define intl long long

intl mod = 1e9+7, n, k, m;
intl dp[111][11][11][31][2][2]; ///cur, internal cc, taken, mod, ls, rs
intl ara[111];

intl solve( int cur, int seg, int taken, int total, int ls, int rs )
{
    if( taken > k )
        return 0;
    if( seg < 0 )
        return 0;
    if( cur == n && seg > 0 )
        return 0;


    int add = (seg*2+ls+rs)*ara[cur];
    int nxt = total;
    if( taken < k ) nxt = ((nxt-add)%m + m)%m;

    if( cur == n )
    {
        if( seg != 0 || taken < k-1 || (ls+rs == 0) ) return 0;
        if( ls + rs == 2 )
        {
            return nxt == 0;
        }
        if( ls + rs == 1 )
        {
            if( taken == k ) return 0;
            return nxt == 0;
        }
    }

    intl &val = dp[cur][seg][taken][total][ls][rs];
    if( val != -1 )
        return val;
    val = 0;
    val += solve(cur+1, seg, taken, nxt, ls, rs);

    val += solve(cur+1, seg, taken+1, nxt, 1, rs);
    val += solve(cur+1, seg-1, taken+1, nxt, 1, rs)*seg;
    if( !(seg == 0 && taken == k-1 && ls+rs == 2) )
    {
        val += solve(cur+1, seg, taken+1, nxt, ls, 1);
        val += solve( cur+1, seg-1, taken+1, nxt, ls, 1 );
    }


    val += solve(cur+1, seg+1, taken+1, nxt, ls, rs);
    val += solve( cur+1, seg, taken+1, nxt, ls, rs )*2*seg;
    val += solve( cur+1, seg-1, taken+1, nxt, ls, rs )*seg*(seg-1);
    val %= mod;
    if( cur == 3 && val )
    cout << cur << " " << seg << " " << taken << " " << total << " " << ls << " " << rs << " val " << val << endl;
    return val;

}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset( dp, -1, sizeof dp );
    cin >> n >> m >> k;
    for( int i = 2; i <= n; i++ )
        cin >> ara[i];
    cout << solve(1, 0, 0, 0, 0, 0) << endl;
    return 0;
}
