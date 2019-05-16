#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 300005;

intl mod = 998244353;

intl ara[MAXN];
intl ans = 1;
intl dp[MAXN];
intl option[MAXN];


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


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    intl n, k;
    cin >> n >> k;
    for( int i = 1; i <= n; i++ )
    {
        cin >> ara[i];
    }

    for( int i = 3; i <= n; i++ )
    {
        if(  ara[i-2] == ara[i] && ara[i-2] != -1)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    dp[0] = 1;
    for( int i = 1; i <= n; i++ )
    {
        if( ara[i] == -1 )
        {
            int koma = 0;
            if( i-2 < 1 )
            {
                if( i+2 <= n && ara[i+2] != -1 )
                {
                    dp[i] = dp[i-1]*(k-1);
                    option[i] = k-1;
                }
                else
                {
                    dp[i] = dp[i-1]*k;
                    option[i] = k;
                }

            }
            else if( i+2 > n )
            {
                if( i-2 >= 1 )
                {
                    dp[i] = dp[i-1]*(k-1);
                    option[i] = k-1;
                }
                else
                {
                    dp[i] = dp[i-1]*k;
                    option[i] = k;
                }
            }
            else
            {
                if( ara[i+2] == -1  )
                {
                    dp[i] = dp[i-1]*(k-1);
                    option[i] = k-1;
                }
                else if( ara[i-2] != -1 && ara[i+2] != -1 )
                {
                    if( ara[i-2] == ara[i+2] )
                    {
                        dp[i] = dp[i-1]*(k-1);
                        option[i] = k-1;
                    }
                    else
                    {
                        dp[i] = dp[i-1]*(k-2);
                        option[i] = k-2;
                    }

                }
                else if( ara[i-2] == -1 && ara[i+2] != -1 )
                {
                    option[i] = k-2;
                    dp[i] = dp[i-1]*(k-2);
                    dp[i] += (binary_expo( option[i-2], mod-2, mod )*dp[i-1])%mod;
                }
            }
            dp[i] %= mod;
        }
        else
        {
            dp[i] = dp[i-1];
            option[i] = 1;
        }
    }

    for( int i = 1; i <= n; i++ )
    {
        cout << i << ": " << option[i] << " " << dp[i] << endl;
    }
    cout << dp[n] << endl;

    return 0;
}

/*
10 11
-1 11 -1 -1 -1 -1 10 -1 -1 -1
*/

