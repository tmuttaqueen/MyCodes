#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;
const intl mod = 1e9+7;
intl inv;

long long binary_expo( long long a, long long b, long long mod )
{
    long long ans = 1;
    while( b > 0 )
    {
        if( b&1 )
            ans = (a*ans)%mod;
        a = (a*a)%mod;
        b /= 2;
    }
    return ans;
}

intl oddsum( intl x )
{
    return ((x%mod)*(x%mod))%mod;
}

intl evensum( intl x )
{
    return ((x%mod)*((x+1)%mod))%mod;
}

intl evensum(intl r, intl l)
{
    return evensum(r) - evensum(l);
}

intl oddsum( intl r, intl l)
{
    return oddsum(r) - oddsum(l);
}

intl sum( intl n )
{
    if( n <= 0 ) return 0;
    intl even = 0, odd = 0, s = 0;
    for( int i = 0; i <= 60; i++ )
    {
        intl nxt = 1LL<<i;
        //cout << n << " " << nxt << " " << s << endl;
        if( nxt <= n )
        {
            n -= nxt;
            if( i&1 )
            {
                s += evensum(even+nxt, even);
                s %= mod;
                even += nxt;
            }
            else
            {
                s += oddsum(odd+nxt, odd);
                s %= mod;
                odd += nxt;
            }
        }
        else
        {
            intl nxt = n;
            n = 0;
            if( i&1 )
            {
                s += evensum(even+nxt, even);
                s %= mod;
                even += nxt;
            }
            else
            {
                s += oddsum(odd+nxt, odd);
                s %= mod;
                odd += nxt;
            }
        }

        if( n == 0 ) break;

    }
    //cout << s << endl;
    return s;

}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    inv = binary_expo(2, mod-2, mod);
    intl l, r;
    cin >> l >> r;
    intl x = sum(r), y = sum(l-1);

    intl ans = x - y;
    //cout << x << " " << y << endl;
    ans = (ans%mod + mod)%mod;
    cout << ans << endl;
    return 0;
}
