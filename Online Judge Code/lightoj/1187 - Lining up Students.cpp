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


int main()
{
    ios::sync_with_stdio(false);
    //filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, ans = 1;
        cin >> n;
        int ara[n+1];
        for( int i = 1; i <= n; i++ ) cin >> ara[i];
        for( int i = 2; i <= n; i++ )
        {
            if( i - ara[i] <= ans ) ans++;
        }
        cout << "Case " << caseno++ << ": " << ans << "\n";
    }

    return 0;
}


