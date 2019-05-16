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
#define piii        pair<pii, int>

bool ara[100005];
intl pr[10000], s = 0;


void sieve()
{
    int n = 100005;
    int lim = sqrt(n)+5;
    memset( ara, 0, sizeof(ara) );
    for( int i = 2; i <= lim; i++ )
    {
        if( ara[i] == 0 )
            for( int j = i*i; j <= n; j+=i )
            {
                ara[j] = 1;
            }
    }
    pr[s++] = 2;
    for( int i = 3; i <= n; i+=2 )
        if( ara[i] == 0 )
            pr[s++] = i;
}

int seg_sieve( int a, int b )
{
    intl n = b-a+1, ans = 0;
    memset( ara, 0, sizeof(ara) );
    for( intl i = 0; i < s && pr[i]*pr[i] <= b; i++ )
    {
        intl k = (a-1)/pr[i];
        for( intl j = (k+1)*pr[i]; j <= b; j+=pr[i] )
        {
            if( j == pr[i] )
                continue;
            ara[j-a] = 1;
        }
    }
    if( a == 1 )
        ara[0] = 1;
    for( int i = 0; i < n; i++ )
        if( ara[i] == 0) ans++;

    return ans;
}

int main()
{
    //ios::sync_with_stdio(false);
    //filein;
    sieve();
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        int ans = seg_sieve(a,b);

        printf("Case %d: %d\n", caseno++, ans);
    }

    return 0;
}



