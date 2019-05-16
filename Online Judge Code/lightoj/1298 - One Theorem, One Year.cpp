#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes\n")
#define val_of(x)   cout << #x << " is " << x << "   "
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>
#define piii        pair<pii, int>
#define double      long double

const int mx = 5000;
int mod = 1000000007;

bool flag[mx];
vector<intl>prime;
intl dp[505][505];

void sieve()
{
    prime.pb(2);
    for( int i = 3; i < mx; i+=2 )
    {
        if( prime.size() > 500 )
            break;
        if( flag[i] == 0 )
        {
            //what_is(i);
            prime.pb(i);
            for( int j = i + i; j < mx; j += i )
                flag[j] = 1;
        }
    }

}

void calculate()
{
    dp[1][1] = 1;
    for( int i = 1; i <= 500; i++ )
    {
        for( int j = i; j <= 500; j++ )
        {
            dp[i][j] += (dp[i-1][j-1]*( prime[i-1] - 1) + dp[i][j-1]*prime[i-1])%mod;
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    sieve();
    calculate();

    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int k, p;
        scanf("%d %d", &k, &p);
        printf("Case %d: %lld\n", caseno++, dp[p][k] );
    }

    return 0;
}




