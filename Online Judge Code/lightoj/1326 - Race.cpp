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

const intl mod = 10056;

intl ans[1001];
intl ara[1001][1001];

void precal()
{
    int n = 1000;
    ara[0][0] = 1;
    for( int i = 1; i <= n; i++ )
    {
        for( int j = i; j<=n; j++ )
        {
            ara[i][j] = ((( ara[i-1][j-1] + ara[i][j-1] )%mod)*i)%mod;
        }
    }
    for( int i = 1; i <= n; i++ )
    {
        intl sum = 0;
        for( int j = 0; j <= i; j++ )
        {
            sum += ara[j][i];
        }
        ans[i] = sum%mod;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    precal();
    //cout << ans[1] << " " << ans[2] << " " << ans[3] << " " << ans[4] << endl;
    //filein;
    int t, caseno = 1;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        printf("Case %d: %d\n", caseno++, ans[n]);
    }


    return 0;
}


