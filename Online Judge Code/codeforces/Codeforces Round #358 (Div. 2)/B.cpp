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


int main()
{
    ios::sync_with_stdio(false);
    filein;
    intl n;
    cin >> n;
    intl ara[n+1];
    ara[0] = 0;
    for( int i = 1; i <= n; i++ )
        cin >> ara[i];
    sort( ara, ara+n+1 );
    int i;
    /*for( i = n-1; i >= 0; i-- )
    {
        if( ara[i-1] != ara[i] )
            break;
    }
    int x = n-i;
    int y = ara[i] - ara[i-1];*/
    intl ans = ara[n] - 1, flag  = 1;
    if( ans > n )
    {
        cout << ans << endl;
        return 0;
    }
    intl dp[n];
    ara[n]--;
    for( int i = n-1; i > 0; i-- )
    {

        if( ara[i+1] - 1 <= ara[i]  )
            ara[i] = ara[i+1]-1;
        else
        {
            flag = 0;
        }

    }
    if( flag )
    {
        ans = max( ans, ara[n]+1 );
    }

    cout << ans << endl;

    return 0;
}


