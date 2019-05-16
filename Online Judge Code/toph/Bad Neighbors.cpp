#include<bits/stdc++.h>

using namespace std;

#define intl long long

intl fact[1002], inv[1002], po[1002];

intl mod = 1e9+7;

long long expo( long long a, long long b, long long mod )
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

int ara[1002], s[1002];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    fact[0] = po[0] = 1;
    inv[0] = 1;
    for( int i = 1; i <= 1000; i++ )
    {
        po[i] = (2*po[i-1])%mod;
        fact[i] = (i*fact[i-1])%mod;
        inv[i] = expo( fact[i], mod-2, mod );
    }

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        for( int i = 0; i < m; i++ )
        {
            cin >> ara[i];
        }
        intl ans = fact[n-m];

        for( int i = 0; i < m; i++ )
        {

            cin >> s[i];

            if( i == 0 )
            {
                ans = (ans*inv[ara[i]-1])%mod;
            }
            else
            {
                ans = (ans*inv[ ara[i] - ara[i-1] - 1 ] )%mod;
            }
            if( i > 0 && s[i-1] == 0 && s[i] == 0 && ( ara[i] - ara[i-1] ) > 1 )
            {
                ans = (ans*po[ ara[i]-ara[i-1] - 2] )%mod;
            }

        }
        ans = (ans*inv[n- ara[m-1]])%mod;
        cout << ans << endl;
    }

    return 0;
}
