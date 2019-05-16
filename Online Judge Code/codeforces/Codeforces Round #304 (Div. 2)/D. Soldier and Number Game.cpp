#include <bits/stdc++.h>

using namespace std;

const double pi = 3.141592653589793;

#define xx          first
#define yy          second
#define mp          make_pair
#define intl        long long
#define filein      freopen("input.txt", "r", stdin)
#define fileout     freopen("output.txt", "w", stdout)
#define debug       printf("yes \n")
#define what_is(x)  cout << #x << " is " << x << endl
#define pb          push_back
#define eb          emplace_back
#define pii         pair<int, int>

const int mx = 5000000;
vector<int>prime(mx+5, 0);
vector<int>ans(mx+5, 0);

void solve()
{
    int lim = sqrt(mx) + 1;
    vector<bool>isprime(mx+5, 0);
    for( int i = 2; i <= lim; i++ )
    {
        if( isprime[i] == 0 )
        {
            prime[i] = i;
            for( int j = i*2; j <= mx; j+= i )
            {
                isprime[j] = 1;
                if( prime[j] == 0 )
                    prime[j] = i;
            }
        }
    }
    for( int i = 3; i <= mx; i+=2  )
        if( isprime[i] == 0 )
            prime[i] = i;
    ans[0] = ans[1] = 0;
    for( int i = 2; i <= mx; i++ )
    {
        ans[i] = 1 + ans[ i/prime[i] ];
    }
    for( int i = 1; i <= mx; i++ )
    {
        ans[i] += ans[i-1];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    solve();
    int t;
    scanf("%d", &t);
    while(t--)
    {
        intl a, b, sol = 0;
        scanf("%I64d %I64d", &a, &b);
        sol = ans[a] - ans[b];
        printf("%I64d\n", sol);
    }

    return 0;
}



