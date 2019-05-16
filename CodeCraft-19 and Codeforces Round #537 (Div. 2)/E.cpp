#include<bits/stdc++.h>

using namespace std;

#define intl long long
#define pii pair<int,int>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back

const int MAXN = 100005;

long long exponentiation( long long a, long long b, long long mod )
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

intl mod = 1e9+7;

intl fact[MAXN], inv[MAXN];

int cnt[200];

intl sol[200][200];
vector<int>vec;
intl dp[52][50005];


intl solve( int cur, int tot )
{
    //cout << cur << " " << tot << endl;

    if( cur == -1 && tot != 0  )
    {
        return 0;
    }
    if( cur == -1 && tot == 0 )
    {
        return 1;
    }
    if( tot == 0 )
        return 1;
    if( dp[cur][tot] != -1 )
        return dp[cur][tot];
    //cout << cur << " : " << tot << endl;
    dp[cur][tot] = solve( cur-1, tot );
    if( tot - vec[cur] >= 0 )
        dp[cur][tot] += solve( cur-1, tot - vec[cur] )*(((((fact[tot]*inv[ vec[cur] ])%mod)*inv[ tot - vec[cur] ])%mod )%mod );
    dp[cur][tot] %= mod;
    return dp[cur][tot];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    for( int i = 0; i < 50; i++ )
    {
        for( int j = 0; j < 50; j++ )
        {
                memset( dp, -1, sizeof dp ) ;
        }
    }

    return 0;
}
