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


intl solve( int cur, int tot1, int tot2 )
{
    //cout << cur << " " << tot1 << endl;

    if( cur == -1 && (tot1 != 0 || tot2 != 0) )
    {
        return 0;
    }
    if( cur == -1 && tot1 == 0 && tot2 == 0 )
    {
        return 1;
    }
    if( tot1 < 0 )
        return 0;
    if( cur < 0 )
        return 0;

    if( dp[cur][tot1] != -1 )
        return dp[cur][tot1];



    //cout << cur << " : " << tot << endl;
    dp[cur][tot1] = 0;
    int x = vec[cur];

    if( x <= tot2 )
    {
        intl d = fact[tot2];
        d = (d*inv[x])%mod;
        d = (d*inv[tot2-x])%mod;
        dp[cur][tot1] += solve( cur-1, tot1, tot2 - x )*d;
        dp[cur][tot1] %= mod;
    }

    if( tot1 >= x )
    {
        intl d = fact[tot1];
        d = (d*inv[x])%mod;
        d = (d*inv[tot1-x])%mod;
        dp[cur][tot1] += solve( cur-1, tot1 - x, tot2 )*d;
        dp[cur][tot1] %= mod;
    }
        //dp[cur][tot] += solve( cur-1, tot - vec[cur] )*(((((fact[tot]*inv[ vec[cur] ])%mod)*inv[ tot - vec[cur] ])%mod )%mod );
    dp[cur][tot1] %= mod;
    //cout << "cur " << cur << " tot1 " << tot1 << " " << dp[cur][tot1] << endl;
    return dp[cur][tot1];
}

int main()
{
    //freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);

    fact[0] = 1;
    inv[0] = 1;
    for( int i = 1; i < MAXN; i++ )
    {
        fact[i] = (fact[i-1]*i)%mod;
        inv[i] = exponentiation( fact[i], mod-2, mod );
    }

    string s;
    cin >> s;
    int q;
    cin >> q;
    for( int i = 0; i < s.length(); i++ )
    {
        cnt[ s[i] ]++;
    }
    int h = s.length()/2;
    memset( sol, -1, sizeof sol );
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        int c1 = s[x-1], c2 = s[y-1];
        if( sol[c1][c2] != -1 )
        {
            cout << sol[c1][c2] << endl;
            continue;
        }
        intl ans;
        if( c1 == c2 )
        {
            int n = cnt[c1];
            if( n  > h )
            {
                ans = 0;
            }
            else
            {
                vec.clear();
                for( char c = 'a'; c <= 'z'; c++ )
                {
                    if( c == c1 ) continue;
                    if( cnt[c] > 0 )
                        vec.push_back(cnt[c]);
                }
                for( char c = 'A'; c <= 'Z'; c++ )
                {
                    if( c == c1 ) continue;
                    if( cnt[c] > 0 )
                        vec.push_back(cnt[c]);
                }
                memset( dp, -1, sizeof dp );
                //cout << vec.size() << " " << h-n << endl;

                ans = solve( vec.size()-1, h - n, h );
                ans = (ans*fact[h])%mod;
                ans = (ans*inv[n])%mod;
                ans = (ans*inv[h-n])%mod;
            }
        }
        else
        {
            int n1 = cnt[c1], n2 = cnt[c2];
            if( n1+n2 > h )
            {
                ans = 0;
            }
            else
            {
                vec.clear();
                for( char c = 'a'; c <= 'z'; c++ )
                {
                    if( c == c1 || c == c2 ) continue;
                    if( cnt[c] > 0 )
                        vec.push_back(cnt[c]);
                }
                for( char c = 'A'; c <= 'Z'; c++ )
                {
                    if( c == c1 || c == c2 ) continue;
                    if( cnt[c] > 0 )
                        vec.push_back(cnt[c]);
                }
                memset( dp, -1, sizeof dp );

                //cout << vec.size() << endl;

                ans = solve( vec.size()-1, h-n1-n2, h );
                //cout << vec.size() << " " << h << endl;

                //cout <<  " -- > " << ans << "  " << d << endl;
                ans = (ans*fact[h])%mod;
                ans = (ans*inv[n1])%mod;
                ans = (ans*inv[n2])%mod;
                ans = (ans*inv[h-n1-n2])%mod;
            }
        }
        ans = (ans*2)%mod;
        sol[c1][c2] = ans;
        cout << sol[c1][c2] << endl;
    }

    return 0;
}
