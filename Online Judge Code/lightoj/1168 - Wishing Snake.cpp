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
    filein;
    int t, caseno = 1;
    cin >> t;
    while(t--)
    {
        int n, k, a, b;
        int ara[1001];
        memset( ara, 0, sizeof(ara) ); // outgoing -  ....  incoming +
        cin >> n;
        while(n--)
        {
            cin >> k;
            while(k--)
            {
                cin >> a >> b;
                ara[a]--;
                ara[b]++;
            }
        }
        int ans = 0;
        for( int i = 0; i <= 1000; i++ )
        {
            if( ara[i] )
                ans++;
        }
        if( ans > 2 )
        {
            cout << "Case " << caseno++ << ": " << "NO\n";
        }
        else
            cout << "Case " << caseno++ << ": " << "YES\n";
    }

    return 0;
}



