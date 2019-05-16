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
    int t;
    intl ara[100], s = 1;
    for( int i = 0; i <= 32; i++ )
    {
        ara[i] = s;
        s*=2;
    }
    cin >> t;
    while(t--)
    {
        intl n, ans;
        cin >> n;
        ans = n*(n+1)/2;
        for( int i = 0; ara[i] <= n; i++ )
        {
            ans -= ara[i]*2;
        }
        cout << ans << endl;
    }

    return 0;
}
