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

intl mod = 1000000007;

int main()
{
    ios::sync_with_stdio(false);
    //filein;
    intl n, k, d;
    cin >> n >> k >> d;
    intl ara1[1000], ara2[1000], ans1[1000], ans2[1000];

    for( intl i = 0; i < (d-1); i++ ) ara1[i] = i+1;
    for( intl i = 0; i < k; i++ ) ara2[i] = i+1;

    ans1[0] = ans2[0] = 1;

    for( int i = 1; i <= n; i++ )
    {
        intl sum = 0;
        for( int j = 0; j < (d-1); j++ )
        {
            if( (i-ara1[j]) >= 0 )
            {
                sum += ans1[i-ara1[j]];
                sum %= mod;
            }
        }
        sum %= mod;
        ans1[i] = sum;
    }

    for( int i = 1; i <= n; i++ )
    {
        intl sum = 0;
        for( int j = 0; j < k; j++ )
        {
            if( (i-ara2[j]) >= 0 )
            {
                sum += ans2[i-ara2[j]];
                sum %= mod;
            }
        }
        sum %= mod;
        ans2[i] = sum;
    }

    cout << (ans2[n]-ans1[n] + mod)%mod << endl;
    return 0;
}



